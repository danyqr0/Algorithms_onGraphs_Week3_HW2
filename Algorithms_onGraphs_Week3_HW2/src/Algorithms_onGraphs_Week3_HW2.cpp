//============================================================================
// Name        : Algorithms_onGraphs_Week3_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW3_Week2
// Description : Checking whether a graph is bipartite in C++
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::vector;
using std::queue;

//global variables
int n,m;
queue <int> g_queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int>::iterator it;int u;
  vector<bool> visited (n,false);
  vector<int> partition (n,0);
  partition[0]=1;
  visited[0]=true;
  g_queue.push(0);
  while(!g_queue.empty()){
	  u=g_queue.front();g_queue.pop();
	  for(it=adj[u].begin();it!=adj[u].end();it++){
		  if(partition[*it]==partition[u]) return 0;
		  if(!visited[*it]){
			  visited[*it]=true;
			  partition[*it]=3-partition[u];
			  g_queue.push(*it);
		  }
	  }
  }

  return 1;
}


int main() {
	cin >> n >> m;
	if( (n>=2 && n<=1e5) && (m>=0 && m<=1e5) ){
		vector<vector<int> > adj(n, vector<int>());
			for (int i = 0; i < m; i++) {
				int x, y;
				cin >> x >> y;
				adj[x - 1].push_back(y - 1);
				adj[y - 1].push_back(x - 1);
			}
		cout << bipartite(adj);
	}
	return 0;
}
