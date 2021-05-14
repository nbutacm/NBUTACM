# C++ 内存管理

- 内存分配的每一层面

![img](https://img-blog.csdnimg.cn/20200411175727113.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzI3MjYyNzI3,size_16,color_FFFFFF,t_70)

## C++ memory primitives

- `new Object();` 等价于

  ```cpp
  void * mem = operator new(sizeof(Object)); // malloc
  Object* p = static_cast<Object*>(mem);
  p->Object::Object(); // 只有编译器可以这样使用 application 可以使用 placement new
  // new(p) Object();
  ```

- `delete p`

  ```cpp
  p->~Object();
  operator delete p; // free(p);
  ```

## delete 和 delete[]的区别

  - delete 只调用一个析构

## placement new

- 允许我们将Object建立再allocated memory的内存空间上
- 没有所谓的placement delete，因为placement new根本没有分配空间

## operator new / operator new[]

![](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/WwIcQHkD5mcpGpZWC00BdwOPWk1hdJFtBArZy8fkQuhZUO2Kib1CuvvgmcCYSfQvibVHnkG1Pmxr54SExueuwTJQ/640?wx_fmt=png)

如果是正常情况下，调用new之后走的是第二条路线，如果在类中重载了operator new()，那么走的是第一条路线，但最后还是要调用到系统的::operator new()函数。

对于GNU C，背后使用的allocate()函数最后也是调用了系统的::operator new()函数。

```c++
class Point {
private:
    int x, y;
public:
    Point(const int &x = 0, const int &y = 0) : x(x), y(y) {
        std::cout << "构造函数" << std::endl;
        std::cout << "x = " << x << " ,y = " << y << std::endl;
    }

    void *operator new(size_t sz) {
        Point *p = static_cast<Point *>(malloc(sizeof(Point)));
        std::cout << "内存分配" << std::endl;

        return p;
    }
    void operator delete(void *p) {
        free(p);
        std::cout<< "内存释放" << std::endl;
    }

    ~Point() {
        std::cout << "析构函数" << std::endl;
    }
};

int main(void) {
    Point *p1 = new Point();
    delete p1;
    Point *p2 = new Point;
    delete p2;
    Point *p3 = new Point(1, 3);
    delete p3;

    return 0;
}
```

> 内存分配
> 构造函数
> x = 0 ,y = 0
> 析构函数
> 内存释放
> 内存分配
> 构造函数
> x = 0 ,y = 0
> 析构函数
> 内存释放
> 内存分配
> 构造函数
> x = 1 ,y = 3
> 析构函数
> 内存释放

## pre-class allocator 

对于malloc来说，大家都有一个误解，以为它很慢，其实它不慢，后面会讲到。无论如何，减少malloc的调用次数，总是很好的，所以设计class者，可以先挖一块，只使用一次malloc，使用者使用，就只需要调用一次malloc，这样就是一个小型的内存管理。

除了降低`malloc`次数之外，还需要降低`cookie`用量。前面提到一次malloc需要一组(两个)cookie，总共8字节。

### part 1

- 单链表，分配多个连续的空间
- 然后分配对象的时候，从链表头部拿出一块部分
- 回收的时候，用头插法到链表
- 次方法可以减少`cookis`

![640?wx_fmt=png](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/WwIcQHkD5mcpGpZWC00BdwOPWk1hdJFt78MP1RmsD7nEPWIayicy4bPxkIUfgfhX1FLXSMR6Bk9ibiaCQkbQFupTQ/640?wx_fmt=png)

### part 2

![](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/WwIcQHkD5mcpGpZWC00BdwOPWk1hdJFtTQciaPKgWw45lFB53UCP6WDIkGHVQibkl5kt0gL7D6v0ezWaN3zG7MuQ/640?wx_fmt=png)

![](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/WwIcQHkD5mcpGpZWC00BdwOPWk1hdJFtTITGyHVPn6v9xdFEoQPRFyXIFwTRlTyybc0DiapcUofggYu14picSlvA/640?wx_fmt=png)

- 使用了`union`用来表示空间代表的是实际数据还是指针

- 这里带来了一个观念：`嵌入式指针`，embedding pointer。

  嵌入式指针：rep占16字节，next占前8字节。  

- 最后operator delete的时候，实际的分配控件并没有被free掉，这种当然不好，技术难点非常高，后面谈！虽然没有还给操作系统，但不能说它内存泄露，因为这些都在它的"手上"。

    

### part 3

不要把内存分配与回收写在各个class中，而要把它们集中在一个allocator中！

以往的版本，把所有的分配，回收这类的，全部集中到了相应的类里，不利于复用的。所以可以把分配回收的方法都提取出来，分装成一个类。

![](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/WwIcQHkD5mcpGpZWC00BdwOPWk1hdJFtMdx2GSDomjFqPn8LB3B7RQjgTicrupibPeCEQg9fkDdMOibTrc0bZF4Bw/640?wx_fmt=png)

## G++ 4.9 allocator 和 pool allocator

- allocator只实现了`::operator new`和`::operator delete`
- allocator没有特殊的设计

### __gun_cxx::poll_alloc

- 定义在 `<ext/pool_allocator.h>`

- 有16个自由链表组成，从`8Bytes ~ 128Bytes`16种大小。超出128Bytes，则直接使用malloc和free

- 如果容器发出的不是8的倍数，则会调整成8的倍数

- 每个链表，20个，每次分配，会分配20*2

- 嵌入式指针的方法，维护链表，如：

  - ```cpp
    union obj{
        union obj * free_list_link;
        T data;
    };
    ```

  - 对象obj 的大小，需要大于指针大小。

  - ```cpp
        class __pool_alloc_base
        {
        protected:
    
          enum { _S_align = 8 };	// 增值大小
          enum { _S_max_bytes = 128 };		//最大二级内存长度
          enum { _S_free_list_size = (size_t)_S_max_bytes / (size_t)_S_align };    // 长度
          
          union _Obj
          {
    	union _Obj* _M_free_list_link;
    	char        _M_client_data[1];    // The client sees this.
          };
          
          static _Obj* volatile         _S_free_list[_S_free_list_size];		// 空闲链表内存池
            ...
        }
    ```

  - ```cpp
    // 追加量的计算
    // round_up(总量>>4) 调整到8的倍数，所有会原来越大
    _M_round_up(size_t __bytes) { return ((__bytes + (size_t)_S_align - 1) & ~((size_t)_S_align - 1)); }
    chunk_alloc() /*
    	先判断之前的空余pool，如果是碎片，则先处理锁片，然后再试图进行分配
    */
    ```

  - 关于碎片内存的处理，由于都是按照8的倍数，来申请内存，所有出现碎片，其碎片的大小也是8的倍数，可以把这个碎片分给最适合的一个自由链表中。

- 再次分配新的二级容量的时候，从前面已经多分配的pool终去切割，数量永远在$[1,20]$

- 当分配失败的时候，则从后面最近的空余的地方借一个过来。

- ![image-20210314195428648](https://i.loli.net/2021/03/14/TAfxpqstU7y8GJw.png)

### std::alloc 源码分析

- allocate 
  - 判断是否超过128， 超过使用第一级
  - 否则进入第二级分配，选择自由链表



## vector的扩容方案

根据不同的编译器实现来决定。

