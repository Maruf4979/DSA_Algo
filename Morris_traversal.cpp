#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree tNode has data, a pointer to left child
   and a pointer to right child */
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};
  
/* UTILITY FUNCTIONS --->constructor*/
/* Helper function that allocates a new Node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 
/* Function to traverse the binary tree without recursion
   and without stack */
void MorrisTraversal(struct Node* root)
{
    struct Node *current, *pre;
    if (root == NULL)
        return;
    current = root;
    while (current != NULL) 
    {
        if (current->left == NULL) 
        {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL&& pre->right != current)
                pre = pre->right;
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) 
            {
                pre->right = current;
                current = current->left;
            }
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else 
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
/* Driver program to test above functions*/
int main()
{
    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \    \                      
      4     5    6
       \
       7
  */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right= newNode(6);
    root->left->left->right= newNode(7);
    cout<<"Morris traversal as inorder traversal"<<endl;
    MorrisTraversal(root);
    return 0;
}