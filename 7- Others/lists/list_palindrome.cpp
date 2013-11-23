#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	char c;
	struct node *next;
};
void reverse(struct node **headref);
bool CompareLists(struct node *temp1, struct node *temp2);
bool isPalindrome(struct node *head) {
	struct node *fast_ptr = NULL, *slow_ptr = NULL;
	struct node *mid_ptr = NULL;
	fast_ptr = slow_ptr = head;
	while(fast_ptr->next != NULL) {
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	if(fast_ptr != NULL) { // odd number of elems
		mid_ptr = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	//reverse slow_ptr and compare two lists
	reverse(&slow_ptr);	
	bool res = CompareLists(head, slow_ptr);
	reverse(&slow_ptr);
	return res;
}

/*Compare two lists */
bool CompareLists(struct node *temp1, struct node *temp2) {
	while(temp1 && temp2) {
		printf("Comparing %c and %c \n", temp1->c, temp2->c);
		if(temp1->c == temp2->c) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else {
			return false;
		}
	}
	return true;
}

/* Reverse List. Head reference changes */
void reverse(struct node **headref) {
	struct node *prev = NULL;
	struct node *current = *headref;
	struct node *next;
	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev =  current;
		current = next;
	}
	*headref = prev;
}

void Printlist(struct node *ptr) {
	printf("\n");
	while(ptr != NULL) {
		printf("%c -> ", ptr->c);
		ptr = ptr->next;
	}
}

void push(struct node **headref,char c) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->c = c;
	temp->next = *headref;
	*headref = temp;
}

int main() {
	char lst[] = { 'a', 'b', 'a','b','a','b','a'};
	struct node *head = NULL;
	for(int i=0;i<3;i++) {
		push(&head, lst[i]);
	}
	Printlist(head);
	//reverse(&head);
	//Printlist(head);
	if(isPalindrome(head))
		printf("YES");
	else
		printf("NO");
}