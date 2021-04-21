#include <bits/stdc++.h>
using namespace std;


class List{
    
    private:
    struct Node{
    int data;
    struct Node *next;
        
    };
    struct Node *head = NULL;
    struct Node *last = NULL;
    public:
    void append(int x){
        // inserting in the first position
        struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
        tmp->data = x;
        tmp->next = NULL;
        last->next = tmp;
        last = last->next;
    }
    void print(){
        struct Node *ptr = head->next;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
    }
    
};
List::List(){
        struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
        tmp->data = 666;
        tmp->next = NULL;
        head = tmp;
        last = tmp;
        
    }

// void insert(int x);
// void print();
// void reverse();


int main() {
    List l1 = new List;
	// insert(10);
	// insert(20);
	// insert(30);
	// insert(40);
	// insert(50);
	// print();
	return 0;
}

// void insert(int x){
//     // inserting in the last position in O(1)
//     struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
//     if(head == NULL){
//         tmp->data = x;
//         tmp->next = NULL;
//         head = tmp;
//         last = tmp;
//     }
//     else{
//         tmp->data = x;
//         tmp->next = NULL;
//         last->next = tmp;
//         last = last->next;
//     }
// }

// void print(){
//     struct Node *ptr = head;
//     while(ptr!=NULL){
//         cout<<ptr->data<<"->";
//         ptr = ptr->next;
//     }
// }
// void reverse(){
    
// }