// Given Linked List Representation of Complete Binary Tree, construct the Binary tree.
// Your task is to complete the function convert which takes two arguments the first being the head denoting the head of the linked list 
// and the second argument is root denoting the root of the tree to be constructed.

#include <bits/stdc++.h>

using namespace std;

/* Link list node */
struct node {
    int data;
    struct node* next;
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void push(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

TreeNode* createnode(int data)
{
    TreeNode* temp = new TreeNode();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

/*You are required to complete this method*/
void convert(node* head, TreeNode*& root)
{
    TreeNode *temp = NULL, *lr = NULL;
    node* trav = head;

    if (head) {
        temp = createnode(head->data);
        root = temp;
    }
    else
        return;
    queue<TreeNode*> q;
    while (trav->next) {
        if (trav->next) {
            trav = trav->next;
            lr = createnode(trav->data);
            temp->left = lr;
            q.push(lr);
        }

        if (trav->next) {
            trav = trav->next;
            lr = createnode(trav->data);
            temp->right = lr;
            q.push(lr);
        }
        q.pop();
        temp = q.front();
    }
}

void lvl(TreeNode* r)
{
    if (r == NULL)
        return;
    queue<TreeNode*> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode* j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(node** head)
{
    node* prev = NULL;
    node* cur = *head;
    node* nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct node* head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode* root;
        convert(head, root);
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}
