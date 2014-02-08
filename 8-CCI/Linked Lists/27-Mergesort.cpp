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

void SplitList(Node **ref1, Node **ref2, Node *list) {
	Node *fast_ptr, *slow_ptr, *cur;
	fast_ptr = list->next;
	slow_ptr = list;
	while(fast_ptr != NULL) {		
		fast_ptr = fast_ptr->next;
		if(fast_ptr!= NULL) {
			fast_ptr = fast_ptr->next;
			slow_ptr = slow_ptr->next;
		}
	}
	*ref2 = slow_ptr->next;
	slow_ptr->next = NULL;
	*ref1 = list;
}

Node* Merge(Node *left, Node *right) {
	Node dummy;
	dummy.next = NULL;
	Node *tail = &dummy;
	while(left != NULL || right != NULL) {
		if(left == NULL) {
			MoveNode(&tail->next, &right);
		} else if(right == NULL) {
			MoveNode(&tail->next, &left);
		} else {
			if(left->data < right->data) {
				MoveNode(&tail->next, &left);
			} else {
				MoveNode(&tail->next, &right);
			}
		}
		tail = tail->next;
	}
	return dummy.next;
}

void Sort(Node **headref) {
	Node *left = NULL, *right = NULL;
	Node *head = *headref;
	if(head == NULL)
		return;
	if(head->next == NULL)
		return;
	cout<<"tosplit"<<endl;
	display(head);
	SplitList(&left, &right, head);
	cout<<"disp after split"<<endl;
	display(left);
	display(right);
	Sort(&left);
	Sort(&right);
	head = Merge(left, right);
	*headref = head;
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
	Sort(&head);
	cout<<"in main"<<endl;
	display(head);
}