#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class Graph {
	public:
	vector<vector<int>> edges;
	vector<vector<int>> adjacencyList;
	int nodes;
	Graph(int n) {
		nodes = n;
	}
	void addEdge(int x, int y) {
		vector<int> edge = {x, y};
		edges.push_back({x, y});
	}
	
	void prints() {
		for(int i = 0; i < edges.size(); i++) {
			cout<<edges[i][0] << " " << edges[i][1]<<endl;
		}
	}
	
	vector<vector<int>> getAdjacencyList() {
		vector<vector<int>> adjList(nodes+1);
		for(int i = 0; i<edges.size(); i++) {
			adjList[edges[i][0]].push_back(edges[i][1]);
			adjList[edges[i][1]].push_back(edges[i][0]);
		}
		adjacencyList = adjList;
		return adjList;
	}
	
	void BFS(int s) {
		
	queue<int> q;
	
	q.push(s);
	vector<bool> visited(nodes+1,false) ;
	
	while(!q.empty()) {
		int x = q.front();
		cout << x << " ";
		visited[x] = true;
		q.pop();
		if(adjacencyList.at(x).size() > 0) {
			for(int i = 0; i<adjacencyList.at(x).size(); i++) {
				if(!visited[adjacencyList.at(x).at(i)]){
				q.push(adjacencyList.at(x).at(i));
				visited[adjacencyList.at(x).at(i)] = true;
				}
			}
		}
	}
	}
	
	void dfsHelper(int s, vector<int>& visited) {
		cout<<s<< " ";
		visited[s] = true;
		if(adjacencyList.at(s).size() > 0) {
			for(int i = 0; i<adjacencyList.at(s).size(); i++){
				if(!visited[adjacencyList.at(s).at(i)]) {
					dfsHelper(adjacencyList.at(s).at(i), visited);
				}
			}
		}
	}
	
	void DFS(int s) {
		vector<int> visited(nodes+1, false);
		dfsHelper(s, visited);
	}
};

int main() {
	Graph g(7);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,6);
	g.addEdge(3,6);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,7);
	
	vector<vector<int>> adjList = g.getAdjacencyList();
	
	// for(int i=0; i< adjList.size();i++) {
	// 	cout<<i<<"->";
	// 	for(int j=0; j<adjList.at(i).size(); j++) {
	// 		cout<<adjList.at(i).at(j)<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	g.BFS(2);
	cout<<"\n";		
	
	g.DFS(2);
 	// your code goes here
	return 0;
}
