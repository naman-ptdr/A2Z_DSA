// Delete the Middle Node of the Linked List

// Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.
// Algorithm / Intuition
// The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal.

// The 'slow' pointer advances one node at a time while the 'fast' pointer moves two nodes at a time. By doing so, when the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.

// Since we require `slow` to reach the node before the middle node, we give `fast` a head start!

// Algorithm
// Step 1: Check if the list is empty or contains only one node. If so, no middle node exists to delete, return NULL. Initialise 'slow' and 'fast' pointers at the head of the list.

// Move ‘fast’ two nodes ahead for the initial position as we have to reach the node previous to the middle node via slow.

// Step 2: Move the 'fast' pointer two nodes ahead and the 'slow' pointer one node ahead in each iteration. Continue this process until the 'fast' pointer reaches the end of the list.


// Step 3: Once the 'fast' pointer reaches the end, the 'slow' pointer will be at the middle node. Delete the middle node by skipping it from the linked list. 


// Step 4: Return the head of the modified linked list.


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:

    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to delete the
// middle node of a linked list
Node *deleteMiddle(Node *head) {
    // If the list is empty or has only one node,
    // return NULL as there is no middle node to delete
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    slow->next = slow->next->next;
    return head;
}

void printLL(Node* head){
    
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    return 0;
}

