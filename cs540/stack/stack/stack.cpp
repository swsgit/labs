// Spencer Stone
// CS540
// 3/4/19
#include <iostream>

using namespace std;

typedef struct Stack {
  int item;
  Stack *next;
} Stack;

void Push(Stack **s, int item) {
  Stack *currentStack = *s;
  Stack *newStack = new Stack;
  newStack->item = item;
  newStack->next = NULL;

  if (currentStack == NULL) {
    *s = newStack;
    return;
  }

  while (currentStack != NULL) {
    if (currentStack->next == NULL) {
      currentStack->next = newStack;
      break;
    }
    currentStack = currentStack->next;
  }
}

int Pop(Stack **s) {
  int ret = NULL;
  Stack *currentStack = *s;
  Stack *prevStack = NULL;

  while (currentStack != NULL) {
    if (currentStack->next == NULL) {
      ret = currentStack->item;
      delete[] currentStack;
      if (prevStack != NULL) {
        prevStack->next = NULL;
      } else {
        *s = NULL;
      }
      return ret;
    }
    prevStack = currentStack;
    currentStack = currentStack->next;
  }

  return ret;
}

void PrintStack(Stack *s) {
  while (s != NULL) {
    cout << s->item << endl;
    if (s->next == NULL) {
      break;
    }
    s = s->next;
  }
}

void DeleteStack(Stack **s) {
  Stack *currentStack = *s;
  Stack *nextStack;
  while (currentStack != NULL) {
    nextStack = currentStack->next;
    delete[] currentStack;
    currentStack = nextStack;
  }
  *s = NULL;
}

int main() {
  Stack *head = NULL;

  Push(&head, 10);
  Push(&head, 20);
  Push(&head, 30);

  cout << "Printing stack...\n";
  PrintStack(head);

  cout << "Popping stack: " << Pop(&head) << endl;
  cout << "Popping stack: " << Pop(&head) << endl;
  cout << "Popping stack: " << Pop(&head) << endl;

  Push(&head, 40);
  Push(&head, 50);
  Push(&head, 60);

  cout << "Printing stack...\n";
  PrintStack(head);

  cout << "Deleting stack...\n";
  DeleteStack(&head);

  cout << "Printing stack...\n";
  PrintStack(head);

  return 0;
}
/*
Printing stack...
10
20
30
Popping stack: 30
Popping stack: 20
Popping stack: 10
Printing stack...
40
50
60
Deleting stack...
Printing stack...
*/