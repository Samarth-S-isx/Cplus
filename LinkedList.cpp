#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        this->data = value;
        this->next = NULL; 
    }

    // destructor
    ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
    }
};

// 
void insertathead(Node* &head,int d){
    // new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertattail(Node* &tail,int d){
    Node* temp  = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertatmiddle(Node* &head,int pos,int d){
    Node* newnode = new Node(d);
    Node* temp = head;
    int cnt = 1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletetion(Node* &head,int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            prev= curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void traverse(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<endl;
}
int main()
{
    Node* node1 = new Node(10);
    // cout<< node1->data<<endl;
    // cout<< node1->next<<endl;
    Node* head = node1;
    Node* tail = node1;
    insertathead(head,15);
    insertathead(head,1);
    insertattail(tail,100);
    insertatmiddle(head,3,200);
    traverse(head);
    deletetion(head,3);
    traverse(head);   
}
