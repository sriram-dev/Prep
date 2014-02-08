#include<iostream>

using namespace std;
class Node {
public:
	int data;
	Node *next;
	Node(int a) {
		data = a;
	}
	Node() {

	}
};

void display(Node *temp) {
	while(temp != NULL) {
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

void MoveNode(Node **destref , Node **srcref) {
	Node *temp = (*srcref);
	(*srcref) = temp->next;
	temp->next = (*destref);
	(*destref) = temp;
}

void AlternateSplit(Node **ref1, Node **ref2, Node *head) {
	Node dummy1, dummy2;
	dummy1.next = NULL;
	dummy2.next = NULL;
	Node *tail1 = &dummy1;
	Node *tail2 = &dummy2;
	Node *cur = head;
	while(cur != NULL) {
		cout<<"in while loop"<<endl;
		MoveNode(&(tail1->next), &cur);
		cout<<"cur after one transfer"<<endl;
		display(cur);
		if(cur != NULL) {
			MoveNode(&(tail2->next), &cur);
			tail2 = tail2->next;
		}
		tail1= tail1->next;
		display(cur);
	}
	(*ref1) = dummy1.next;
	(*ref2) = dummy2.next;
}


void push(Node **headref, int data) {	
	Node temp1;
	temp1.next = NULL;
	Node *temp = new Node;
	temp->data = data;
	temp->next = (*headref);
	(*headref) = temp;
}



int main() {
	Node *head = NULL;
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	push(&head, 9);
	display(head);
	cout<<"in main after disp"<<endl;
	Node *l1 = NULL, *l2 = NULL;
	AlternateSplit(&l1, &l2, head);
	cout<<"in main"<<endl;
	display(l1);
	display(l2);
}