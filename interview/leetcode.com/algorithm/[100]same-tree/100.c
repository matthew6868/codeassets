/*
 *  Source: https://leetcode.com/problems/same-tree/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-12-2
 *
    100. Same Tree  
    Total Accepted: 169187
    Total Submissions: 375983
    Difficulty: Easy
    Contributors: Admin
    Given two binary trees, write a function to check if they are equal or not.

    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    
    if (p == NULL || q == NULL) {
        return false;
    }
    
    if (p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    
    return false;
}