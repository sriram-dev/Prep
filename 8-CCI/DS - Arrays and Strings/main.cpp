#include<iostream>
#include<string>
using namespace std;
bool areUniqueChars(char *str);
char* reverseString(char *str);

int main() {
	cout<<"Testing solutions"<<endl;
	char str[4] = "asd";
	cout<<"Test1 -- \n Expected: Yes \n Actual: "<<endl;
	if(areUniqueChars(str))
		cout<<"Yes";
	else
		cout<<"No";
	cout<<"\n Test Case 2"<<endl;
	cout<<"Reverse :"<<reverseString(str)<<endl;
}

int strlen(char *str) {
	int len = 0;
	char *p = str;
		while(*p != '\0'){
			len++;
			p++;
	}
	return len;
}

// 1.
bool areUniqueChars(char *str) {
	bool uniq = true;
	int len = 0;
	char *p = str;
	while(*p != '\0'){
		len++;
		p++;
	}
	cout<<"Len"<<len<<endl;
	for(int i=0;i<len;i++) {
		char c = str[i];
		for(int j=i+1;j<len;j++) {
			if(str[j] == c) {
				uniq = false;
				break;
			}

		}
	}
	return uniq;
}

char* reverseString(char *str) {
	int len = strlen(str);
	cout<<"len"<<len<<endl;
	int itrf = 0, itrl = len-1;
	while(itrf < itrl) {
		cout<<"itrf:"<<itrf<<" itrl"<<itrl<<endl;
		if(itrf != itrl) {
			char c = str[itrf];
			str[itrf] = str[itrl];
			str[itrl] = c;
		}
		itrf++;
		itrl--;
	}
	return str;
}


bool isPermutation(char *str1, char *str2) {
	bool res = true;
	int len1 = strlen(str1), len2 = strlen(str2);

}

