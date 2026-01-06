#include<iostream>
using namespace std;
class S_node{
public:
    int data;
    S_node* next;
    S_node(int val){
        data = val;
        next = NULL;
    }
};
class S_list{
private:
    S_node* head;
    S_node* tail;
public:
    S_list(){
        head = tail = NULL;
        push_back(10);
        push_back(15); 
        push_back(20); 
        push_back(25); 
        push_back(30);
    }
    void push_front(int val){
        S_node* newNode = new S_node(val);
        if(head==NULL){
         head=tail=newNode;
        }
        else
        {
         newNode->next=head;
         head=newNode;
             }
    }

    void push_back(int val){
        S_node* newNode = new S_node(val);
        if(head==NULL) {
            head=tail=newNode;
        }
        else{ 
            tail->next=newNode;
             tail=newNode; 
        }
    }
    void pop_front(){
        if(head==NULL){ 
            return;
        }
        S_node* temp = head;
        head = head->next;
        delete temp;
        // if(head==NULL) tail=NULL;
    }

    void pop_back(){
        if(head==NULL){
         return;
    }
        if(head==tail){
             delete head; 
             head=tail=NULL; 
             return;}
        S_node* temp = head;
        while(temp->next!=tail){
             temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
    }

    void insert(int pos, int val){
        if(pos<0) {
            return;
        }
        if(pos==0){ 
            push_front(val);
             return;
             }
        S_node* temp=head;
        for(int i=0;i<pos-1 && temp!=NULL;i++) {
            temp=temp->next;
        }
        if(temp==NULL)
        { cout<<"Invalid Position\n";
             return;
             }
        S_node* newNode=new S_node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        // if(temp==tail) tail=newNode;
    }

    void show(){
        S_node* temp=head;
        while(temp!=NULL){
             cout<<temp->data<<"->"; temp=temp->next; 
            }
        cout<<"NULL"<<endl;
    }
};

// ===== DOUBLY LINKED LIST =====
class D_node{
public:
    int data;
    D_node* next;
    D_node* prev;
    D_node(int val){ 
        data=val; 
        next=NULL;
        prev=NULL;
     }
};
class D_list{
private:
    D_node* head;
    D_node* tail;
public:
    D_list(){
        head=tail=NULL;
        push_back(1); 
        push_back(2);
        push_back(3);
        push_back(4); 
        push_back(5);
    }

    void push_front(int val){
        D_node* newNode=new D_node(val);
        if(head==NULL){
             head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode; }
    }
    void push_back(int val){
        D_node* newNode=new D_node(val);
        if(head==NULL){
             head=tail=newNode;
        }
        else{ 
            tail->next=newNode;
             newNode->prev=tail;
              tail=newNode;
             }
    }

    void pop_front(){
        if(head==NULL) {
            return;
        }
        D_node* temp=head; 
            head=head->next;
             head->prev=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL) {
            return;
        }
        D_node* temp=tail;
        if(head==tail){
             head=tail=NULL;
        }
        else{ 
            tail=tail->prev; 
            tail->next=NULL;
         }
        delete temp;
    }

    void insert(int pos,int val){
        if(pos<0) {
            return;
        }
        if(pos==0){
             push_front(val);
              return; 
            }
        D_node* temp=head;
        for(int i=0;i<pos-1 && temp!=NULL;i++) {
            temp=temp->next;
        }
        if(temp==NULL){ 
            cout<<"Invalid Position";
             return;
            }
        D_node* newNode=new D_node(val);
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL) {
            temp->next->prev=newNode;
        }
        temp->next=newNode;
        if(newNode->next==NULL) tail=newNode;
    }

    void show(){
        D_node* temp=head;
        while(temp!=NULL){
             cout<<temp->data<<"<=>";
              temp=temp->next; }
        cout<<"NULL"<<endl;
        }
    };


// ===== MAIN MENU =====
int main(){
    int m;
    cout<<"1. Singly Linked List"<<endl;
    cout<<"2. Doubly Linked List"<<endl;
     cout<<"Enter option: "<<endl;
    cin>>m;

    if(m==1){
        S_list s;
        int choice,val,pos;
        do{
            system("cls");
            s.show();
             cout<<endl;
            cout<<"--- Singly Linked List Menu ---\n";
            cout<<"1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Insert at Position\n0. Exit\n";
            cout<<"Enter choice: "; cin>>choice;

            switch(choice){
                case 1: 
                cout<<"Enter value: ";
                cin>>val;
                 s.push_front(val);
                 break;
                case 2:
                 cout<<"Enter value: "; 
                 cin>>val; 
                 s.push_back(val); 
                 break;
                case 3: 
                s.pop_front(); 
                break;
                case 4: 
                s.pop_back(); 
                break;
                case 5: 
                cout<<"Enter position: "; 
                cin>>pos; 
                cout<<"Enter value: "; 
                cin>>val; 
                s.insert(pos,val); 
                break;
                case 0: 
                cout<<"GOOD BYE\n"; 
                break;
                default: 
                cout<<"Invalid Choice\n";
            }
        }while(choice!=0);
    }
    else if(m==2){
        D_list d;
        int choice,val,pos;
        do{
            system("cls");
            d.show(); cout<<endl;
            cout<<"--- Doubly Linked List Menu ---\n";
            cout<<"1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Insert at Position\n0. Exit\n";
            cout<<"Enter choice: "; 
            cin>>choice;
            switch(choice){
                case 1: cout<<"Enter value: "; 
                cin>>val; 
                d.push_front(val); 
                break;
                case 2: 
                cout<<"Enter value: "; 
                cin>>val; 
                d.push_back(val); 
                break;
                case 3: 
                d.pop_front(); 
                break;
                case 4: 
                d.pop_back(); 
                break;
                case 5: 
                cout<<"Enter position: "; 
                cin>>pos; 
                cout<<"Enter value: "; 
                cin>>val; 
                d.insert(pos,val); 
                break;
                case 0: 
                cout<<"GOOD BYE\n"; 
                break;
                default: 
                cout<<"Invalid Choice\n";
            }
        }while(choice!=0);
    }
    else cout<<"Invalid Option!\n";

    return 0;
}
