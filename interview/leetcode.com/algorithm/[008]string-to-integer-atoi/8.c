/*
 *  Source:https://leetcode.com/problems/string-to-integer-atoi/
 *  Author:matthew6868(mxu.public@outlook.com)
 *  Date:2016-10-15
 *
 *  8. String to Integer (atoi) 
 *  Total Accepted: 135312
 *  Total Submissions: 982585
 *  Difficulty: Easy
 *  Contributors: Admin
 *  Implement atoi to convert a string to an integer.
 *
 *  Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 *  Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *  Test case:
 *  "+1" => 1
 *  "   +0002ab2" => 2
 *  "+- 123" => 0
 *  "-2147483649" => -2147483648
 *  "+2147483649" => 2147483647
 *
 */
int myAtoi(char* str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    
    // eat lead white space
    while (*str != '\0' && *str == ' ') {
        str++;
    }
    
    // eat sign
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    // eat lead zero
    while (*str != '\0' && *str == '0') {
        ++str;
    }
    
    long long result = 0;
    
    while (*str != '\0' && (*str - '0' >= 0) && (*str - '0' <= 9)) {
        int val = *str - '0';
        result = result * 10 + val;
        if (result > INT_MAX) {
            if (sign > 0) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        str++;
    }
    
    return result * sign;
}