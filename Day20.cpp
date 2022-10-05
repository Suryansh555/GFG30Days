//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
unordered_map<Node*,Node*>parent;
   Node*targetNode=NULL;
   void generate(Node*root,int target){
       if(!root)return;
       if(root->data==target){
           targetNode=root;
       }
       if(root->left){
           parent[root->left]=root;
       }
       if(root->right){
           parent[root->right]=root;
       }
       generate(root->left,target);
       generate(root->right,target);
   }
   int sum_at_distK(Node* root, int target, int k)
   {
       // Your code goes here
       if(!root)return 0;
       generate(root,target);
       unordered_set<Node*>vis;
       queue<Node*>q;
       q.push(targetNode);
       int ans=0;
       while(!q.empty() and k>=0){
           int n=q.size();
           while(n--){
               Node*temp=q.front();
               q.pop();
               if(vis.find(temp)!=vis.end()){
                   continue;
               }
               ans+=temp->data;
               vis.insert(temp);
               if(temp->left){
                   q.push(temp->left);
                   }
                   if(temp->right){
                       q.push(temp->right);
                   }
                   if(parent.find(temp)!=parent.end()){
                       q.push(parent[temp]);
                   }
           }
           k--;
       }
   return ans;
   }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends