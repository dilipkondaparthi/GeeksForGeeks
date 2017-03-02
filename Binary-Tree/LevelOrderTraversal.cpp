// Given a Binary Tree, your task is to print its level order traversal where each level is separated by $.

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Author: K.Dilip

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void levelOrder(struct Node* root)
{
    queue<Node*> q;
    if (root == NULL)
        return;

    q.push(root);
    int count;

    while (!q.empty()) {
        count = q.size();
        while (count--) {
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            cout << q.front()->data << " ";
            q.pop();
            root = q.front();
        }
        cout << "$ ";
    }
}

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Driver program to test size function*/
int main()
{
    int t;
    struct Node* child;
    scanf("%d\n", &t);
    while (t--) {
        map<int, Node*> m;
        int n;
        scanf("%d", &n);
        struct Node* root = NULL;
        while (n--) {
            Node* parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);

            if (m.find(n1) == m.end()) {
                parent = newNode(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];

            child = newNode(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }

        levelOrder(root);
        cout << endl;
    }
    return 0;
}