/* C++ program to print nodes of extreme corners
of each level in alternate order */

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Author : K.Dilip

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
/* Function to print nodes of extreme corners
of each level in alternate order */

void printExtremeNodes(Node* root)
{
    queue<Node *> q, result;
    q.push(root);
    int count;
    bool check = true;
    while (!q.empty()) {
        int t = q.size(), count = q.size();
        while (count) {
            if (check && count == 1) {
                cout << root->data << " ";
            }
            else if (!check && count == t) {
                cout << root->data << " ";
            }

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            q.pop();
            count--;
            root = q.front();
        }
        check = !check;
    }
}

/* Driver program to test above functions*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        map<int, Node*> m;
        int n;
        scanf("%d\n", &n);
        Node* root = NULL;
        while (n--) {
            Node* parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            //  cout << n1 << " " << n2 << " " << (char)lr << endl;
            if (m.find(n1) == m.end()) {
                parent = newNode(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];

            Node* child = newNode(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        printExtremeNodes(root);
        cout << endl;
    }
    return 0;
}
