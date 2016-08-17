// Count BST nodes that lie in a given range. Solved by traversing through In-Order fashion using Stack STL, C++.
// Time Complexity: O(n)

#include <iostream> 
#include <stack>         
using namespace std;
 
/* Author : Dilip.K */
struct node
{
    node* left;
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
 
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}

int getCount(node* root,int l,int h)
{
    if(root==NULL)
        return 0;
    
    stack<node*> s;
    int count=0;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        
        if(s.empty())
            return count;
        
        int x=s.top()->data;
        
        if(x<l)
        {
            root=s.top()->right;
            s.pop(); 
        }
        else if(x>=l && x<=h)
        {
            count++;
            root=s.top()->right;
            s.pop(); 
        }
        else if(x>h)
            return count;
    }
    
    return count;
}

int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;
    cout << "Count of nodes between [" << l << ", " << h
         << "] is " << getCount(root, l, h);
    return 0;
}
