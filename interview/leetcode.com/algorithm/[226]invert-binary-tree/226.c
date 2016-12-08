/*
 *  Source: https://leetcode.com/problems/invert-binary-tree/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-12-08
 *
    226. Invert Binary Tree   Add to List QuestionEditorial Solution  My Submissions
    Total Accepted: 138780
    Total Submissions: 280963
    Difficulty: Easy
    Contributors: Admin
    Invert a binary tree.

        4
      /   \
      2     7
    / \   / \
    1   3 6   9
    to
        4
      /   \
      7     2
    / \   / \
    9   6 3   1
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// improved
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode     *tmp;
    if (root) {
        tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
    }
    return root;
}
