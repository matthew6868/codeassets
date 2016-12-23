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

 class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        
        vector<int> result;
        vector<int> fullNums(nums.size());
        const size_t length = nums.size();
        for (int i = 1; i <= length; i++) {
            fullNums[i - 1] = i;
        }

        //auto last = std::unique(nums.begin(), nums.end());
        //nums.erase(last, nums.end()); 

        std::set_difference(fullNums.begin(), fullNums.end(), nums.begin(), nums.end(), std::inserter(result, result.begin()));
        
        return result;
    }
};