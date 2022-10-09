#include<bits/stdc++.h>
using namespace std ;

vector<int> TopK(vector<int>& a, int k)
   {
       map<int,int> mp;
       for(int i=0;i<a.size();i++)
           mp[a[i]]++;
       priority_queue<pair<int,int>> pq;
       for(auto x:mp)
           pq.push({x.second,x.first});
       vector<int> v;
       for(int i=0;i<k;i++)
       {
           pair<int,int> p = pq.top();
           pq.pop();
           v.push_back(p.second);
       }
       return v;
   }