#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return 1;
    }
    else if ((p != NULL && q == NULL) || (q != NULL && p == NULL)) {
        return 0;
    }
    else {
        if ((p->val == q->val && isSameTree(p->left, q->left) && isSameTree(q->right, p->right))) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}
 //Given binary tree [3,9,20,null,null,15,7],
int main() {
    TreeNode *A = new TreeNode(3);
    A->left = new TreeNode(9);
    A->right = new TreeNode(20);
    A->left->left = new TreeNode(NULL);
    A->left->right = new TreeNode(NULL);
    A->right->left = new TreeNode(15);
    A->right->right = new TreeNode(7);

    std::cout << minDepth(A) << std::endl;
    return 0;
}


