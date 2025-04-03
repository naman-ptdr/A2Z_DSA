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

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* removeK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* prev = NULL;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

int main(){
    vector<int> arr = {8, 3, 9, 22, 7, 2, 50};
    Node* head = convertToLL(arr);
    cout<<"Head of LL : "<<head->data<<endl;
    cout<<"Linked List : ";
    printLL(head);
    int length = findLength(head);
    cout<<"Length Of LL "<<length<<endl;

    cout<<"Is 9 is in LL or not : "<< searchInLL(head, 9)<<endl;

    head = removeHead(head);
    cout<<"Head of new LL : "<<head->data<<endl;

    head = removeTail(head);
    cout<<"New Linked List after remove tail : ";
    printLL(head);

    head = removeK(head, 3);
    cout<<"New Linked List after remove 3rd element : ";
    printLL(head);

    // Insert at head

    // head = new Node(5, head);

    head = insertHead(head, 5);
    cout<<head->data<<endl;
}
