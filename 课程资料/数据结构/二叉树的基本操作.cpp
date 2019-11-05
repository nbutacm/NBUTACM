

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct node {
  char  data;
  node *Right;
  node *Left;
};

node* CreateBTNode(string s) {
  stack<node *> Stack;
  int   k = 1, len = s.size();
  node *Tree;
  node *p1 = new node;

  p1->data  = s[0];
  p1->Left  = NULL;
  p1->Right = NULL;
  Tree      = p1;
  Stack.push(Tree);

  for (int i = 1; i < len; i++) {
    if (s[i] == '(') {
      k = 1;
    }
    else if (s[i] == ',') {
      if (((s[i - 1] >= 'A') && (s[i - 1] <= 'Z')) ||
          (s[i - 1] == ')')) Stack.pop();
      k = 2;
    }
    else if (s[i] == ')') {
      Stack.pop();
    }
    else {
      p1        = new node;
      p1->data  = s[i];
      p1->Left  = NULL;
      p1->Right = NULL;
      node *p = Stack.top();

      if (k == 1) {
        p->Left = p1;
      }
      else if (k == 2) {
        p->Right = p1;
      }
      Stack.push(p1);
    }
  }

  return Tree;
}

void DispBTNode(node *Tree) {
  if ((Tree->data >= 'A') && (Tree->data <= 'Z')) {
    cout << Tree->data;
  }

  if ((Tree->Left != NULL) || (Tree->Right != NULL)) {
    cout << '(';

    if (Tree->Left != NULL) {
      DispBTNode(Tree->Left);
    }

    if ((Tree->Left != NULL) && (Tree->Right == NULL)) {
      cout << ')';
    }

    if (Tree->Right != NULL) {
      cout << ',';
      DispBTNode(Tree->Right);
      cout << ')';
    }
  }
}

node* FindNode(node *Tree, char x) {
  stack<node *> s;

  s.push(Tree);

  while (!s.empty()) {
    node *p = s.top();
    s.pop();

    if (p->data == x) {
      return p;
    }
    else {
      if (p->Left != NULL) s.push(p->Left);

      if (p->Right != NULL) s.push(p->Right);
    }
  }
}

int BTNodeDepth(node *Tree) {
  if (Tree == NULL) return 0;

  if ((Tree->Left == NULL) && (Tree->Right == NULL)) return 1;

  return max(BTNodeDepth(Tree->Left), BTNodeDepth(Tree->Right)) + 1;
}

int NodesCount(node *Tree) {
  if (Tree == NULL) return 0;

  if ((Tree->Left == NULL) && (Tree->Right == NULL)) return 1;

  return NodesCount(Tree->Left) + NodesCount(Tree->Right) + 1;
}

void PreOrder(node *Tree) {
  if (Tree != NULL) {
    cout << Tree->data;
    PreOrder(Tree->Left);
    PreOrder(Tree->Right);
  }
}

void InOrder(node *Tree) {
  if (Tree != NULL) {
    InOrder(Tree->Left);
    cout << Tree->data;
    InOrder(Tree->Right);
  }
}

void PostOrder(node *Tree) {
  if (Tree != NULL) {
    PostOrder(Tree->Left);
    PostOrder(Tree->Right);
    cout << Tree->data;
  }
}

void LevelOrder(node *Tree) {
  queue<node *> q;

  q.push(Tree);

  while (!q.empty()) {
    node *p = q.front();
    q.pop();
    cout << p->data;

    if (p->Left != NULL) q.push(p->Left);

    if (p->Right != NULL) q.push(p->Right);
  }
}

int main() {
  // string in="A(B(C),E(F(,G)))";
  string in = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";

  cout << "����������" << endl;
  cout << in << endl;
  node *Tree = NULL;
  Tree = CreateBTNode(in);
  cout << endl;

  cout << "����������" << endl;
  DispBTNode(Tree);
  cout << endl << endl;

  cout << "���ҽڵ� E��������ָ��" << endl;
  node *F = NULL;
  F = FindNode(Tree, 'E');

  if (F == NULL) cout << "�Ҳ���E�ڵ�" << endl;
  else cout << "�����ҵ�E�ڵ�" << endl << endl;


  cout << "���������ĸ߶�:";
  int h = BTNodeDepth(Tree);
  cout << h << endl << endl;

  cout << "���������Ľ�������:";
  int num = NodesCount(Tree);
  cout << num << endl << endl;

  cout << "����������������:";
  PreOrder(Tree);
  cout << endl << endl;

  cout << "����������������:";
  InOrder(Tree);
  cout << endl << endl;

  cout << "�������ĺ�������:";
  PostOrder(Tree);
  cout << endl << endl;

  cout << "�������Ĳ��α���:";
  LevelOrder(Tree);
  cout << endl << endl;
}
