#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
#define vi vector<int>

// 1. Create Tree
void create(vi &segtree, int n) {
	int len = 2 * pow(2, floor(log(n)) + 1);
	cout<<"Len:"<<len<<endl;
	segtree.assign(len, 0);
}

// 2 Build Tree
void build(vi &segtree, int l, int r, int v, vi A) {
	if(l == r) {
		segtree[v] = l;
		return;
	}
	cout<<"l:"<<l<<"r:"<<r<<endl;
	build(segtree, l, ((l+r)/2), 2 *v , A);
	build(segtree, ((l+r)/2)+1, r,  2*v + 1, A);
	int p1 = 2*v;
	int p2 = 2*v + 1;
	int lVal = segtree[p1], rVal = segtree[p2];
	if(A[lVal] <= A[rVal])
		segtree[v] = lVal;
	else
		segtree[v] = rVal;	
}

// 3 RMQ 
int rmq(vi &segtree, int l, int r, int from, int to, vi A, int v) {
	// check if it is inside the l and r 
	if( from >= l && to <= r)
		return segtree[v];
	// check out condition
	if(!(from >=l && from <= r) && !(to >= l && to <= r))
		return -1;
	int p1 = rmq(segtree, l, (l+r)/2, from, to, A, 2*v);
	int p2 = rmq(segtree, ((l+r)/2)+1, r, from, to, A, 2*v +1);
	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return p1;
	if(A[p1] > A[p2])
		return p2;
	else
		return p1;
}

int rmq(vi &segtree, vi A,int from, int to) {
	return rmq(segtree,0,A.size()-1,from, to, A, 1);
}


int main() {
	vi segtree;
	int a[] = {10,11,2,5,8,1};
	vi A(a, a+6);
	create(segtree, 6);
	build(segtree, 0, 5,1,A);
	cout<<"rmq(1,5)" <<rmq(segtree,A,1,5)<<endl;
	for(int i=0;i<8;i++) 
		cout<<segtree[i]<<"\t";
}