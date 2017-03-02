// Given a Binary Search Tree (BST) and a range, print all the numbers in the BST that lie in the given range.
#include <bits/stdc++.h>
using namespace std;

/* Author : Dilip.K */

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

void printNearNodes(Node* root, int l, int h)
{
    if (!root)
        return;
    if (root->data == l && root->data == h)
        cout << root->data << " ";
    else if (root->data >= l && root->data <= h) {
        printNearNodes(root->left, l, h);
        cout << root->data << " ";
        printNearNodes(root->right, l, h);
    }
    else if (root->data < l)
        printNearNodes(root->right, l, h);
    else
        printNearNodes(root->left, l, h);
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

        int l, r;
        cin >> l >> r;

        printNearNodes(root, l, r);
        cout << endl;
    }
}
