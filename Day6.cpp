//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i = 0 ; i< N ; i++){
            if( i == 0)
                dp[0][i] = mat[0][i];
            else
                dp[0][i] = dp[0][i-1] + mat[0][i];
        }
        
        for(int i = 0 ; i < N ; i++){
            if(i == 0)
                continue ;
            else
                dp[i][0] = dp[i-1][0] + mat[i][0];
        }
        
        for(int i = 1 ; i < N ; i++){
            for(int  j = 1 ; j < N ; j++){
                dp[i][j] = mat[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        int result = INT_MIN ; 
        for(int i = K - 1 ; i < N ; i++){
            for(int j = K-1 ; j < N ; j++){
                int currResult = dp[i][j] - ((i - K >= 0 )?dp[i-K][j]:0) - ((j -K >= 0)?dp[i][j-K]:0) + ((i-K >= 0 and j - K >= 0 )?dp[i-K][j-K]:0);
                result = max(result,currResult);
            }
        }
        return result;
    }  
};

//{ Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}

// } Driver Code Ends