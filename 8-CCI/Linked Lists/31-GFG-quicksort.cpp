#include<iostream>

using namespace std;



class Node {
public:
	int data;
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


void push(Node **headref, int data) {	
	Node temp1;
	temp1.next = NULL;
	Node *temp = new Node;
	temp->data = data;
	temp->next = (*headref);
	(*headref) = temp;
}


void partition(Node *left, Node *right, Node *newleft, Node *newright) {

}

Quicksort(Node *left, Node *right) {
	// partition the list from left to right . get the index of pivot 
	Node *newleft = NULL, *newright = NULL;
	Node *pivot =  partition(left, right, &newleft, &newright);
	if(left != right) {
		Node *tail = getTail(left, pivot);
		Quicksort(left, tail);
		Quicksort(pivot->next, right);
	}
}

int main() {
	Node *head = NULL;
	push(&head, 3);
	push(&head, 4);
	push(&head, 1);
	push(&head, 5);
	push(&head, 2);	
	Node *tail;
	Node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	tail = temp;
	Quicksort(&head, &tail);
}