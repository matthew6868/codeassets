/*
 *  Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-12-24
 *  
 *  Desc:
    448. Find All Numbers Disappeared in an Array
    Total Accepted: 9532
    Total Submissions: 15987
    Difficulty: Easy
    Contributors: yuhaowang001
    Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

    Find all the elements of [1, n] inclusive that do not appear in this array.

    Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

    Example:

    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [5,6]
 */

/* TIMEOUT solution */
 public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        
        for (int i = 1; i <= nums.length; ++i) {
            boolean exist = false;
            for (int index = 0; index < nums.length; ++index) {
                if (nums[index] == i) {
                    exist = true;
                    break;
                }
            }
            
            if (!exist) {
                result.add(i);
            }
        }
        
        return result;
    }
}