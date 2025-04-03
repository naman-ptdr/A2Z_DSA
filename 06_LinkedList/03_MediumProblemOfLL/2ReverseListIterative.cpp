// Reverse a Linked List

// Problem Statement: Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.


// Approach 2: Reverse Links in place (Iterative)

// The previous approach uses O(N) addition space which can be avoided by interchanging the connecting links of the nodes of the linked list in place.


// The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows. When this happens, the last element becomes the new first element of the list. This in-place reversal allows us to efficiently transform the original list without using extra space.

// Algorithm:

// Step 1: Initialise a ‘temp’ pointer at the head of the linked list. This pointer will be used to traverse the linked list. And initialize the pointer ‘prev’ to ‘NULL’ to keep track of the previous node. This will be used to reverse the direction of the ‘next’ pointers.


// Step 2: Traverse the entire linked list by moving through each node using the 'temp' pointer until it reaches the end (marked as 'NULL').

// At each iteration within the traversal,

// Save the reference to the next node that 'temp' is pointing to in a variable called 'front'. This helps retain the link to the subsequent node before altering the 'next' pointer.

// Reverse the direction of the ‘next’ pointer of the current node (pointed to by ‘temp’) to point to the ‘prev’ node. This effectively reversed the direction of the linked list, making the current node point to the previous node. 

// Move the ‘prev’ pointer to the current node. This sets up the ‘prev’ pointer for the next iteration of the loop.
// Move the ‘temp’ pointer to the ‘front’ node. This advances the traversal to the next node in the original order.

// In summary:


// Step 3: Keep traversing through the linked list using the 'temp' pointer until it reaches the end, thereby reversing the entire list. Once the 'temp' pointer reaches the end, return the new head of the reversed linked list, which is now indicated by the 'prev' pointer. This 'prev' pointer becomes the first node in the newly reversed list.





#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse a linked list
// using the 3-pointer approach
Node* reverseLinkedList(Node *head)
{
   // Initialize'temp' at
   // head of linked list
   Node* temp = head;  
   
   // Initialize pointer 'prev' to NULL,
   // representing the previous node
   Node* prev = NULL;  
   
   // Traverse the list, continue till
   // 'temp' reaches the end (NULL)
   while(temp != NULL){  
       // Store the next node in
       // 'front' to preserve the reference
       Node* front = temp->next;  
       
       // Reverse the direction of the
       // current node's 'next' pointer
       // to point to 'prev'
       temp->next = prev;  
       
        // Move 'prev' to the current
        // node for the next iteration
       prev = temp;  
       
        // Move 'temp' to the 'front' node
        // advancing the traversal
       temp = front; 
   }
   
   // Return the new head of
   // the reversed linked list
   return prev;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}


