#include <iostream>
using namespace std;
class Node{
	public: 
	int data;
	Node* next;
	
//	constructor
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
	
//	destructor
	~Node(){
		int value = this -> data;
//		memory free
	if(this -> next != NULL){
		delete next;
		this -> next = NULL;
	}
	cout<<"memory is free for node with data "<<value<<endl;
	}
};

void insertionAtHead(Node* &head, int d){
//	is function ko call karne se L.L me sari values head se ati hain
//	new node create
	Node* temp = new Node(d);
 	temp -> next = head;
	head = temp;
}

void insertionAtTail(Node* &tail, int d){
	//	new node create
	Node* temp = new Node(d);
    tail -> next = temp;
	tail = tail -> next;	
}

//print function  (how to traverse a link list
void print(Node* &head){
	Node* temp = head;
	
//	loop jab tak temp = null na ho jaye 
while(temp != NULL ){
	cout << temp -> data <<" ";
	temp = temp -> next;
}
cout << endl;
}

//middle main kisi element me add karwana 
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
	
//	agar head pe hi kuch add karwana ho to 
	if(position == 1){
		insertionAtHead(head, d);
		return;
	}
	Node* temp = head;
	int cnt = 1;
	
	while(cnt < position-1){
		temp = temp -> next;
		cnt++;
	}
	
//	inserting at last position
	if(temp -> next == NULL){
		insertionAtTail(tail, d);
		return;
	}
	
//	creating a node for d
	Node* nodeToInsert = new Node(d);
	nodeToInsert -> next = temp -> next;
	temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head){
//	deleting first node 
	if(position == 1){
		Node* temp = head;
		head = head -> next;
//		memory free start node 
	temp -> next = NULL;  // curr k next ko null karne se yeh hoa k jo node delete kar rahy hain woh ab point hi nhi kary gi kahin bhi 
	delete temp;
	}
	else{
//		deleting any middle node or last node
	Node* curr = head;
	Node* prev = NULL;
	
	int cnt =1;
	while(cnt < position){
		prev = curr;
		curr = curr -> next;
		cnt++;
	}
	prev -> next = curr -> next;
	curr -> next = NULL;    // curr k next ko null karne se yeh hoa k jo node delete kar rahy hain woh ab point hi nhi kary gi kahin bhi 
	delete curr;
	}
}

int main(){
	
//	create a new node
	Node* node1 = new Node(10);
//	cout << node1 -> data << endl;
//	cout << node1 -> next <<endl;
	
//	head pointed to new node1
Node* head = node1;
print(head);

// --------

//tail node k liye function link karwaya
Node* tail = node1;
print(tail);

insertionAtTail(tail, 12);
print(head);

insertionAtTail(tail, 15);
print(head);

insertAtPosition(tail, head, 1, 22);

insertAtPosition(tail, head, 4, 23);  // head pe dalne se two times print ho raha
print(head);

cout << "head" << head -> data << endl;
cout << "tail" << tail -> data << endl;

deleteNode(4, head);
print(head);

return 0;


}
