// Find intersection of Two Linked Lists


// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2
// Explanation: Here, both lists intersecting nodes start from node 2.

// Example 2:
// Input:
//  List1 = [1,2,7], List 2 = [2,8,1]
// Output:
//  Null
// Explanation: Here, both lists do not intersect and thus no intersection node is present.

// Solution 1: Brute-Force

// Approach: We know intersection means a common attribute present between two entities. Here, we have linked lists as given entities. 

// What should be the common attribute for two linked lists? 

// If you believe a common attribute is a node's value, then think properly! If we take our example 1, there we can see both lists have nodes of value 3. But it is not the first intersection node. So what’s the common attribute?

// It is the node itself that is the common attribute. So, the process is as follows:-

// Keep any one of the list to check its node present in the other list. Here, we are choosing the second list for this task.
// Iterate through the other list. Here, it is the first one. 
// Check if the both nodes are the same. If yes, we got our first intersection node.
// If not, continue iteration.
// If we did not find an intersection node and completed the entire iteration of the second list, then there is no intersection between the provided lists. Hence, return null.

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
// void insertNode(node* &head,int val) {
//     node* newNode = new node(val);
    
//     if(head == NULL) {
//         head = newNode;
//         return;
//     }
    
//     node* temp = head;
//     while(temp->next != NULL) temp = temp->next;
    
//     temp->next = newNode;
//     return;
// }

// //utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//     while(head2 != NULL) {
//         node* temp = head1;
//         while(temp != NULL) {
//             //if both nodes are same
//             if(temp == head2) return head2;
//             temp = temp->next;
//         }
//         head2 = head2->next;
//     }
//     //intersection is not present between the lists return null
//     return NULL;
// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists 
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }



// Solution 2: Hashing

// Approach:

// Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-

// Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
// Iterate through list 2 and search the hashed value in the hash table. If found, return node.


#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
//utility function to insert node at the end of the linked list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}

//utility function to print linked list created
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}

int main() {
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}