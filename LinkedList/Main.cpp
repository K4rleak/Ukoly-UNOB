#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    
    Node* NewNode(int data);
    void Printnode();
    Node* AddNextNode(int data);
    
};


int main(){
    Node* node1 = node1->NewNode(1);
    cout<<"Node1:"<<endl;
    node1->Printnode();

    Node* node2=node2->NewNode(2);
    cout<<"Node2:"<<endl;
    node2->Printnode();

    node1->next=node2;
    cout<<endl<<"Node1&2:"<<endl;
    node1->Printnode();

    Node* node3 = node1->AddNextNode(3);
    cout<<endl<<"Node1&2&3:"<<endl;
    node1->Printnode();

return 0;
}

Node* Node::NewNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void Node::Printnode(){
    cout << "[Address: " << this << ", val: " << this->data << ", next: " << this->next << "]" << endl;
	if (this->next != NULL) this->next->Printnode();
}

Node* Node::AddNextNode(int data){
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next = this->next;
    this->next = newNode;
    return newNode;
}