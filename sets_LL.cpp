#include <iostream>
#include <unordered_set>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
    	this->data = data;
    	this->next = NULL;
	}
};

class Set {
private:
    Node* head;

public:
    Set(){
    	head = NULL;
	}

    void insert(int data) {
        if (!contains(data)) {  //check karta k data set main mojood hai ya nhi ? nhi hai to new node bana kar dal deta 
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }

    bool contains(int data) const {  //check karta k contain element function set me mojud haui ya nhi or oconst yeh check karta k koi duplicate value to nhi hai 
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {  //jo value arahi hai woh pehlay se mojood hai ya nhi ?
                return true;
            }
            current = current->next;    //or current ko barha do agy 
        }
        return false;
    }

    void display() {    //same ll wala print function
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Set unionSets(const Set& other) const {  // set va;lue main other dosri value ko target kar raha hai 
        Set result;
        Node* current = head;
        while (current != NULL) {    //jab tak current null na ho jaye tab tak insertion k function se result main data add karwaty jao
            result.insert(current->data);
            current = current->next;  
        }

        current = other.head;        //dosry set ki value dekh rahy ab 
        while (current != NULL) {
            result.insert(current->data);
            current = current->next;   //isko bhi result main store karwaty jao 
        }

        return result;
    }

    Set intersectionSets(const Set& other) const {
        Set result;
        Node* current = head;
        while (current != NULL) {
            if (other.contains(current->data)) {  //current set ke current element ka data other set mein mojud hai ya nah
                result.insert(current->data);     //other set mein mojud hai (condition true hoti hai), to result.insert(current->data); se current element ka data result set mein insert kiya jata hai
            }
            current = current->next;    
        }
        return result;
    }

    Set differenceSets(const Set& other) const {
        Set result;
        Node* current = head;
        while (current != NULL) {
            if (!other.contains(current->data)) {   //current element ka data other set mein nahi hona chahiye taaki woh difference ka hissa ho
                result.insert(current->data);       //current element ka data result set mein insert kiya jata ha
            }
            current = current->next;
        }
        return result;
    }

    void customInsert(int firstItem, int secondItem) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == firstItem) {         //yani first item pe value mojood hai
                Node* newNode = new Node(secondItem);  // ab bari ati second item ki to usy create kia pehlay
                newNode->next = current->next;        // //imaan wali example
                current->next = newNode;
                current = newNode;
            }
            current = current->next;
        }
    }
};

int main() {
    Set set1;
    Set set2;
    set1.insert(5);
    set1.insert(8);
    set1.insert(3);
    set2.insert(1);
    set2.insert(3);
    set2.insert(4);

    cout << "Set 1: ";
    set1.display();
    cout << "Set 2: ";
    set2.display();

    Set unions = set1.unionSets(set2);    //union le lia idher set 1 or set 2 ka 
    cout << "Union of the sets: ";
    unions.display();

    Set intersectionResult = set1.intersectionSets(set2);
    cout << "Intersection of the sets: ";
    intersectionResult.display();

    Set differenceResult = set1.differenceSets(set2);
    cout << "Difference of the sets: ";
    differenceResult.display();

    Set set3;
    set3.insert(5);
    set3.insert(4);
    set3.insert(5);
    set3.insert(8);
    set3.insert(9);
    set3.insert(1);

    set3.customInsert(5, 2);
    cout << "Customized Insert is: ";
    set3.display();

    return 0;
}

