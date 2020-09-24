#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include <iostream>
template <typename T>
struct ListNode {
	T data;
	ListNode<T>* next;
	ListNode<T>(const T &x = T()) : data(x), next(nullptr) { }
};

template <typename T>
class List {
private:
	size_t size;
	ListNode<T>* head, * last;
public:
	List<T>();
	~List<T>();
	void push(const T& x);
	bool find(const T& x);
};

template <typename T>
List<T>::List() {
	head = new ListNode<T>();
	last = head;
    size = 0;
}

template <typename T>
List<T>::~List() {
	while (head) {
		ListNode<T>* p = head->next;
		delete head;
		head = p;
	}
}

template <typename T>
void List<T>::push(const T& x) {
	this->last->next = new ListNode<T>(x);
	this->last = this->last->next;
	size++;
}

template <typename T>
bool List<T>::find(const T& x) {
	ListNode<T>* temp = head->next;
	while (temp) {
		if (!(x < temp->data) && !(temp->data < x)) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}


#endif // !_LINK_LIST_H_
