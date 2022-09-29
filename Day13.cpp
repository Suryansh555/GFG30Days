
#include<bits/stdc++.h>
using namespace std ;

class Solution{
   public:
   
   struct Node{
       int data;
       Node* left;
       Node* right;
       
       Node(int val){
           data=val;
           left=NULL;
           right=NULL;
       }
   };
   bool flag=true;
   void post(Node* root,vector<int> &vc){
       if(root==NULL)return;
       
       post(root->left,vc);
       post(root->right,vc);
       vc.push_back(root->data);

   }
   
   int find(int in[],int start,int n){
       for(int i=0;i<n;i++){
           if(start== in[i])return i;
       }
       flag=false;
       return -1;
   }
   
   Node* construct(int pre[],int in[],int &prendex,int instart,int inend,int n){
       
       if(instart>inend) return NULL;
       if(prendex>=n) return NULL;
       int start=pre[prendex++];
       int pos=find(in,start,n);
       Node* root=new Node(start);
       root->left=construct(pre,in,prendex,instart,pos-1,n);
       root->right=construct(pre,in,prendex,pos+1,inend,n);
       return root;
   }
   
   bool checktree(int pre[], int in[], int pos[], int n) 
   { 
    // Your code goes here
    int prendex=0;
    Node* root=construct(pre,in,prendex,0,n-1,n);
    vector<int> vc;
    post(root,vc);
    for(int i=0;i<n;i++){
        if(vc[i] != pos[i]) return 0;
    }
    return flag;
   }

};