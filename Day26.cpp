#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    bool cycle=false;
    int dfs(int idx , unordered_map<int,vector<int>>&adj , int duration[] , vector<int> &visited){
        // 0 -> In current traversal.
        visited[idx]=0;
        int timed=0;
        for(auto i:adj[idx]){
            if(visited[i]==0){
                cycle=true;
                break;
            }else if(visited[i]==-1){
                timed=max(timed,dfs(i,adj,duration,visited));
            }else{
                timed=max(timed,duration[i]);
            }
        }
        
        // 1 -> Completed calculating time for it so DP
        visited[idx]=1;
        duration[idx]+=timed;
        
        return duration[idx];
    }
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        // Check for cycles.
        cycle=false;
        
        // Solve for time = max time in dfs of all with DP.
        vector<int> visited(n,-1);
        unordered_map<int,vector<int>> adj;
        for(auto i:dependency){
            adj[i.first].push_back(i.second);
        }
        int timed=0;
        
        for(int i=0;i<n&&!cycle;i++)
            if(visited[i]==-1)
                timed=max(timed,dfs(i,adj,duration,visited));
        
        if(cycle)return -1;
        
        return timed;
        
    }
};