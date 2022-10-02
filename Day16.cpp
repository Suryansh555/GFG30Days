//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
stack<string> stk;

        string newstr;

        if(k==1) return newstr;

        for(int i=0;i<s.size();i++){

            if(stk.empty()){

                string xt=s.substr(i,1);

                stk.push(xt);

            }

            else if(stk.top()[0]==s[i]){

                string x=stk.top();

                stk.pop();

                string xt=s.substr(i,1);

                x+=xt;

                if(x.size()!=k) stk.push(x);

            }

            else{

                string xt=s.substr(i,1);

                stk.push(xt);

            }

        }

        while(!stk.empty()){

            newstr+=stk.top();

            stk.pop();

        }

        reverse(newstr.begin(),newstr.end());

        return newstr;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends