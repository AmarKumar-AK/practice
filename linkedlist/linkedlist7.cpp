// A program to add two linked list
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
void addTwoLinkedList(struct Node *list1, struct Node *list2){
    int sum = 0;
    int carry = 0;
    // untill either of the list is empty, we will keep on getting value from both list and adding up their elements
    while(list1!=NULL && list2!=NULL){
        sum = (list1->data + list2->data + carry)%10;
        carry = (list1->data + list2->data + carry)/10;
        // cout<<sum<<" "<<carry<<endl;
        struct Node *tmp = new Node;
        tmp->data = sum;
        // in first iteration, tmp->next will be pointing to NULL
        tmp->next = head3;
        // head is pointing to the list created till now
        head3 = tmp;
        list1 = list1->next;
        list2 = list2->next;
    }
    // if list1 contains less element then add the list2 elements only along with carry
    if(list1==NULL){
        while(list2!=NULL){
            sum = (list2->data + carry)%10;
            carry = (list2->data + carry)/10;
            struct Node *tmp = new Node;
            tmp->data = sum;
            // in first iteration, tmp->next will be pointing to NULL
            tmp->next = head3;
            // head is pointing to the list created till now
            head3 = tmp;
            list2 = list2->next;
        }
    }
    // if list2 contains less element then add the list1 elements only along with carry
    else if(list2==NULL){
        while(list1!=NULL){
            sum = (list1->data + carry)%10;
            carry = (list1->data + carry)/10;
            struct Node *tmp = new Node;
            tmp->data = sum;
            // in first iteration, tmp->next will be pointing to NULL
            tmp->next = head3;
            // head is pointing to the list created till now
            head3 = tmp;
            list1 = list1->next;
        }
    }
    // if there is carry till the addition of last elements in both the list, then append carry to the resultant list
    if(carry){
        struct Node *tmp = new Node;
        tmp->data = sum;
        // in first iteration, tmp->next will be pointing to NULL
        tmp->next = head3;
        // head is pointing to the list created till now
        head3 = tmp;
    }
    print(&head3);
    
};
int main() {
	insert(&head1,1); // head1->1->NULL
	insert(&head1,2); // head1->2->1->NULL
	insert(&head1,5); // head1->3->2->1->NULL
	insert(&head1,2); // head1->4->3->2->1->NULL
	insert(&head1,7); // head1->5->4->3->2->1->NULL
	print(&head1);
    insert(&head2,9); // head2->9->NULL
    insert(&head2,1); // head2->9->9->NULL
    insert(&head2,6); // head2->6->9->9->NULL
    cout<<endl;
    print(&head2);
    cout<<endl;
    addTwoLinkedList(head1,head2);
	return 0;
}

