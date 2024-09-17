// Detect a Cycle in a Linked List
//     Examples
//         Example 1 :

//     Input Format :

//     LL : 1 2 3 4 5

//     Result : True

//Explanation : The last node with the value of 5 has its 'next' pointer pointing back to a previous node with the value of 3. This has resulted in a loop,
//hence we return true.

// Algorithm / Intuition
// The previous method uses O(N) additional memory, which can become quite large as the linked list length grows. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.

// The Tortoise and Hare approach has been discussed in this article. 

// When the tortoise and hare enter the loop, they may be at different positions within the loop due to the difference in their speeds. The hare is moving faster, so it will traverse a greater distance in the same amount of time.

// If there is no loop in the linked list, the hare will eventually reach the end, and the algorithm will terminate without a meeting occurring.


// Algorithm
// Step 1: Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time, while `fast` will advance two steps at a time. These pointers will move simultaneously.

// Step 2: Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and `fast` two steps at a time.

// Step 3: Continue this traversal until one of the following conditions is met:

// `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop in the linked list ie. the linked list is linear, and the algorithm terminates by returning false.
// `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list, and the algorithm terminates by returning `true`.

// Intuition: 
// In a linked list with a loop, consider two pointers: one that moves one node at a time (slow) and another that moves two nodes at a time (fast). If we start moving these pointers with their defined speed they will surely enter the loop and might be at some distance 'd' from each other within the loop.

// The key insight here is the relative speed between these pointers. The fast pointer, moving at double the speed of the slow one, closes the gap between them by one node in every iteration. This means that with each step, the distance decreases by one node.

// Imagine a race where one runner moves at twice the speed of another. The faster runner covers the ground faster and closes the gap, resulting in a reduction in the distance between them. Similarly, the fast pointer catches up to the slow pointer in the looped linked list, closing in the gap between them until it reaches zero.

// Proof: 
// Let 'd' denote the initial distance between the slow and fast pointers inside the loop. At each step, the fast pointer moves ahead by two nodes while the slow pointer advances by one node.



// The relative speed between them causes the gap to decrease by one node in each iteration (fast gains two nodes while slow gains one node). This continuous reduction ensures that the difference between their positions decreases steadily. Mathematically, if the fast pointer gains ground twice as fast as the slow pointer, the difference in their positions reduces by one node after each step. Consequently, this reduction in the distance between them continues until the difference becomes zero.

// Hence, the proof lies in this iterative process where the faster rate of the fast pointer leads to a continual decrease in the gap distance, ultimately resulting in their collision within the looped linked list.





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

// Function to detect a loop in a linked
// list using the Tortoise and Hare Algorithm
bool detectCycle(Node* head) {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}


int main() {
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}

