#include<bits/stdc++.h>
using namespace std;
 
void dp_on_trees(int node, int parent, vector<int> adj[], vector<int>& dp) {
    dp[node] = 1;
 
    for(int child : adj[node]) {
        if(child != parent) {
            dp_on_trees(child, node, adj, dp);
            dp[node] += dp[child];
        }
    }
}
 
int main(){
    int n;
    cin >> n;
 
    vector<int> adj[n+1];
 
    for(int i=0; i<n-1; i++) {
        int u = i + 2;
        int v;
        cin >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> dp(n+1, 0);
 
    dp_on_trees(1, 0, adj, dp);
 
    for(int i=1; i<=n; i++) cout << dp[i] - 1 << " ";
    cout << endl;
 
    return 0;
}