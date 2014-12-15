#include <iostream>
#include <climits>
#include <queue>

using namespace std;

#define INFINITY INT_MAX

struct AdjListNode {
	int dest;
	AdjListNode *next;
	int weight;
};

struct AdjList {
	AdjListNode *head;
	int dist;
	AdjList *parent;
	int parentVal;
};

class Graph {
	int V;
	AdjList *array;
	bool directed;
public:
	Graph(int x, bool y) {
		V = x;
		directed = y;
		array = new AdjList[x];
		for(int i = 0; i < x; ++i) {
			array[i].head = NULL;
		}
	}
	void addEdge(int x, int y, int w) {
		AdjListNode *node = new AdjListNode[1];
		node->dest = y;
		node->weight = w;
		node->next = array[x].head;
		array[x].head = node;
		if(!directed) {
			AdjListNode *node1 = new AdjListNode[1];
			node1->dest = x;
			node1->weight = w;
			node1->next = array[y].head;
			array[y].head = node1;
		}
	}
	void initialize(int src) {
		for(int i = 0; i < V; ++i) {
			array[i].dist = INFINITY;
		}
		array[src].dist = 0;
	}
	void relax(int u, int v, int w) {
		if(array[v].dist > array[u].dist + w) {
			array[v].dist = array[u].dist + w;
		}
	}
	bool bellManFord(int src) {
		initialize(src);
		for(int k = 0; k < V; ++k) {
			for(int i = 0; i < V; ++i) {
				AdjListNode *node = array[i].head;
				while(node != NULL) {
					relax(i, node->dest, node->weight);
					node = node->next;
				}
			}
		}
		for(int i = 0; i < V; ++i) {
			AdjListNode *node = array[i].head;
			while(node != NULL) {
				if(array[node->dest].dist > array[i].dist + node->weight)
					return false;
				node = node->next;
			}
		}
		return true;
	}
	void dijkstra(int src) {
		
	}

	int findSP1(int src, int dest) {
		//check if connected
		int *flag = new int[V];
		for(int i = 0; i < V; ++i) 
			flag[i] = 0;
		flag[src] = 1;
		queue<int> Q;
		Q.push(src);
		while(!Q.empty()) {
			int x = Q.front();
			Q.pop();
			AdjListNode *node = array[x].head;
			while(node != NULL) {
				if(flag[node->dest] == 0) {
					Q.push(node->dest);
					flag[node->dest] = 1;
				}
				node = node->next;
			}
			flag[x] = 2;
		}
		if(flag[dest] != 2)
			return -1;
		if(bellManFord(src))
			return array[dest].dist;
		else
			return -1;
	}

};

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i) {
		int n, m, src, dest;
		cin >> n >> m >> src >> dest;
		Graph graph(n, false);
		for(int j = 0; j < m; ++j) {
			int x, y, w;
			cin >> x >> y >> w;
			graph.addEdge(x-1, y-1, w);
		}
		int dist = graph.findSP1(src-1, dest-1);
		if(dist == INFINITY || dist < 0)
			cout << "NONE" << endl;
		else
			cout << dist << endl;
	}
	return 0;
}
