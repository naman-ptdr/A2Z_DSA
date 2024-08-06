// Iterative Postorder Traversal of Binary Tree Using 2 Stacks

// Problem Statement: Given the root of a Binary Tree, create a function that performs a postorder traversal using two stacks and returns an array containing the traversal sequence.
// This approach performs a modified postorder traversal (left, right then root) and then reverses the result to obtain the postorder traversal sequence. This approach uses two stacks, one for traversal and another to store the nodes in a manner that facilitates obtaining the postorder sequence in reverse.The root node is pushed onto the first stack to initiate traversal and nodes are iteratively processed by popping them from the first stack, pushing them onto the second and adding their left and right children onto the first stack. This process continues until all nodes have been processed.Lastly, all nodes from the second stack are popped and retrieved in reverse order, effectively getting the postorder traversal sequence which is stored in an array and returned.

// Algorithm:

// Step 1: Create two stacks: one for holding nodes and another for storing the final postorder traversal sequence. Initialise an array `postorder` to store the traversal sequence.


// Step 2: Push the root node to the first stack.


// Step 3: Process the nodes until the first stack is empty:

// Pop a node from the top of the first stack.
// Push this node onto the second stack.
// Push its left child (if it exists) onto the first stack.
// Push its right child (if it exists) onto the first stack.

// Step 4:Once the first stack is empty, retrieve the nodes in the postorder sequence by popping nodes from the second stack one by one and store them in the postorder array.




                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder
// traversal of a binary tree using
// two stacks
vector<int> postOrder(Node* root) {
    // Vector to store
    // postorder traversal
    vector<int> postorder;

    // If the tree is empty,
    // return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Two stacks for
    // iterative traversal
    stack<Node*> st1, st2;

    // Push the root node
    // onto the first stack
    st1.push(root);

    // Iterative traversal to populate
    // st2 with nodes in postorder
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal 
    // vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the
    // postorder traversal
    return postorder;
}




// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
                            
// Time Complexity: O(2N) where N is the number of nodes in the Binary Tree. The traversal process visits each node in the Binary Tree exactly once to push into stack1 and stack2. Then after the tree is traversed and the nodes are popped from stack2 to push into the postorder array.

// Space Complexity: O(2N) where N is the number of nodes in the Binary Tree. The space occupied by the two stacks depend on the height of the binary tree. In the worst-case scenario, if the tree is skewed, the space complexity would be O(N) as both stacks could potentially hold all nodes at different points during traversal.The postorder array also holds all nodes from the binary tree hence giving another O(N) + O(N) ~ O(2N).