/*
 *  Source: https://leetcode.com/problems/sum-of-left-leaves/
 *  Author: matthew6868(mxu.public@outlook.com)\
 *  Date: 2016-11-19
 *
 *  404. Sum of Left Leaves   QuestionEditorial Solution  My Submissions
 *  Total Accepted: 21096
 *  Total Submissions: 46272
 *  Difficulty: Easy
 *  Contributors: Admin
 *  Find the sum of all left leaves in a given binary tree.

 *  Example:

      3
     / \
     9  20
      /  \
     15   7

 *  There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    int sumOfLeftLeavesRecursive(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL && parent != NULL && parent->right != root) {
            return root->val;
        }
        
        int sum = sumOfLeftLeavesRecursive(root->left, root);
        sum += sumOfLeftLeavesRecursive(root->right, root);

        return sum;
    }
    
public:  
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesRecursive(root, NULL);
    }
};