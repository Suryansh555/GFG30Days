#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data ; 
    Node * next ;
};


int countTriplets(struct Node* head, int x) 
{ 
   // code here.
   vector<int>v;
   while(head!=NULL)
   {
       v.push_back(head->data);
       head=head->next;
   }
   
 int count=0;
 for(int i=0;i<v.size();i++)
 {
     int l=i+1;
     int r=v.size()-1;
     while(l<r)
     {
         if(v[i]+v[l]+v[r]>x)
         r--;
         else if(v[i]+v[l]+v[r]<x)
         l++;
         else
         {
         count++;
         l++;
         r--;
         
     }
 }
} 
return count;
}