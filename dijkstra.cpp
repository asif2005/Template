#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5;

vector<pair<int,int>>graph[MX];// creating the graph vector 

vector<int>dist(MX,MX); // the vector for storing the shortest distance

vector<int>vis(MX,0); // the vector for checking the visited vertex



void dijkstra(int source){ // passing the source the vertex

    multiset<pair<int,int>>st; // set for storing the wieghts
    st.insert({0,source});  // inserting the source vertex with 0 distance

    dist[source]=0;  // storing the distance of source vertex in dist vector

    while(st.size()>0) { // traversing all the costs one by one

        auto node = *st.begin(); // extracting the current vertex and costs from the set
        int vertex = node.second; // extracting the current node;
        int dis = node.first ;  // extracting the current cost

        st.erase(st.begin()); // poping the current vertex from the set 

        if(vis[vertex])continue;  // if the node is already visited that ignore that
        vis[vertex] = 1; // if the vertex is not visited the mark it visited

        for(auto child:graph[vertex]){  // traversing all the neigbours of current node
            int child_v=child.first;  // extracting the child node
            int wt = child.second; // extracting the cost of the node

            if(dist[vertex]+wt<dist[child_v]){ // checking the distance of child node is les or not
                dist[child_v]=dist[vertex]+wt; // changin the distance of child node
                st.insert({dist[child_v],child_v}); // inserting the values in set
            }
        }
    }

}
void solve(){
    int n,m; // variable for number of vertex and edges;
    cin>>n>>m; // taking input the number of vertex and edges

    for(int i =0;i<m;i++){
        int x,y,w; // variable for storing edges between two vertices ;
                    // and the cost of the vertices

        cin>>x>>y>>w; // taking input the vertices and costs
        
        graph[x].push_back({y,w}); // storing the vertices and costs in the graph 
        graph[y].push_back({x,w}); // if the graph is undirected


    }
    dijkstra(1);
    for(int i =0;i<n;i++){
        cout<<dist[i]<<endl;
    }
}
int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
