// Print Nodes in Top View of Binary Tree. Solved by using map STL, C++.

#include <iostream> 
#include<queue> 
#include<map>
using namespace std;

/* Author : Dilip.K */
struct node
{
    node * left;
    node* right;
    int hd;
    int data;
};

node* newNode(int x)
{
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    return temp;
} 

void topview(node* root)
{
    if(root==NULL)
       return;
     queue<node*>q;
     map<int,int> m; 
     int hd=0;
     root->hd=hd;
     
    q.push(root);
    
    while(q.size())
    {
        hd=root->hd;
        if(m.count(hd)==0)  // count function returns 1 if the container contains an element whose key is equivalent to hd, or returns zero otherwise.
        m[hd]=root->data;
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
      
    } 
    
     for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
    
}
 
// Driver Program to test above functions
int main()
{
   node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    topview(root);
    
  
    return 0;
}
