// A program to create a linked list
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
int main() {
	insert(10); // head->10->NULL
	insert(20); // head->20->10->NULL
	insert(30); // head->30->20->10->NULL
	insert(40); // head->40->30->20->10->NULL
	insert(50); // head->50->40->30->20->10->NULL
	print();
	return 0;
}

