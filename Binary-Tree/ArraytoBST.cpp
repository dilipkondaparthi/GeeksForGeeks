// Given a sorted array. Write a program that creates a Balanced Binary Search Tree using array elements. 
// If there are n elements in array, then floor(n/2)'th element should be chosen as root and same should be followed recursively.

#include <iostream>
using namespace std;

// Author : K.Dilip

struct node {
    int data;
    node* left;
    node* right;
};

void preorder(node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* createBST(int a[], int l, int h)
{
    if (l > h)
        return NULL;
    node* root = new node();
    int mid = (l + h) / 2;
    root->data = a[mid];
    root->left = createBST(a, l, mid - 1);
    root->right = createBST(a, mid + 1, h);
    return root;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        node* root = createBST(a, 0, n - 1);
        preorder(root);
        cout << endl;
    }
    return 0;
}
