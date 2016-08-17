//Find if there is a triplet in a Balanced BST that adds to zero.

#include <iostream> 
#include<queue> 
#include<map>
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

void convertBSTtoDLL(node* root,node* &head,node* &tail) // we convet BST to DLL in INORDER fashion
{
 if(root==NULL)
     return;
  
 convertBSTtoDLL(root->left,head,tail);  // recurse for the left subtree
 
 if(tail)           
     tail->right=root;   //assigning the next pointer for the previous node
 else                     
     head=root;           // Initially assigning the head pointer 
 
 root->left=tail;     //assigning the previous pointer for the current node
 tail=root;
 
 convertBSTtoDLL(root->right,head,tail); // recurse for the right subtree
 
}

bool checkpairsum(int sum,node* head,node* tail)
{
    while(head!=tail) 
    {
        int x=head->data,y=tail->data;
        if(x+y==sum) 
        {   
        	printf("Pair found: (%d,%d,%d)",-1*sum,x,y);
            return true;
        }
        else if(x+y>sum)  
            tail=tail->left;
        else       //(x+y>sum)
            head=head->right; 
     //  printf("%d+%d!=%d \n",x,y,sum);
    }
    return false;
}

bool isTripletPresent(node* root)
{
    node* head=NULL,*tail=NULL;
    
    convertBSTtoDLL(root,head,tail);  
    
    while(head->right!=tail && head->data<0)  
    {
        if(checkpairsum(-1*(head->data),head->right,tail))
            return true;
       
        head=head->right;
    } 
    return false;
}


int main()
{
    node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
    if (!(isTripletPresent(root)))
        printf("Not Present");
    return 0;
}
