// Implement stack using linked list
// Pre-requisites: Basic knowledge of stack and operations in the linked list.

// Introduction
// Stack is a linear data structure in which elements are stored like a pile, i.e. one on top of another.

// The following diagram represents a simple stack

// Following operations can be performed in the stack:

// push(): pushes an element at the top of the stack.
// pop(): removes an element from the top of the stack.
// size(): returns the size of the stack.
// isEmpty(): returns a boolean value for whether the stack is empty or not.
// peek()/top(): returns the top element of the stack.
// Implementation of stack
// The stack can be implemented in two ways:

// Statically:  Using arrays
// Dynamically: Using a linked list
// In this article, we’ll focus more on the implementation of a stack using a linked list.

// Approach
// Let's focus on each and every operation of the stack and see how we can implement it using a linked list.

// We can assume our linked list to be a horizontal stack where the operations like deletion and insertion would take place at the top of the stack or at the head of the linked list.

// To perform all the operations our head of the linked list would act as the top of the stack.

// push(): pushing an element at the top of a stack

// Pushing the element at the top of the stack would mean the same as pushing an element at the end of the linked list.

// We can insert it at the beginning of the linked list using the following steps:

// Create a node for our new element.
// Point to the next pointer of our element node to point to the head of the linked list.
// Make the element node our top node.
// Increment the size variable.
// For a more detailed explanation of insertion at the beginning of a linked list, refer to this article.

// Let's see the function of this implementation

// void stackPush(int x) {
//     stackNode * element = new stackNode(x);
//     element -> next = top;
//     top = element;
//     cout << "Element pushed" << "\n";
//     size++;
//   }

//   pop(): removing an element from the top of a stack

// Removing an element from the top of the stack is the same as removing the element from the beginning of our linked list.

// The following steps are involved in the pop() method

// Check for underflow conditions in the stack.
// Store the top node in a temp node and top node data in another variable.
// Make the second node of our temp node a top.
// Delete temp node.
// Return the top node’s data.
// The following function explains the approach

// Code:

// C++
// Java

//  int stackPop() {
//     if (top == NULL) {
//       return -1;
//     }
//     int topData = top -> data;
//     stackNode * temp = top;
//     top = top -> next;
//     delete temp;
//     size--;
//     return topData;
//   }
// size(): returns the size of the stack

// For this, we maintain a size variable. After each push operation, we increment the size variable and after each pop operation, we decrement the size variable.

// Let’s see the code implementation for this function.

// Code:

// C++
// Java
// int stackSize() {
//     return size;
//   }
// isEmpty(): returns a boolean value for whether the stack is empty or not.

// To do this, we check if our top is equal to NULL.

// Code implementation is as follows:

// Code:

// C++
// Java
// bool stackIsEmpty() {
//     return top == NULL;
//   }
// The following code compiles every function to form a complete stack implementation using a linked list.


#include<iostream>
using namespace std;

struct stackNode {
  int data;
  stackNode * next;
  int size;
  stackNode(int d) {
    data = d;
    next = NULL;
  }
};
struct stack {
  stackNode * top;
  int size;
  stack() {
    top = NULL;
    size = 0;
  }
  void stackPush(int x) {
    stackNode * element = new stackNode(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }
  int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }
  int stackSize() {
    return size;
  }
  bool stackIsEmpty() {
    return top == NULL;
  }
  int stackPeek() {
    if (top == NULL) return -1;
    return top -> data;
  }
  void printStack() {
    stackNode * current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};
int main() {
  stack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}