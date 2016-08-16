// Print a Binary Tree in Vertical Order. Solved using Level-Order traversal.
#include <iostream> 
#include<queue> 
#include<map>
using namespace std;

/* Author : Dilip.K */
struct node
{
    node * left;
    node* right;
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

int height(node * root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

void levelorder(node* root,int level,int i,map<int,vector<int> > &m)
{
    if(root==NULL)
        return;
  if(level==1)
  {
      m[i].push_back(root->data);
      return;
  }
    levelorder(root->left,level-1,i-1,m);
    levelorder(root->right,level-1,i+1,m); 
}

 

void printVerticalOrderiterative(node* root)
{
    map<int,vector<int> > m;
    
    for(int i=1;i<=height(root);i++)
    { 
        levelorder(root,i,0,m);
    } 
    
    map<int,vector<int> > :: iterator it;
    
    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(4);
root->left->left = newNode(3);
root->left->left->right = newNode(5);
root->left->left->right->right = newNode(6);
root->right->left = newNode(7);

cout << "Vertical order traversal is \n";
printVerticalOrderiterative(root);

return 0;
}
