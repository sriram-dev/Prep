#include<iostream>
#include<vector>
using namespace std;

class Stack {
public:
	vector<int> stk;
	int top;
	Stack() {
		top = -1;
	}
	void push(int elem) {
		stk.push_back(elem);
		top++;
		cout<<"top:"<<top<<endl;
	}
	int pop() {
		int ret = stk[top];
		stk.erase(stk.begin() + top);
		top--;
		cout<<"Top pos:"<<top<<endl;
		return ret;
	}
	int peek() {
		return stk[top];
	}
	bool isEmpty() {
		if(top < 0)
			return true;
		else
			return false;
	}
};

Stack sort(Stack stk) {
	Stack temp;
	while(!stk.isEmpty()) {
		int ret = stk.pop();
		while(!temp.isEmpty()) {
			if(temp.peek() > ret)
				stk.push(temp.pop());
			else
				break;			
		}
		cout<<"stack top"<<stk.peek()<<endl;
		temp.push(ret);
	}
	return temp;
}

int main() {
	Stack stk;
	stk.push(4);
	stk.push(2);
	stk.push(3);
	Stack sorted = sort(stk);
	cout<<"pop:"<<sorted.pop()<<endl;
	cout<<"pop:"<<sorted.pop()<<endl;
}