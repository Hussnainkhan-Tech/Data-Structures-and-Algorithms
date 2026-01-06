#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class list{
    private:
    node* head;
    node* tail;
    public:
    list(){
        head=tail=NULL;
    }
    void push_front(int val){
        node* newNode=new Node(val);
    }
    if(head==NULL){
        head=tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
    void show(){
         node*temp=head;
         while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
         }
         cout<<endl;
    }
};
int main(){
    list s;
    s.push_front(1);
    s.push_front(2);
    s.push_front(3);
    s.push_front(4);
    s.show();
    return 0;

}