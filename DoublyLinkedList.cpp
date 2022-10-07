// b) Create a doubly linked list. Perform Deletion of an element (given by the user at run time)
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;

    node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLL(node* head){
   while(head!=NULL){
     cout<<head->data<<" ";
     head = head->next;
   }
   cout<<endl;
}

node* deleteElement(node* head, int val){
    node* Mainhead = head;
    if(head->data == val){
        node* temp = head->next;
        temp->prev = NULL;
        Mainhead = temp;
    }
    else{
    while(head!=NULL){
        if(head->next == NULL && head->data != val){
            cout<<"Element does not exist in the list"<<endl;
        }
        if(head->next->data == val && head->next->next == NULL){
            head->next = NULL;
            break;
        }
        if(head->next->data == val){
             node* temp = head->next->next;
             head->next = temp;
             temp->prev = head;
             break;
        }
        head = head->next;
    }
    }
    return Mainhead;
}

int main(){
     //2 <=> 4 <=> 8 <=> 16
    node* n1 = new node(2);
    node* n2 = new node(4);
    node* n3 = new node(8);
    node* n4 = new node(16);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;

    cout<<"Before deletion, the Doubly Linked List is: ";
    printLL(n1);

    int val;
    cout<<"Enter data to be deleted"<<endl;
    cin>>val;

    node* head = deleteElement(n1, val);

    cout<<"After deletion the Doubly Linked List is: ";
    printLL(head);

    return 0;
}