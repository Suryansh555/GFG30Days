  #include<bits/stdc++.h>
  using namespace std ;
  
  vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
   { 
       // Your code goes here 
       vector<int>ans;
       priority_queue<pair<int,int>>max_heap;
       for( int i=0;i<n;i++)
       {
           max_heap.push({abs(x-arr[i]),arr[i]});
       }
       
       while(max_heap.size()>k)
       {
           max_heap.pop();
       }
       
       while(max_heap.size()!=0)
       {
           ans.push_back(max_heap.top().second);
           max_heap.pop();
       }
       
       sort(ans.begin(),ans.end());
       return ans;
   }  