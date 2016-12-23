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

 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    {
        for (int i = 0; i < numsSize; ++i) {
            int index = nums[i];
            if (nums[abs(index) - 1] > 0) {
                nums[abs(index) - 1] = -nums[abs(index)-1];
            }
        }
    }
    
    {
        int holes = 0;
        for (int i = 1; i <= numsSize; ++i) {
            if (nums[i - 1] > 0) {
                holes++;
            }
        }
        *returnSize = holes;
    }
    
    {
        int index = 0;
        int *result = (int*)malloc(sizeof(int) * (*returnSize));
        for (int i = 1; i <= numsSize; ++i) {
            if (nums[i - 1] > 0) {
                result[index++] = i;
            }
        }
        
        return result;
    }
}