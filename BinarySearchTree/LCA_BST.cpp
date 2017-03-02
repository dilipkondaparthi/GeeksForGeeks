// Given a Binary Search Tree and 2 nodes value n1 and n2, Find the lowest common ancestor of the two nodes.

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

Node* LCA(Node* root, int n1, int n2)
{

    if (root == NULL)
        return NULL;

    while (root) {

        if (root->data < n1 && root->data < n2)
            root = root->right;

        else if (root->data > n1 && root->data > n2)
            root = root->left;

        else
            break;
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
        //int i;

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

        cout << LCA(root, l, r)->data << endl;
    }
}
