#include <iostream>
#include <vector>

using namespace std;


struct Node {
	int inc;
	int notInc;
	int col;
};

vector<int> *adj;
Node *myNode;

int mini(int a, int b) {
	return (a<b)?a:b;
}

void dfs(int s) {
	if(adj[s].size() == 1) {
		myNode[s].col = 2;
		myNode[s].inc = 1;
		myNode[s].notInc = 0;
		return;
	}

	myNode[s].col = 1;
	int incl = 0, notincl = 0;
	for(int i = 0; i < adj[s].size(); ++i) {
		if(myNode[adj[s][i]].col == 0) {
			dfs(adj[s][i]);
		}
	}

	for(int i = 0; i < adj[s].size(); ++i) {
		if(myNode[adj[s][i]].col == 2) {
			incl+=mini(myNode[adj[s][i]].inc, myNode[adj[s][i]].notInc);
			notincl+=myNode[adj[s][i]].inc;
		}
	}
	myNode[s].inc = incl+1;
	myNode[s].notInc = notincl;
	myNode[s].col = 2;
}


int main() {
	int n;
	cin >> n;
	adj = new vector<int>[n];
	myNode = new Node[n];
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	
	int root = 0;
	for(int i = 0; i < n; ++i) {
		if(adj[root].size() < adj[i].size())
			root = i;
		myNode[i].col = 0;
	}

	dfs(root);
	cout << mini(myNode[root].inc, myNode[root].notInc) << endl;

	return 0;
}
