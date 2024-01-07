#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
	Node(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	
	~Node(){
		int value = this->data;
		if(next != NULL){
			delete next;
			next = NULL;
		}
		cout<<"memory is free for node with data"<<value<<endl;
	}
};

void insertAtHead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next = head;
	head->prev = temp;
	head = temp;
}
void insertAtTail(Node* &tail, int d){
	Node* temp = new Node(d);
	tail->next = temp;
	temp->prev = tail;
	tail = tail->next;
}
void inserAtPosition(Node* &head, Node* &tail, int position, int d){
	if(position == 1){
		insertAtHead(head, d);
		return;
	}
	Node* temp = head;
	int cnt = 0;
	
	while(cnt <position - 1){
		temp = temp->next;
		cnt++;
	}
	
	if(temp->next == NULL){
		insertAtTail(tail, d);
		return;
	}
	
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
	
	
	
}

void deleteNode(Node* &head, int position){
	if(position == 1){
		Node* temp = head;
		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		delete temp;
		
	}
	else{
		Node* curr = head;
		Node* prev = NULL;
		int cnt = 1;
		
		while(cnt < position){
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		
		curr->prev = NULL;
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

void print(Node* &head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	
}

int main(){
	Node* node1 = new Node(10);
	Node* head =node1;
	Node* tail = node1;
	print(head);
	insertAtHead(head, 20);
	print(head);
	insertAtTail(tail, 40);
	print(head);

 inserAtPosition(tail, head, 2, 44);
	print(head);

	cout<<"Head"<<head->data<<endl;
	
	cout<<"Tail"<<tail->data<<endl;
	
	deleteNode(head, 2);
	print(head);
	return 0;
}


