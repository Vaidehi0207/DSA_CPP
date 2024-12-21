#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> solve(int V, vector<int> adj[]){
        // creating a vector visited intially 0 
        int vis[V] = {0};
        // mark visited[0] = 1;
        vis[0] = 1;
        queue<int> q;
        q.push(0);

        vector<int> bfs;

        while(!q.empty()){
            // topmost of queue
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // now find the neighbours of node and if it is not marked as 1 
            // then mark it 1 in vis array and push it in the queue
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = {1};
                    q.push(it);
                }
            }
        } 
        return bfs;
    }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printans(vector<int> &ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}


int main(){
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
    Solution obj;
    vector<int> ans = obj.solve(5, adj);
    printans(ans);
    return 0;

}