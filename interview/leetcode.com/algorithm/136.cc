/*
 *  Author:matthew6868(mxu.public@outlook.com)
 *  Date:2016-11-7

 *  136. Single Number   QuestionEditorial Solution  My Submissions
 *  Total Accepted: 170544
 *  Total Submissions: 326772
 *  Difficulty: Easy
 *  Contributors: Admin
 *  Given an array of integers, every element appears twice except for one. Find that single one.

 *  Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        multimap<int, int> tables;
        
        for (int i = 0; i < nums.size(); ++i) {
            tables.insert(pair<int,int>(nums[i], i));
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (tables.count(nums[i]) < 2) {
                return nums[i];
            }
        }
        
        return 0;
    }
};