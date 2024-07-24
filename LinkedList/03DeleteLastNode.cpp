// Problem Statement: Given a linked list, delete the tail of 
// the linked list and print the updated linked list.

// Approach:
// The main intuition is to point the second last node to null to 
// get the updated linked list. Hence, we will iterate till the second last node and make it point to NULL. This will effectively skip the last node of the list therefore, we will free up the memory being occupied by this node (Only in the case of C++).

// Two edge cases to consider are:

// If the input linked list is empty, we return null.
// If there is only one node in the list, that node itself will be 
// the tail, therefore we return null after deleting that node.


#include<bits/stdc++.h>
using namespace std;
// Node class for a linked list
class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Function to print the linked list starting from the given head
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Function to delete the tail node of a linked list and return the new head
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}
int main() {
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    head = deleteTail(head);
    // Print the linked list after deletion
    printLL(head);
}

// Time Complexity: O(N) for traversing the linked list and updating the tail.

// Space Complexity: O(1), as we have not used any extra space.