#include<bits/stdc++.h>
using namespace std ;
long long ValidPair(int a[], int n) 
{ 
    sort(a, a+n);
    long long ans=0;
    for(int i=0; i<n-1; i++){
        int lb = lower_bound(a+i+1, a+n, 1-a[i]) - a;
        ans += (n-lb);
    }
    return ans;
}   