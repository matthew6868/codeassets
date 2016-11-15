/*
 *   Author: matthew6868(mxu.public@outlook.com)
 *   Date:2016-11-15
 *
 *   442. Find All Duplicates in an Array
 *   Total Accepted: 3878
 *   Total Submissions: 8388
 *   Difficulty: Medium
 *   Contributors: shen5630
 *   Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 *   Find all the elements that appear twice in this array.
 *
 *   Could you do it without extra space and in O(n) runtime?
 *
 *   Example:
 *   Input:
 *   [4,3,2,7,8,2,3,1]
 *
 *   Output:
 *   [2,3]
 *
 */

public class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        // reference => https://discuss.leetcode.com/topic/64735/java-simple-solution/2
        // when find a number i, flip the number at position i-1 to negative. 
        // if the number at position i-1 is already negative, i is the number that occurs twice.
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < nums.length; ++i) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] < 0)
                res.add(Math.abs(index + 1));
            nums[index] = -nums[index];
        }

        return res;
    }
}