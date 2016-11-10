/*
 *   Author:matthew6886(mxu.public@outlook.com)
 *   Date: 2016-11-10
 *
 *   283. Move Zeroes
 *   Total Accepted: 133404
 *   Total Submissions: 283615
 *   Difficulty: Easy
 *   Contributors: Admin
 *   Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 *   For example, given nums = [0, 1, 0, 0,3, 12], after calling your function, nums should be [1, 3, 12, 0, 0,0].
 *
 *   Note:
 *   You must do this in-place without making a copy of the array.
 *   Minimize the total number of operations.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //refre from https://leetcode.com/articles/move-zeroes/
        int lastNonZeroFoundAt = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found. 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // After we have finished processing new elements,
        // all the non-zero elements are already at beginning of array.
        // We just need to fill remaining array with 0's.
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};