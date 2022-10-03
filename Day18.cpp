
#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
 bool recreationalSpot(int arr[], int n){

     int K = INT_MIN;
    stack<int>st;

     for(int i=n-1;i>=0;i--){

         if(arr[i]<K) return true;

         else while(!st.empty() && arr[i]>st.top()){
             K = st.top();
             st.pop();
        }
        st.push(arr[i]);

     }

     return false;

 }
};