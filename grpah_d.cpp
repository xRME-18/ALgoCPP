#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <pair<int,int>> v[], int src, int dest, int wt)
{
	v[src].push_back({dest, wt});
	v[dest].push_back({src, wt});
}

void solve(vector<pair<int,int>> v[], int n, int x)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<int> e(n, INT_MAX), z(n, 0);
	
	e[x] = 0;
	q.push({0, x});
	
	while(!q.empty())
	{
		int a = q.top().second;
		q.pop();
		
		if(z[a])
		    continue;
		
		z[a] = 1;
		
		for(auto b : v[a])
		{
			if(e[a] + b.second < e[b.first])
			{
				e[b.first] = e[a] + b.second;
				q.push({e[b.first], b.first});
			}
		}
	}
	
	cout << "\n Vertex \t Distance from Source \n \n";
	for (int i=0; i<n; i++)
		cout << " " << i << "\t \t \t" << e[i] << endl;
}

int main()
{
	int n = 5;
	vector<pair<int,int>> v[n];
	addEdge(v, 0, 1, 5);
	addEdge(v, 0, 4, 1);
	addEdge(v, 0, 3, 9);
	addEdge(v, 1, 2, 2);
	addEdge(v, 2, 3, 6);
	addEdge(v, 3, 4, 2);
	solve(v, n, 0);
}
