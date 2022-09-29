//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    long long int digitsum(int element){
        long long int sum = 0; 
        while(element != 0){
            sum = sum + element % 10;
            element /= 10 ;
        }
        return sum ;
    }
    int RulingPair(vector<int> arr, int n) 
    { 
    	unordered_map<long long int,int> mp ;
    	long long int real = INT_MIN ;
    	for(int i = 0 ; i < n ; i++){
    	    long long int sum = digitsum(arr[i]);
    	    if(mp.find(sum) != mp.end()){
    	        if(mp[sum] + arr[i] > real){
    	            real = mp[sum] + arr[i];
    	        }
    	        if(mp[sum] < arr[i]){
    	            mp[sum] = arr[i];
    	        }
    	    }
    	    else{
    	        mp[sum] = arr[i];
    	    }
    	}
    	if(real == INT_MIN){
    	    return -1;
    	}
    	return real ;
    }   
};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 


// } Driver Code Ends