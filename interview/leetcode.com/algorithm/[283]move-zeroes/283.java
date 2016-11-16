/*
 *   Source: https://leetcode.com/problems/move-zeroes/
 *   Author: matthew6886(mxu.public@outlook.com)
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
public class Solution {
    public void moveZeroes(int[] nums) {
        int holes = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0 && i != nums.length - 1) {
                boolean needMove = false;
                for (int j = i; j < nums.length - holes - 1; ++j) {
                    nums[j] = nums[j + 1];
                    if (!needMove && nums[j] != 0 )
                        needMove = true;
                }

                if (!needMove)
                    break;
                    
                holes++;
                i--;
            }
        }
        
        for (int i = 0; i < holes; ++i) {
            nums[nums.length - 1 - i] = 0;
        }
    }
}