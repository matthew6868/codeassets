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

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> uniqueResult;
        multimap<int, int> numsMap;
        
        for (auto it : nums) {
            numsMap.insert(std::pair<int, int>(it, 1));
        }
        
        for (auto it : nums) {
            if (numsMap.count(it) > 1) {
                uniqueResult.insert(it);
            }
        }
        
        vector<int> result(uniqueResult.begin(), uniqueResult.end());
        
        return result;
    } 
};