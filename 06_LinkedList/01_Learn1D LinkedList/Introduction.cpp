#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* convertToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int findLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool searchInLL(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data==val) return true;
        temp = temp->next;
    }
    return false;
}


int main(){
    vector<int> arr = {8, 3, 9, 22, 88};
    Node* head = convertToLL(arr);
    cout<<"Head of LL : "<<head->data<<endl;
    cout<<"Linked List : ";
    printLL(head);
    int length = findLength(head);
    cout<<"Length Of LL "<<length<<endl;

    cout<<"Is 9 is in LL or not : "<< searchInLL(head, 9);
}
