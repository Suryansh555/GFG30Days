#include<bits/stdc++.h>
using namespace std ;

typedef pair<int,int> ip;
class Solution{
    int d[4]={1,-1,0,0};
    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int> > ans(M,vector<int>(N));
        queue<ip> q;
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if(matrix[i][j]=='B')
                    ans[i][j]=0,q.push({i,j});
                else if(matrix[i][j]=='W')
                    ans[i][j]=-1;
                else 
                    ans[i][j]=-1;
        int dis=1,x,y;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                tie(x,y)=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int dx=x+d[i], dy=y+d[3-i];
                    // matrix[dx][dy]="F" is to mark it as visited
                    if(dx>=0 && dx<M && dy>=0 && dy<N && matrix[dx][dy]=='O')
                        ans[dx][dy]=dis,matrix[dx][dy]='F',q.push({dx,dy});
                }
            }
            dis++;
        }
        return ans;
    } 
};