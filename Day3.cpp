 #include<bits/stdc++.h>
 using namespace std ;
 
 long long smallestpositive(vector<long long> array, int n)
   { 
       // code here 
       sort(array.begin(), array.end());
       long long res =1;
       for(int i =0; i<n; i++){
           if(res<array[i]){
           return res;
           }
           else
            res = res+array[i];
       }
       return res;
   } 