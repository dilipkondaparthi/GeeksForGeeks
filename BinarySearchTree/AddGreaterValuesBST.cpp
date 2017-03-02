// Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node.

#include <bits/stdc++.h> 
using namespace std;

// Author: K.Dilip

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
    if (root != NULL) {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void modified(Node* root, int& sum)
{
    if (root == NULL)
        return;
    modified(root->right, sum);
    sum += root->data;
    root->data = sum;
    modified(root->left, sum);
}

void modify(Node** root)
{
    int sum = 0;
    modified(*root, sum);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        Node* root = NULL;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            insert(&root, k);
        }

        modify(&root);

        inorder(root);
        cout << endl;
    }
}
