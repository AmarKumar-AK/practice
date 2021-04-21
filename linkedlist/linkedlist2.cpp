// A program to create a linked list
// insertion of element is done at last position
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
    
};
struct Node *head = NULL;

void insert(int x){
    // allocating memory for the node
    struct Node *tmp = new struct Node;
    // inserting x in tmp and its next is pointing to NULL
    tmp->data = x;
    tmp->next = NULL;
    // if first element is inserted in linked list
    if(head == NULL){
        head = tmp;
    }
    else{ // if first element is already inserted
        // pointer pointing to the first element
        struct Node *last = head;
        // traversing to the last of the linked list and inserting tmp there
        while(last->next!=NULL){
            last = last->next;
        }
        last->next=tmp;
    }
}

void print(){
    struct Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}

int main() {
	insert(10); // head->10->NULL
	insert(20); // head->10->20->NULL
	insert(30); // head->10->20->30->NULL
	insert(40); // head->10->20->30->40->NULL
	insert(50); // head->10->20->30->40->50->NULL
	print();
	return 0;
}


