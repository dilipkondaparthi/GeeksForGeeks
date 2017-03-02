// Given a a Binary Tree, your task is to complete the function getLevelDiff,
// which returns the difference between the sum of nodes at odd level and the sum of nodes at even level . 
// The function getLevelDiff  takes only one argument  ie the root of the binary tree. 

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

int getLevelDiff(Node* root)
{
    int diff, count, so, level = 2;
    queue<Node*> q;

    q.push(root);
    so = root->data;
    while (!q.empty()) {
        count = q.size();
        while (count--) {
            if (root->left) {
                q.push(root->left);
                level % 2 ? so += root->left->data : so -= root->left->data;
            }
            if (root->right) {
                q.push(root->right);
                level % 2 ? so += root->right->data : so -= root->right->data;
            }
            q.pop();
            root = q.front();
        }
        level++;
    }
    return so;
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
        scanf("%d\n", &n);
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

        cout << getLevelDiff(root);
        cout << endl;
    }
    return 0;
}
