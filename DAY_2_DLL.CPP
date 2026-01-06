#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
        node(int val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};
    class D_list{
        private:
        node*head;
        node*tail;
            public:
            D_list(){
                head=tail=NULL;
            }
                void push_front(int val){
                    node*newNode=new node(val);
                    if(head==NULL){
                        head=tail=newNode;
                    }
                    else{
                        newNode->next=head;
                        head=newNode;
                    }
                }
                            void push_back(int val){
                                node*newNode=new node(val);
                            
                            if(head==NULL){
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
                                    node*temp=head;
                                    head=head->next;
                                    head->prev=NULL;
                                    temp->next=NULL;
                                    delete temp;

                                }
                                        void pop_back(){
                                            if(head==NULL){
                                                return;
                                            }
                                            node*temp=head;
                                            while(temp->next!=tail){
                                                temp=temp->next;
                                            }
                                            temp->next=NULL;
                                            tail->prev=NULL;
                                            tail=tail->prev;
                                            delete tail;

                                        }
                    void show(){
                        node*temp=head;
                        while(temp!=NULL){
                            cout<<temp->data<<"<=>";
                            temp=temp->next;
                        }
                        cout<<"NULL"<<endl;
                    }

    };
        int main(){
            D_list s;
            s.push_front(4);
            s.push_front(3);
            s.push_front(2);
            s.push_front(1);
            s.push_back(5);
            s.push_back(6);
            s.push_back(7);
            s.push_back(8);
            s.pop_front();
            s.pop_back();
            // s.pop_back();


            s.show();
            return 0;

        }