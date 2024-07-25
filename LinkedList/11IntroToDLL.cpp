// Introduction to Doubly Linked List

// In the realm of data structures, it's essential to grasp the
// intricacies of doubly linked lists. These data structures are
// characterized by their ability to efficiently navigate in both
// forward and backward directions. Before diving into the depths of
// doubly linked lists, it's beneficial to recap our understanding of
// linked lists, and their precursor.

// Recap on Linked List

// Before exploring doubly linked lists, let's refresh our knowledge of linked lists.
// Linked lists are linear data structures consisting of nodes, each containing data
// and a reference (or pointer) to the next node. This setup allows for dynamic memory
// allocation and efficient insertions and deletions.

// A significant characteristic of singly linked lists is their unidirectional nature,
// allowing traversal in only one direction: forward. Moving backward, such as going from
// node 1 to node 3, is not possible because each node in a singly linked list holds two
// pieces of information - the data (an integer value in this case) and a pointer that
// indicates the address of the next node. This structure enables efficient forward navigation,
// but the absence of a backward pointer restricts reverse traversal.

// Doubly Linked Lists,  as the name suggests, take the concept of 2-way traversal by
// introducing two pointers in each node. This enables seamless traversal in both directions,
// making them a valuable tool for various advanced data structure applications.

// Code:

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor for a Node with both data and a reference to the next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for a Node with data and no reference to the next node (end of the list)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};