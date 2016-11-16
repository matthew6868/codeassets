/*
 *   Source: https://leetcode.com/problems/sum-of-two-integers/
 *   Author:matthew6868(mxu.public@outlook.com)
 *   Date: 2016-11-07
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

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
    
        int mask = 1;
        int sum = 0;
        int carry_bit = 0;
        // 循环获取a，b数字的每个二进制数值（0或1），同时考虑进位情况。
        while (mask) {
            int a1 = ( a & mask ) != 0 ? 1 : 0;
            int b1 = ( b & mask ) != 0 ? 1 : 0;
    
            if (!carry_bit) {
                if (a1 & b1) {
                    carry_bit = 1;
                } else if (a1 | b1) {
                    sum |= mask;
                }
            } else {
                if (a1 & b1) {
                    carry_bit = 1;
                    sum |= mask;
                } else if (a1 | b1) {
                    carry_bit = 1;
                } else {
                    carry_bit = 0;
                    sum |= mask;
                }
            }
    
            mask <<= 1;
        }
    
        return sum;
    }
};