#include<bits/stdc++.h>
using namespace std;

class Graph
{
	private:
		int **adjmatrix;
		int numvertices;
	public:
		Graph(int numvertices)
		{
			this->numvertices = numvertices;
			adjmatrix = new int*[numvertices];
			for(int i=0;i<numvertices;i++)
			{
				adjmatrix[i] = new int[numvertices];
				for(int j=0;j<numvertices;j++)
				{
					adjmatrix[i][j]=0;
				}
			}
		}
		
		void addedge(int var1,int var2,int weight)
		{
			adjmatrix[var1][var2]=weight;
			adjmatrix[var2][var1]=weight;
		}
		
		void removeedge(int var1,int var2)
		{
			adjmatrix[var1][var2]=0;
			adjmatrix[var2][var1]=0;
		}
		
		void primsAlgo()
		{
			int selected[numvertices];
			memset(selected,false,sizeof(selected));
			selected[0]=true;
			int totalweight = 0;
			cout<<"edge : weight "<<endl;
			
			for(int edgeno=0;edgeno<numvertices-1;edgeno++)
			{
				int min = INT_MAX;
				int x;
				int y;
				
				for(int i=0;i<numvertices;i++)
				{
					if(selected[i])
					{
						for(int j=0;j<numvertices;j++)
						{
							if(!selected[j] != 0 && adjmatrix[i][j] !=0)
							{
								if(min>adjmatrix[i][j])
								{
									min = adjmatrix[i][j];
									x = i;
									y = j;
								}
							}
						}
					}
				}
				cout<<x<<" - "<<y<<" : "<<adjmatrix[x][y]<<endl;
				selected[y]=true;
				totalweight += adjmatrix[x][y];
			}
			cout<<endl<<"total weight of minimum spanning tree : "<<totalweight<<endl;
		}
		
		void ptint()
		{
			for(int i=0;i<numvertices;i++)
			{
				cout<<i<<" : ";
				for(int j=0;j<numvertices;j++)
				{
					cout<<adjmatrix[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
		~Graph()
		{
			for(int i=0;i<numvertices;i++)
			{
				delete[] adjmatrix[i];
				delete[] adjmatrix;
			}
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
	
	graph.primsAlgo();
}