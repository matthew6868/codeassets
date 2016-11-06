/**
 *  Author:matthew6868(mxu.public@outlook.com)
 *  Date:2016-11-7

 *  136. Single Number   
 
 *  Given an array of integers, every element appears twice except for one. Find that single one.

 *  Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *	
 * 	@param {number[]} nums
 * 	@return {number}
 */
var singleNumber = function(nums) {
    for(var i = 1; i < nums.length; i++){
        nums[0] ^= nums[i];
    }
  return nums[0];
};