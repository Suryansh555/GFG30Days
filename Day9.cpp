 #include<bits/stdc++.h>
 using namespace std ;
 int transfigure (string A, string B)
   {
    
   if( A.size() != B.size()) return -1;
    
   
   int sum=0;
   for(int i=0; i< A.size(); i++){
       sum = sum + A[i];
       sum = sum - B[i];
   }
   
   if(sum != 0) return -1;
   
   int count = 0;
   int i = A.length() - 1,j=i;
   
   while( i >= 0  && j>=0){
       
       if( A[i] == B[j]){
           i--;
           j--;
       }else{
           i--;
           count++;
       }
   }
   
    if(count==A.length() && count==B.length())return -1;
    
   return count;
   }