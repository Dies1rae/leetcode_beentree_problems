#include <iostream>

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
 
int main() {
    TreeNode *A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    TreeNode* B = new TreeNode(1);
    B->left = new TreeNode(NULL);
    B->right = new TreeNode(3);
    std::cout << isSameTree(A, B) << std::endl;
    return 0;
}


