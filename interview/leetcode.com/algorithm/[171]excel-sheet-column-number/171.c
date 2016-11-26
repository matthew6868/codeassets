/*
 *  Source: https://leetcode.com/problems/excel-sheet-column-number/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-11-26
 *
 *  Description:
    171. Excel Sheet Column Number
    Total Accepted: 108316
    Total Submissions: 241816
    Difficulty: Easy
    Contributors: Admin
    Related to question Excel Sheet Column Title

    Given a column title as appear in an Excel sheet, return its corresponding column number.

    For example:

        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28 
 *
 */
int titleToNumber(char* s) { 
    int result = 0, factor = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        result += pow(26, factor++) * (s[i] - 'A' + 1);
    }

    // a more simple solution
    // ref => https://discuss.leetcode.com/topic/61434/c-easy-solution-explanation
    /* int result = 0;
    while (*s) {
      result = result * 26 + *s++ - 'A' + 1;
    } */
     
    return result;
}
