/*Delete Last Node of a Doubly Linked List

Problem Statement: Given a Doubly Linked List. Delete the last of a Doubly Linked List.

Examples
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution:
Approach:

To delete the tail of a doubly linked list, we update the linkage between its last
node and its second last node. Since a doubly linked list is bidirectional, we set
the second last node's next pointer and the last node's back pointer to null. Then,

we return the head as the result.

Two edge cases to consider are:

If the input doubly linked list is empty, we return null.
If there is only one node in the list, that node itself will be the tail and we return
null after deleting that node.
Algorithm

Step 1: Traverse the doubly linked list to the last node and keep track of it using the
tail pointer.

We start from the head of the doubly linked list and iterate through the list using a while
loop until we reach the last node. The tail pointer is used to keep track of this last node.

Step 2: Obtain the second last node using the tail's back pointer, and name it the prev pointer.

Step 3: Set the 'next' pointer of the prev node to null. This step effectively disconnects
the initial tail node from the list in the forward direction, making prev the new tail node.

Step 4: Set the 'back' pointer of the tail node to null. This ensures that the tail node no
longer points back to the prev node, as it is now the last node in the list.

Step 5: Return the head of the doubly linked list as the result. Now that we have updated the
doubly linked list, the list is now one node shorter than before.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list (forward direction)
    Node *back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node *convertArr2DLL(vector<int> arr)
{
    // Create the head node with the first element of the array
    Node *head = new Node(arr[0]);
    // Initialize 'prev' to the head node

    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node *temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node

        prev->next = temp;
        // Move 'prev' to the newly created node for the next iteration

        prev = temp;
    }
    // Return the head of the doubly linked list

    return head;
}

// Function to print the elements of the doubly linked list
void print(Node *head)
{
    while (head != nullptr)
    {
        // Print the data in the current node
        cout << head->data << " ";
        // Move to the next node
        head = head->next;
    }
}

// Function to delete the head of the doubly linked list
// The functionality of this has been explained in our previous
// article, please refer to it.
Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // Return NULL if the list is empty or contains only one element
        return nullptr;
    }

    // Store the current head as 'prev'
    Node *prev = head;
    // Move 'head' to the next node
    head = head->next;

    // Set 'back' pointer of the new head to nullptr
    head->back = nullptr;

    // Set 'next' pointer of 'prev' to nullptr
    prev->next = nullptr;

    // Return the new head
    return head;
}

// Function to delete the tail of the doubly linked list
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // If the list is empty or has only one node, return null
        return nullptr;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        // Traverse to the last node (tail)
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    // Free memory of the deleted node
    delete tail;

    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2DLL(arr);

    cout << "Original Doubly Linked List: ";
    print(head);

    cout << "\n\nAfter deleting the tail node: ";
    head = deleteTail(head);
    print(head);

    return 0;
}

/*
Output:

12 5 8 7
After deleting tail node:
12 5 8

Time Complexity: O(1) Removing the head of a doubly linked list is a quick operation,
taking constant time because it only involves updating references.

Space Complexity: O(1) Deleting the head also has minimal memory usage, using a few
extra pointers without regard to the list's size.*/