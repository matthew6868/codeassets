/*
 *  Source: https://leetcode.com/problems/first-unique-character-in-a-string/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-11-21
 *
    387. First Unique Character in a String   QuestionEditorial Solution  My Submissions
    Total Accepted: 29713
    Total Submissions: 66363
    Difficulty: Easy
    Contributors: Admin
    Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.
    Note: You may assume the string contain only lowercase letters.
 */
public class Solution {
    public int firstUniqChar(String s) {
        char[] repeats = new char[256];
        
        for (int i = 0; i < s.length(); i++) {
            repeats[s.charAt(i)] ++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (repeats[s.charAt(i)] == 1) {
                return i;
            }
        }
        
        return -1;
    }
}