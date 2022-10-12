#include<bits/stdc++.h>
using namespace std; 


int catchThieves(char arr[], int n, int k) 
    {
        int ans = 0;
        vector<int> thief,police;
        for(int i=0;i<n;i++){
            if(arr[i] == 'T'){
                thief.push_back(i);
            }else{
                police.push_back(i);
            }
        }
        int i=0,j=0;
        while(i<police.size() && j<thief.size()){
            if(abs(thief[j]-police[i]) <= k){
                ans++;
                i++;
                j++;
            }else if(police[i] < thief[j]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }