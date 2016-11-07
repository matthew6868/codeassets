/*
 *   Author:matthew6868(mxu.public@outlook.com)
 *   Date: 2016-11-07
 *   Note: Not implement by myself,the code is reference from https://discuss.leetcode.com/topic/49829/share-my-c-solutions-easy-to-understand
 *
 *   371. Sum of Two Integers
 *   Total Accepted: 44230
 *   Total Submissions: 85794
 *   Difficulty: Easy
 *   Contributors: Admin
 *   Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 *   Example:
 *   Given a = 1 and b = 2, return 3.
 *
*/
public class Solution {
    public int getSum(int a, int b) {
        // return b == 0 ? a : getSum(a^b, (a&b)<<1);
        
        int sum = a;
        
        // consider every bit carry after add and add them each time.
        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        
        return sum;
    }
}