// A program to create a linked list
// insertion of element is done at last position in O(1)
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
    
};
struct Node *head = NULL;
struct Node *last = NULL;

void insert(int x){
    // allocating memory for the node
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    // inserting x in tmp and its next is pointing to NULL
    tmp->data = x;
    tmp->next = NULL;
    // inserting first element, head and last pointer will be pointing to the first element
    if(head == NULL){
        head = tmp;
        last = tmp;
    }
    // inserting two or more node, head will be pointing to the first element,
    // while last pointer will be pointing to the last element inserted 
    else{
        last->next = tmp;
        last = last->next;
    }
}

void insertAtPosition(int x, int pos){
    struct Node *ptr = head;
    struct Node *prev = head;
    struct Node *tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;
    int cnt = 1;
    if(pos == 1){
        tmp->next = head;
        head = tmp;
    }else{
        while(cnt!=pos){
            prev = ptr;
            ptr = ptr->next;
            cnt++;
        }
        tmp->next = ptr;
        prev->next = tmp;
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
    insertAtPosition(25,7);
    cout<<endl;
    print();
	return 0;
}
