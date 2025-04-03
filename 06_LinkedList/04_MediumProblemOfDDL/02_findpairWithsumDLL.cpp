#include <iostream>
#include <vector>

using namespace std;

// Doubly linked list node class
class Node {
public:
    int data;
    Node *next, *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Solution {
public:
    Node* findTail(Node* temp) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* left = head;
        Node* right = findTail(head);
        
        vector<pair<int, int>> ans;

        while (left != NULL && right != NULL && left->data < right->data) {
            int sum = left->data + right->data;
            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next; 
                right = right->prev;
            } else if (sum < target) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return ans;
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    Node* head = NULL;

    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    cout << "Doubly linked list: ";
    printList(head);

    int target = 6;
    Solution sol;
    vector<pair<int, int>> pairs = sol.findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ":\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
