#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
private:
    node* head;
    node* tail;

public:
    list() {
        head = tail = NULL;


        push_back(10);
        push_back(15);
        push_back(20);
        push_back(25);
        push_back(30);
    }

    void push_front(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "EMPTY LIST\n";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "EMPTY LIST\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int pos, int val) {
        if (pos < 0) return;

        if (pos == 0) {
            push_front(val);
            return;
        }

        node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        node* newNode = new node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail)
            tail = newNode;
    }

    void show() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n"<<endl;
    }
};

int main() {
    list s;
    int choice, val, pos;

    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "CHOOSE THE OPTION: "<<endl;
    cin >> choice;

    if (choice == 1) {

        cout << "MY SINGLE LINK LIST VALUES"<<endl;
        s.show();

        do {
            system("cls"); 
            s.show();
            cout << "\nYOU CHOOSE SINGLY LINKED LIST\n";
            cout << "1. Push Front\n";
            cout << "2. Push Back\n";
            cout << "3. Pop Front\n";
            cout << "4. Pop Back\n";
            cout << "5. Insert at Position\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push_front(val);
                    s.show();
                    break;

                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    s.push_back(val);
                    s.show();

                    break;

                case 3:
                    s.pop_front();
                    s.show();
                    
                    break;

                case 4:
                    s.pop_back();
                    s.show();

                    break;

                case 5:
                    cout << "Enter position: ";
                    cin >> pos;
                    cout << "Enter value: ";
                    cin >> val;
                    s.insert(pos, val);
                    s.show();

                    break;
                case 0:
                    cout << "GOOD BYE\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
            }

        } while (choice != 0);
    }

    return 0;
}
