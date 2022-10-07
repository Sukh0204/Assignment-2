// a) Create a singly linked list. Perform Insertion of an element after a Specified Value
// (given by the user at run time)

#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(){
        data = 0;
        next = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void printLL(node* head){
   while(head!=NULL){
     cout<<head->data<<" ";
     head = head->next;
   }
   cout<<endl;
}
void insertElement(node* head, int val, int pos){
    node* newVal = new node(val);
     while(head!=NULL){
        if(head->next == NULL && head->data!= pos){
            cout<<"Invalid value provided"<<endl;
        }
        if(head->data == pos){
            node* temp = head->next;
            head->next = newVal;
            newVal->next = temp;
            break;
        }
        head = head->next;
     }
}
int main(){
   //2->4->8->16
    node* n1 = new node(2);
    node* n2 = new node(4);
    node* n3 = new node(8);
    node* n4 = new node(16);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout<<"Before insertion the Singly Linked List is: ";
    printLL(n1);
    int val;
    cout<<"Enter data to be added"<<endl;
    cin>>val;
    int pos;
    cout<<"Enter value after which to add"<<endl;
    cin>>pos;
    insertElement(n1, val, pos);
    cout<<"After insertion the Singly Linked List is: ";
    printLL(n1);
    return 0;
}