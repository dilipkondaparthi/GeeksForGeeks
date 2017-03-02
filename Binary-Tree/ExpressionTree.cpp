// Given a simple expression tree, which is also a full binary tree consisting of basic binary operators i.e., + , – ,* and some integers, 
// Your task is to evaluate the expression tree. 
// You need to complete the function evalTree which takes the root of the tree as its only argument and 
// returns an integer denoting the result obtained by simplifying the expression tree.

#include <bits/stdc++.h>
using namespace std;

// Author: K.Dilip

struct node {
    string data;
    node* left;
    node* right;
};

int evalTree(node* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return stoi(root->data);

    int l = evalTree(root->left);
    int r = evalTree(root->right);
    if (root->data == "*")
        return l * r;
    else if (root->data == "+")
        return l + r;
    else if (root->data == "-")
        return l - r;
    else if (root->data == "/")
        return l / r;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int p = 0;
        node* root = new node;
        root->data = s[p];
        root->left = NULL;
        root->right = NULL;
        queue<node*> q;
        q.push(root);
        p = 1;
        while (!q.empty()) {

            node* f = q.front();
            q.pop();
            node *l, *r;
            if (p != n) {
                l = new node;
                l->data = s[p];
                f->left = l;
                p++;
                q.push(l);
            }
            else {
                f->left = NULL;
            }
            if (p != n) {
                r = new node;
                r->data = s[p];
                f->right = r;
                p++;
                q.push(r);
            }
            else {
                f->right = NULL;
            }
        }

        cout << evalTree(root) << endl;
    }
}
