#include <iostream>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* current = *head_ref;
        
        while (current != NULL) {
            if (current->data == x) {
                // Node to delete found
                Node* nextNode = current->next;
                Node* prevNode = current->prev;
                
                // Adjust pointers of the adjacent nodes
                if (prevNode) {
                    prevNode->next = nextNode;
                } else {
                    // If prevNode is NULL, we're at the head
                    *head_ref = nextNode;  // Update head
                }
                
                if (nextNode) {
                    nextNode->prev = prevNode;
                }
                
                // Delete current node
                delete current;
                current = nextNode;  // Move to the next node
            } else {
                // Move to the next node
                current = current->next;
            }
        }
    }
};

// Function to print the list
void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Helper function to add a new node at the end of the list
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

// Main function for testing
int main() {
    Node* head = NULL;
    
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 4);
    
    std::cout << "Original list: ";
    printList(head);

    int x = 2;
    Solution sol;
    sol.deleteAllOccurOfX(&head, x);
    
    std::cout << "List after deleting all occurrences of " << x << ": ";
    printList(head);
    
    return 0;
}
