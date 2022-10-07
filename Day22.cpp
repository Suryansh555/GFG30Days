#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    
    public:
    #define vt vector<int>
    pair<int, int> shortestRange(Node *root) 
    {
        vector<vector<int>>v;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>t;
            while(size--)
            {
                root=q.front();
                q.pop();
                t.push_back(root->data);
                if(root->left)
                   q.push(root->left);
                if(root->right)
                   q.push(root->right);
            }
            v.push_back(t);
        }
        int m=v.size(),mx=0,s,e,diff=INT_MAX;
        priority_queue<vt,vector<vt>,greater<vt>>pq;
        for(int i=0;i<m;i++)
        {
            pq.push({v[i][0],i,0});
            mx=max(mx,v[i][0]);
        }    
        while(!pq.empty())
        {
            int mn=pq.top()[0],i=pq.top()[1],j=pq.top()[2];
            pq.pop();
            if(mx-mn<diff)
            {
                diff=mx-mn;
                s=mn;
                e=mx;
            }
            j++;
            if(j==v[i].size())
               break;
            mx=max(mx,v[i][j]);
            pq.push({v[i][j],i,j});
        }        
        return {s,e};
    }
};