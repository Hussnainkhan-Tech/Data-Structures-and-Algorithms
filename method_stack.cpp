#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// PUSH
void push(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    cout << val << " pushed\n";
}

// POP
void pop() {
    if (top == NULL) {
        cout << "Stack Empty\n";
        return;
    }
    Node* temp = top;
    cout << temp->data << " popped\n";
    top = top->next;
    delete temp;
}

// DISPLAY
void display() {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
}




// class stack{
//     int data;
//     node* next;
// };
// node* top=NULL;

// void push(int val){
//     node* newNode=new node(val);
//     newNode->data=val;
//     newNode->next=top;
//     top=newNode;
//     cout<<val<<"pushed"<<endl;
// }