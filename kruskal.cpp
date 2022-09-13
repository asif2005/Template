#include<bits/stdc++.h>
using namespace std;

const int MX=1e5;

// This is the code of kruskal algorithm using dsu

vector<int>par(MX);  // this is for dsu
vector<int>sz(MX);   

// from here dsu code start____------______


// this  function is for making set
void make(int v){
	par[v]=v;
	sz[v]=1;
}

// this is for finding parent 
int find(int v){
	if(par[v]==v)return v;
	return par[v]=find(par[v]);
}

// this is for Union a set
void Union(int a, int b){
	a =find(a);
	b=find(b);

	if(a!=b){
		if(sz[a]<sz[b]){
			swap(a,b);
		}
		par[b]=a;
		sz[a]+=sz[b];
	}
}


// here dsu codes end ____------_____


// here kruskal code start___=====_____


void solve(){

	int n,m; // variable for graph size
	cin>>n>>m;  // taking input the variables

	vector<pair<int,pair<int,int>>>edges; // this is for storing the graph using edge list


	// this loop is for taking input the edges
	for(int i =0;i<m;i++){
		int x,y,wt;
		edges.push_back({wt,{x,y}});
	}

	sort(edges.begin(),edges.end());  // sorting the edge list according to weight

	//this is loop is for creating sets;
	for(int i =1;i<=n;i++)make(i);

	int total = 0; // variable store the size of mst 
	

	// this is for finding the minimum spanning tree
	for(auto edge:edges){
		int wt =edge.first;
		int u = edge.second.first;
		int v= edge.second.second;

		if(find(u)==find(v))continue;

		Union(u,v);
		total+=wt;
	}

}

int main(){
	int t =1;
	// cin>>t;
	while(t--){
		solve();
	}
}
