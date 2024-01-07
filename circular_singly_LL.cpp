#include <iostream>
using namespace std;

class Node{
	public:
    	int data;
     	Node* next;
	
//	constructor
	Node(int d){
		this -> data = d;
		this -> next = NULL;
	}
	
//	destructor
	~Node(){
		int value = this -> data;
		if(this -> next != NULL){
			delete next;
			next = NULL;
		}
		cout<<"memory is free for node with data "<<value<<endl;
	}
};


void insertNode(Node* &tail, int element, int d){
	
//	empty list
	if(tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode -> next = newNode;
	}
//	non-empty list
//	assuming that the element is present in the list
	else{
		Node* curr = tail;
		
		while(curr -> data != element){
			curr = curr -> next;
		}
		Node* temp = new Node(d);
		temp -> next = curr -> next;
		curr -> next = temp;
	}
}

void deleteNode(Node* &tail, int value){
//	enpty list
	if(tail == NULL){
		cout<<"your list is empty please add insert function then call delete"<<endl;
		return; 
	}
	else{
		Node* prev = tail;
		Node* curr = prev->next;
		
		while(curr->data != value){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		if(tail == curr){       // jab 1st node delete karni ho to woh node tail pe hi hogi curr wali to usy prev se point karwaya taky 1st node bhi delete hi saky
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
	}
}

//print function
	void print(Node* tail){
		Node* temp = tail;
		do {
			cout<<tail -> data<<" ";
			tail = tail -> next;
		}while(tail != temp);
		cout<<endl;
	}



int main(){
    // Tail function that starts as empty
    Node* tail = NULL;
    
    // Insert the first element
    insertNode(tail, 5, 3);
    print(tail);
    
    // Insert another element
    insertNode(tail, 3, 5);
    print(tail);
    
    
	// Insert another element
    insertNode(tail, 5, 7);
    print(tail);
    
    // Insert another element
    insertNode(tail, 7, 9);
    print(tail);
    
//    insert middle element
	insertNode(tail, 5, 6);
	print(tail);
	
	deleteNode(tail, 6);
	print(tail);
	
	deleteNode(tail, 3);
	print(tail);
    
    return 0;
}









