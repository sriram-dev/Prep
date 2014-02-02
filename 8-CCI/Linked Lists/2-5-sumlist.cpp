#include<iostream>
#include<cmath>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int a ){
		data = a;
	}
};
void Display(Node *);

Node* create() {
	Node *list = NULL;
	int n, elem;
	cout<<"Enter n"<<endl;
	cin>>n;	
	for(int i=0;i<n;i++) {
		cin>>elem;
		if(list == NULL) {
			cout<<"null"<<endl;
			list = new Node(elem);
			list->next = NULL;
		} else {
			Node *temp;
			temp = new Node(elem);			
			temp->next = list;
			list = temp;
		}
	}
	return list;
}

int listadd(Node *l1, Node *l2) {
	int sum = 0;
	int carry = 0;
	Node *res;
	Node *temp;
	temp = res;
	while(l1 != NULL || l2 != NULL ){
		carry = 0;
		if(temp == NULL) {
			temp = new Node(0);
			temp->next = NULL;				
		} 
		if(res == NULL)
			res = temp;
		if(l1 == NULL) {			
			temp->data = l2->data;
			l2 = l2->next;
		} else if(l2 == NULL) {
			temp->data = l1->data;
			l1 = l1->next;
		} else {
			int r = l1->data + l2->data + carry;
			if(r > 9) {
				carry = (r/10)%10;
				temp->data= r%10;				
			} else {
				temp->data = r;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		cout<<"added data as "<<temp->data<<endl;
		temp = temp->next;
	}
	cout<<"calling disp"<<endl;
	cout<<"carry:"<<carry<<endl;
	temp = res;
	while(temp->next != NULL)
		temp = temp->next;
	if(carry != 0) {
		temp->next = new Node(carry);
		temp->next->next = NULL;
	}
	Display(res);
	int incr = 0;
	temp = res;
	while(temp != NULL) {
		sum += (temp->data * pow(10, incr));
		incr++;
		temp = temp->next;
	}
	return sum;
}

void Display(Node *l) {
	while(l != NULL) {
		cout<<l->data<<"-->";
		l = l->next;
	}
	cout<<endl;
}

int main() {
	Node* l1 = create();
	Node* l2 = create();
	//Display(l1);
	//Display(l2);
	cout<<"res:"<<listadd(l1,l2);
}