#include<bits/stdc++.h>
using namespace std ;


class Solution
{
    public:
    int maxFrequency(string S)
    {
    	int ans=1;
        int n=S.size();
        string temp;;
    	for(int i=0;i<n;i++){
    	    string s1=S.substr(0,i+1);
    	    string s2=S.substr(n-i-1,i+1);
    	    if(s1==s2){
    	        temp=s1;
    	        break;
    	    }
    	}
    	for(int i=temp.size();i<n;i++){
    	    ans+=(temp==S.substr(i,temp.size()));
    	}
    	return ans;
    }
};

