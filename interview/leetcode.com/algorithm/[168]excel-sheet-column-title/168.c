/*
 *  Source: https://leetcode.com/problems/excel-sheet-column-title/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-11-25
 *
 *  168. Excel Sheet Column Title QuestionEditorial Solution  My Submissions
    Total Accepted: 82572
    Total Submissions: 343427
    Difficulty: Easy
    Contributors: Admin
    Given a positive integer, return its corresponding column title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB 
 */

char* convertToTitle(int n) {
    static char result[32] = {'\0'};
    int count = 0;
    
    while (n > 0) {
        int remainder = (n - 1) % 26; // aways convert to zero index array
        result[count++] = 'A' + remainder;
        
        n  = (n - 1) / 26;
    }
        
    // revert string
    for (int i = 0; i < count / 2; ++i) {
        char temp = result[count - 1 - i];
        result[count - 1- i] = result[i];
        result[i] = temp;
    }
    
    return result;
}