#include <list>
#include <map>
#include <set>
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

/* Some defs to make life easy */
#define ii pair<int,int>
#define vii vector<ii>

class GraphLibs {
public:
	void AdjacencyMatrix() {
		int n;
		cout<<"enter n vertices :";
		cin>>n;
		/* initialize list to -1 */
		int adjMat[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				adjMat[i][j] = -1;
			}
		}
		cout<<"Enter edges with weights \n";
		for(int i=0;i<n;i++) {
			int from, to, weight;
			cin>>from>>to>>weight;
			adjMat[from][to] = weight;
			adjMat[to][from] = weight; // if its undirected graph
		}
		// Display Matrix
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<adjMat[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}

	void AdjacencyList() {
		vector<pair<int, vii> > adjList;
		int n;
		cout<<"Enter n edges :";
		cin>>n;
		for(int i=0;i<n;i++) {
			int from, to, weight;
			cin>>from>>to>>weight;
			bool found = false;
			for(int j=0;j<adjList.size();j++) {
				if(adjList[j].first == from) {
					found = true;
					break;
				}
			}
			if(found) {
				// list second contains the pairs of to and weight
				// list first is from edge
				adjList[from].second.push_back(make_pair(to, weight));
			} else {
				vii temp;
				temp.push_back(make_pair(to, weight));
				adjList.push_back(make_pair(from, temp));
			}
		}
		// Display List
		for(int i=0;i<adjList.size();i++) {
			cout<<adjList[i].first<<" --> \t";
			for(int j=0;j<adjList[i].second.size();j++) {
				cout<<"("<<adjList[i].second[j].first<<","<<adjList[i].second[j].second<<") \t";
			}
			cout<<"\n";
		}
	}

	
};
int main() {

	/* Stub to check graph usage */
	int opt;
	cout<<"Choose 1. Adj Matrix 2. Adj List \n";
	cin>>opt;
	GraphLibs libs;
	switch(opt) {
	case 1:
		libs.AdjacencyMatrix();
		break;	
	case 2:
		libs.AdjacencyList();
		break;	
	}
}
