// Given a binary tree, your task is to complete the function minDepth 
// which takes one argument the root of the binary tree and prints the min depth of  binary tree .

#include <bits/stdc++.h>
#include <climits>
using namespace std;

//Author: K.Dilip

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/*You are required to complete this method*/
int minDepth(Node* node)
{
    if (node == NULL)
        return INT_MAX;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return 1 + min(minDepth(node->left), minDepth(node->right));
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

        cout << minDepth(root) << endl;
        // cout << endl;
    }
    return 0;
}
