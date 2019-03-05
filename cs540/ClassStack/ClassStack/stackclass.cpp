// Spencer Stone
// CS540
// 3/4/19
#include <iostream>

using namespace std;

typedef struct Node {
  int item;
  Node *next;
} Node;

class Stack {
private:
  Node *head;

public:
  Stack() { head = NULL; }
  void Push(int item);
  int Pop();
  void Print();
  void Delete();
};

void Stack::Push(int item) {
  Node *top = head;
  Node *newNode = new Node;
  newNode->next = NULL;
  newNode->item = item;

  if (head == NULL) {
    head = newNode;
    return;
  }

  while (top != NULL) {
    if (top->next == NULL) {
      top->next = newNode;
      return;
    }
    top = top->next;
  }
}

int Stack::Pop() {
  int ret = NULL;
  Node *top = head;
  Node *prev = NULL;

  while (top != NULL) {
    if (top->next == NULL) {
      ret = top->item;
      delete[] top;
      if (prev != NULL) {
        prev->next = NULL;
      } else {
        head = NULL;
      }
      return ret;
    }
    prev = top;
    top = top->next;
  }

  return ret;
}

void Stack::Print() {
  Node *top = head;
  while (top != NULL) {
    cout << top->item << "\n";
    top = top->next;
  }
}

void Stack::Delete() {
  Node *top = head;
  Node *nextNode;
  while (top != NULL) {
    nextNode = top->next;
    delete[] top;
    top = nextNode;
  }
  head = NULL;
}

int main() {
  Stack stack;

  stack.Push(10);
  stack.Push(20);
  stack.Push(30);

  cout << "Printing stack...\n";
  stack.Print();

  cout << "Popping stack: " << stack.Pop() << "\n";
  cout << "Popping stack: " << stack.Pop() << "\n";

  stack.Push(40);
  stack.Push(50);
  stack.Push(60);

  cout << "Popping stack: " << stack.Pop() << "\n";
  cout << "Popping stack: " << stack.Pop() << "\n";

  cout << "Printing stack...\n";
  stack.Print();

  cout << "Deleting stack\n";
  stack.Delete();

  cout << "Printing stack...\n";
  stack.Print();

  return 0;
}
/*
Printing stack...
10
20
30
Popping stack: 30
Popping stack: 20
Popping stack: 60
Popping stack: 50
Printing stack...
10
40
Deleting stack
Printing stack...
*/