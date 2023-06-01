#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisJointSet
{
	int *parent;
	
	public:
		DisJointSet(int n)
		{
			parent = new int[n];
			
			for(int i=0;i<n;i++)
			{
				parent[i]=i;
			}
		}
		
		int find(int i)
		{
			if(parent[i]==i)
			{
				return i;
			}
			return parent[i] = find(parent[i]);
		}
		
		void unite(int x,int y)
		{
			int s1 = find(x);
			int s2 = find(y);
			
			if(s1 != s2)
			{
				parent[s2] = s1;
			}
		}
};

class Graph
{
	vector<vector<int>>edgelist;
	int v;
	
	public:
		Graph(int v)
		{
			this->v=v;
		}
		void addedge(int x,int y,int w)
		{
			edgelist.push_back({w,x,y});
		}
		
		void kruskalsalgo()
		{
			sort(edgelist.begin(),edgelist.end());
			DisJointSet s(v);
			int ans = 0;
			cout<<endl;
			cout<<" following are the edges in the minimum spanning tree "<<endl;
			cout<<endl;
			
			for(auto edge : edgelist)
			{
				int weight = edge[0];
				int firstvertex = edge[1];
				int secondvertex = edge[2];
				
				if(s.find(firstvertex) != s.find(secondvertex))
				{
					ans += weight;
					s.unite(firstvertex,secondvertex);
					cout<<firstvertex<<" - "<<secondvertex<<" : "<<weight<<endl;
				}
			}
			cout<<endl;
			cout<<"minimum cost spanning tree : "<<ans<<endl<<endl;
		}
};
int main()
{
	Graph graph(6);
	graph.addedge(0,1,4);
	graph.addedge(0,2,4);
	graph.addedge(1,2,2);
	graph.addedge(2,3,3);
	graph.addedge(2,4,2);
	graph.addedge(2,5,4);
	graph.addedge(3,5,3);
	graph.addedge(4,5,3);
	
	graph.kruskalsalgo();
}