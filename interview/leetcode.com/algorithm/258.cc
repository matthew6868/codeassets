/*
 *	Author:matthew6868(mxu.public@outlook.com)
 *	Date: 2016-11-08
 *
 *
 *	258. Add Digits 
 *	Total Accepted: 135269
 *	Total Submissions: 271000
 *	Difficulty: Easy
 *	Contributors: Admin
 *	Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 *	For example:
 *
 *	Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 *	Follow up:
 *	Could you do it without any loop/recursion in O(1) runtime?
*/

class Solution {
public:
    int caculateDigits(int num) {
        if (num < 10)
            return num;
            
        return num % 10 + caculateDigits(num / 10);
    }
    
    int addDigits(int num) {
        while (num >= 10) {
            num = caculateDigits(num);
        }
        
        return num;
    }
};