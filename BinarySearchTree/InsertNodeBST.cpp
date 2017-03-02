// Given a Binary Search Tree (BST), Task is to complete the function insert which inserts a node in the BST.
 
#include <bits/stdc++.h>
using namespace std;

// Author : K.Dilip

struct node {
    int data;
    struct node *right, *left;
};

struct node* newNode(int item)
{
    struct node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* This function should insert a new node with given data and
   return root of the modified tree  */
struct node* insert(struct node* node, int data)
{
    // Your code here
    if (node == NULL)
        return newNode(data);

    if (node->data > data)
        node->left = insert(node->left, data);
    else if (node->data < data)
        node->right = insert(node->right, data);

    return node;
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        node* root;
        node* tmp;
        root = NULL;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }
        inorder(root);
        cout << endl;
    }
}
