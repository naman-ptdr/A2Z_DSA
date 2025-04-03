// Problem Statement: Given the head of a linked list, print 
// the length of the linked list.

// Approach:
// The most naive method to find the length of a linked list is 
// to count the number of nodes in the list by doing a traversal 
// in the Linked list.


#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
// Function to calculate the length of a linked list
int lengthOfLinkedList(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    // Traverse the linked list and count nodes
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++; // increment cnt for every node traversed
    }
    return cnt;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    // Create a linked list
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Print the length of the linked list
    cout << lengthOfLinkedList(head) << '\n';
}


// Time Complexity: 

// Since we are iterating over the entire list,  time complexity is O(N).

// Space Complexity:

// We are not using any extra space, thus space complexity is O(1) or constant.