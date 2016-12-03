/*
 *  Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-12-03
 *
    104. Maximum Depth of Binary Tree
    Total Accepted: 196579
    Total Submissions: 389456
    Difficulty: Easy
    Contributors: Admin
    Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    
    return left > right ? left : right;
}