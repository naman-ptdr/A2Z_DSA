// Sort a Linked List

// Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.\
// Algorithm / Intuition
// Instead of using an external array to store node values, we can employ a sorting algorithm without using any extra space. An in-place sorting algorithm like Merge Sort or Quick Sort adapted for linked lists can achieve this.

// Read more about Merge Sort here!Merge Sort Algorithm. A modified version of merge sort can operate directly on the linked list without using any additional space. This algorithm would divide the linked list into halves recursively until single nodes remain. These sorted halves of the linked list are merged back together in a sorted order.


// This approach employs the divide-and-conquer strategy:

// Divides the linked list into smaller parts until they become trivial to sort (single node or empty list).
// Merges and sorts the divided parts while combining them back together.
// Algorithm

// Step 1: Base Case If the linked list contains zero or one element, it is already sorted. Return the head node.

// Step 2: Split the ListFind the middle of the linked list using a slow and a fast pointer. Read more about this approach here!Middle Element in Linked List. Split the linked list into two halves at the middle node. The two halves will be left and right.


// Step 3: RecursionRecursively apply merge sort to both halves obtained in the previous step. This step continues dividing the linked list until there's only one node in each half.

// Step 4: Merge Sorted ListsMerge the sorted halves obtained from the recursive calls into a single sorted linked list. Compare the nodes from both halves and rearrange them to form a single sorted list. Update the head pointer to the beginning of the newly sorted list.

// Step 5: ReturnOnce the merging is complete, return the head of the sorted linked list.

                                
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

// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
Node* findMiddle(Node* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head){
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // Find the middle of the list using the findMiddle function
    Node* middle = findMiddle(head);
    
    // Divide the list into two halves
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;
    
    // Recursively sort the left and right halves
    left = sortLL(left);
    right = sortLL(right);
    
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}


int main() {
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}

                                
                            