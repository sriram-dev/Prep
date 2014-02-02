#include<iostream>
#include<vector>
using namespace std;

class Stack {
public:
	vector<int> st;
	int tope;
	Stack() {
		cout<<"in constructor"<<endl;
		tope = -1;
	}
	void push(int elem) {
		st.push_back(elem);
		tope++;
		//cout<<"top of stack at "<<tope<<endl;
	}
	int pop() {
		return st[tope--];
		//cout<<"top of stack at "<<tope<<endl;
	}
	int top() {
		cout<<"top of stack at "<<tope<<endl;
		return st[tope];
	}
	int isempty() {
		if(tope < 0)
			return 1;
		else
			return 0;
	}
};


class Queue {
public:
	Stack st1, st2;
	void push_back(int elem) {
		// empty st1 contents to st2
		// push new elem into st1
		// empty st2 contents to st1
		cout<<"-- PUSH " <<elem<<endl;		
		st1.push(elem);
	}

	int pop_front() {
		// pop first elem from st1
		while(!st1.isempty()) {
			st2.push(st1.pop());
		}
		int ret = st2.pop();
		while(!st2.isempty()) {
			st1.push(st2.pop());
		}
		return ret;
	}
};

int main() {
	Queue myq;
	myq.push_back(1);
	myq.push_back(2);
	myq.push_back(4);
	myq.push_back(5);
	cout<<"pop:"<<myq.pop_front();
	cout<<"pop:"<<myq.pop_front();
}