// Given a Binary Search Tree (BST) and a node no 'x', Task is to delete the node 'x' from the BST.

#include <bits/stdc++.h>
using namespace std;

// Author : K.Dilip

struct Node {
    int data;
    struct Node *right, *left;
};

void insert(Node** tree, int val)
{
    Node* temp = NULL;
    if (!(*tree)) {
        temp = (Node*)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if (val < (*tree)->data) {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }
}
void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* min_node(Node* root)
{
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int x)
{
    // your code goes here

    if (root == NULL)
        return NULL;

    if (root->data > x) {
        root->left = deleteNode(root->left, x);
    }
    else if (root->data < x) {
        root->right = deleteNode(root->right, x);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = min_node(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, root->data);
        }
    }
    return root;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        Node* root;
        Node* tmp;
        root = NULL;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            insert(&root, k);
        }
        int r;
        cin >> r;
        root = deleteNode(root, r);
        inorder(root);
        cout << endl;
    }
}
