#include <iostream>
using namespace std;


// Creating Node
class Node{
public:

    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};



class List{
    Node* head;
    Node* tail;

public:

    List(){
        head = tail = NULL;
    }

    // PUSH FRONT
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }




    // PUSH BACK

    void push_back(int val){
        Node* newNode = new Node(val);
       if(head == NULL){
          head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;

    }




    // POP FRONT

    void pop_front(){
       if(head == NULL){
           cout<<"Linked List empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        if(head==NULL)
            tail=NULL;

    }

    // POP BACK

    void pop_back(){
        if(head==NULL){
           cout<<"Linked List empty\n";
            return;
        }


        // only one node

        if(head==tail){
          delete head;
            head=tail=NULL;
            return;
        }



        Node* temp=head;
        while(temp->next != tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;

    }




    // INSERT

    void insert(int val,int pos){
        if(pos<0){
           cout<<"Invalid position\n";
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }



        Node* temp=head;
       for(int i=0;i<pos-1;i++){
            if(temp==NULL){
               cout<<"Invalid position\n";
                return;
            }
           temp=temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next==NULL)
            tail=newNode;

    }

    // SEARCH

    int Search(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
           idx++;
        }
        return -1;
    }

    // PRINT
      void printLL(){
      Node* temp=head;
        while(temp!=NULL){
           cout<<temp->data<<" ";
           temp=temp->next;
       }
        cout<<endl;
    }
};



int main(){
    List ll;


    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);


    ll.push_back(40);
    ll.push_back(50);



    ll.printLL();



    ll.pop_front();


    ll.printLL();



    ll.pop_back();


    ll.printLL();



    ll.insert(100,2);


    ll.printLL();



    cout<<"Index: "<<ll.Search(100)<<endl;



    return 0;
}