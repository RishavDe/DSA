#include <iostream>
using namespace std;
class Node
{
    int vertex;
    Node* next;

};
class adjList
{
    int numVertices;
    Node** adjLists;

};
class Edge
{
        	private:
			int src,dest,weight;
			public:
        	friend bool operator>(const Edge&,const Edge&);
        	friend bool operator<(const Edge&,const Edge&);
        	friend bool operator==(const Edge&,const Edge&);
        	friend bool operator!=(const Edge&,const Edge&);
        	friend bool operator>=(const Edge&,const Edge&);
        	friend bool operator<=(const Edge&,const Edge&);
        	friend class Graph;
        	friend istream& operator>>(istream &in,Edge& e);
};
class Graph
{
			int V;
			adjList *array;
        	public:
        	Graph(int V=0);
        	Graph(const Graph&);
        	void addEdge(Edge edge);
        	void removeEdge(Edge edge);
        	void DFS() const;
        	void BFS() const;
        	bool checkCycle() const;
        	Graph kruskal() const;
        	Graph Prim() const;
};
 
 

