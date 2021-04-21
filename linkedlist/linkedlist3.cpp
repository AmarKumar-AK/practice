// A program to create a linked list and then reverse it
// insertion of element is done at first position
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
    
};
struct Node *head = NULL;

void insert(int x){
    // allocating memory for the node
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    // inserting x in the tmp node
    tmp->data = x;
    // in first iteration, tmp->next will be pointing to NULL
    tmp->next = head;
    // head is pointing to the list created till now
    head = tmp;
}

void print(){
    struct Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}
void reverse(){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while(current!=NULL){
        // Store next so that current can be moved further as 
        // the link from current to next is breaking after reversing current node's pointer
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // in further iterations, prev should be current and current should be next
        prev = current;
        current = next;
    }
    // at the end prev will be pointing to the first element of the linked list after reversing
    head = prev;
}


int main() {
	insert(10); // head->10->NULL
	insert(20); // head->20->10->NULL
	insert(30); // head->30->20->10->NULL
	insert(40); // head->40->30->20->10->NULL
	insert(50); // head->50->40->30->20->10->NULL
	print();
    reverse();
    cout<<endl;
    print();
	return 0;
}

