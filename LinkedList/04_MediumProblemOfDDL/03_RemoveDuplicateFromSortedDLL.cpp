#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        Node* p = head;
        while (p != NULL) {
            // While the next node exists and is a duplicate
            while (p->next != NULL && p->data == p->next->data) {
                Node* temp = p->next;  // Store the duplicate node
                p->next = temp->next;   // Bypass the duplicate
                if (temp->next) {
                    temp->next->prev = p; // Update the prev pointer of the next node
                }
                delete temp;  // Free memory of the duplicate node
            }
            p = p->next; // Move to the next unique node
        }
        return head; // Return the modified list
    }
};

// Helper function to append a new node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to print the list
void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main function for testing
int main() {
    Node* head = NULL;

    // Creating a doubly linked list: 1 <-> 1 <-> 2 <-> 3 <-> 3
    append(&head, 1);
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.removeDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
