#include <iostream>

using namespace std;

class Node {
public:
    int digit;
    Node* next;

    Node(int data){
    	this->digit = data;
    	this->next = NULL;
	}
};

class LinkedList {
public:
    Node* insertNode(Node* start, int data) { //yeh code ek naya node banata hai aur use linked list ke shuruaati node ke peechhe laga deta hai. new_node ko fir return kiya jata hai, jisse yeh naya node linked list ka naya head ban jata hai. Is tareekay se linked list mein naye nodes ko add kiya ja sakta hai
        Node* new_node = new Node(data);   //create a new node 
        new_node->next = start;            //new node point to head(start)
        return new_node;                  //and then return it
    }

    Node* addLinkedLists(Node* num1, Node* num2) {
        Node* result = NULL;  // se ek naya linked list result initialize kiya jata hai jiska pehla node NULL hota hai
        int carry = 0;        //carry variable initialize kiya jata hai, jiska initial value 0 hota hai.
        while (num1 != NULL || num2 != NULL || carry != 0) {  //Loop tab tak chalta hai jab tak dono linked lists khatam nahi ho jati aur koi carry bachti hai
            int x = 0;  // pehle 0 se initialize kiya jata hai.
            if (num1) {  //Is line mein check kiya jata hai ki kya num1 NULL hai ya nahi. Agar num1 NULL nahi hai, toh num1->digit ki value x mein assign ki jati hai, jisse x mein num1 ke digit ka value aa jata hai. Agar num1 NULL hai, toh x 0 rehta hai
            x = num1->digit;
            }

            int y = 0;
            if (num2) {
            y = num2->digit;
            }

            int sum = x + y + carry; //Yeh ek digit-wise addition ka hissa hai, jahan x aur y current digits hain jo num1 aur num2 se aaye hain, aur carry carry digit ko represent karta hai. Isse sum mein current digits ka jama (addition) ho jata hai
            carry = sum / 10;  
            result = insertNode(result, sum % 10); //Is line ka matlab hai ki sum ke last digit ko result linked list mein ek naye node ke roop mein add kiya jata hai.
//sum % 10 se sum ki value ki last digit nikali jati hai. For example, agar sum ki value 37 hai, to sum % 10 se last digit 7 nikala jayega.
//Is last digit ko ek naye node ke taur par result linked list mein shamil kiya jata hai. Yani, agar sum % 10 7 hai, to ek naya node banaya jata hai jiska data 7 hota hai, aur yeh node result linked list mein jod diya jata hai.
//result linked list mein jo node add kiya gaya hai, woh ab result ke head ke roop mein consider hota hai.
            if (num1) num1 = num1->next; //Yeh dono lines num1 aur num2 ko unke next nodes par move karne mein madadgar hoti hain.
            if (num2) num2 = num2->next;
        }
        return result;
    }

    void printDigits(Node* node) {
        Node* temp = node;
        while (temp != NULL) {
            cout << " " << temp->digit << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    Node* num1 = NULL;
    Node* num2 = NULL;
    int firstDigit;
    int secondDigit;
    int entries1;
    int entries2;

    cout << "How many digits you want to enter in NUMBER 1?: ";
    cin >> entries1;
    for (int i = 0; i < entries1; i++) {
        cout << "nEnter digit: ";
        cin >> firstDigit;
        num1 = list.insertNode(num1, firstDigit);
    }

    cout << endl;
    cout << "nHow many digits you want to enter in NUMBER 2?: ";
    cin >> entries2;
    for (int i = 0; i < entries2; i++) {
        cout << "Enter digit: ";
        cin >> secondDigit;
        num2 = list.insertNode(num2, secondDigit);
    }

    cout << endl;
    cout << "Number 1 : ";
    list.printDigits(num1);
    cout << endl;
    cout << "Number 2 :";
    list.printDigits(num2);
    cout << endl;
    Node* addition = list.addLinkedLists(num1, num2);
    cout << "Addition: ";
    list.printDigits(addition);

    // Free memory for linked lists
    while (num1 != NULL) {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != NULL) {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (addition != NULL) {
        Node* temp = addition;
        addition = addition->next;
        delete temp;
    }

    return 0;
}

