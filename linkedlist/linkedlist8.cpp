// A program to merge two sorted linked list
// insertion of element is done at first position
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node *next;
    
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *head3 = NULL;
void insert(struct Node **head,int x){
    // allocating memory for the node
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    // inserting x in the tmp node
    tmp->data = x;
    // in first iteration, tmp->next will be pointing to NULL
    tmp->next = *head;
    // head is pointing to the list created till now
    *head = tmp;
}
void print(struct Node **head){
    struct Node *ptr = *head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}
void mergeTwoSortedLinkedList(struct Node *list1, struct Node *list2){
    while(list1!=NULL && list2!=NULL){
        if(list1->data >= list2->data){
            insert(&head3,list1->data);
            list1 = list1->next;
        }else if(list1->data < list2->data){
            insert(&head3,list2->data);
            list2 = list2->next;
        }
    }
    if(list1==NULL){
        while(list2!=NULL){
            insert(&head3,list2->data);
            list2 = list2->next;
        }
    }else if(list2==NULL){
        while(list1!=NULL){
            insert(&head3,list1->data);
            list1 = list1->next;
        }
    }
    print(&head3);
    
};
int main() {
	insert(&head1,1); // head1->1->NULL
	insert(&head1,3); // head1->2->1->NULL
	insert(&head1,4); // head1->3->2->1->NULL
	insert(&head1,6); // head1->4->3->2->1->NULL
	insert(&head1,8); // head1->5->4->3->2->1->NULL
	print(&head1);
    insert(&head2,2); // head2->9->NULL
    insert(&head2,5); // head2->9->9->NULL
    insert(&head2,7); // head2->6->9->9->NULL
    cout<<endl;
    print(&head2);
    cout<<endl;
    mergeTwoSortedLinkedList(head1,head2);
	return 0;
}

