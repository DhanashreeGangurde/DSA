#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string getpath(vector<int> paths,int source,int dest)
{
	string path,nodes;
	
	int currVertex = dest;
	while(currVertex != source)
	{
		nodes = to_string(paths[currVertex]) + nodes;
		
		currVertex = paths[currVertex];
	}
	for(char node:nodes)
	{
		path += node;
		path += " - ";
	}
	
	path += to_string(dest);
	return path;
}

int main()
{
	int numVertices = 5;
	int source = 1;
	
	vector<pair<int,int>>graph[numVertices + 1];
	
	graph[1].push_back({2,2});
	graph[1].push_back({4,1});
	
	graph[2].push_back({1,2});
	graph[2].push_back({5,5});
	graph[2].push_back({3,4});
	
	graph[3].push_back({2,4});
	graph[3].push_back({4,3});
	graph[3].push_back({5,1});
	
	graph[4].push_back({1,1});
	graph[4].push_back({3,3});
	
	graph[5].push_back({2,5});
	graph[5].push_back({3,1});
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	
	vector<int>paths(numVertices + 1,source);
	
	vector<int>distTo(numVertices + 1,INT_MAX);
	distTo[source]=0;
	
	pq.push(make_pair(0,source));
	
	while(!pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		for(auto edge : graph[prev])
		{
			int next = edge.first;
			int nextDist = edge.second;
			cout<<"comparing form "<<prev<<" to "<<next<<" ---> distance : "<<distTo[next]<<" and "<<dist + nextDist<<endl;
			
			if(distTo[next]>dist + nextDist)
			{
				cout<<"FOUND SHORTER PATH "<<endl;
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next],next));
				
				paths[next] = prev;
			}
		}
	}
	cout<<endl;
	cout<<"the distance  from source "<<source<<" are : "<<endl;
	for(int dest = 1;dest<=numVertices;dest++)
	{
		cout<<source<<" ---> "<<dest<<" Distance "<<distTo[dest];
		cout<<" path : "<<getpath(paths,source,dest)<<endl;
	}
	return 0;
}