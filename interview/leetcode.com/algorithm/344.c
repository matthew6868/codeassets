/*
 * Author: matthew6868(mxu.public@outlook.com)
 * Date: 2016-11-04
 * 
 * 344. Reverse String
 * Total Accepted: 104395
 * Total Submissions: 182089
 * Difficulty: Easy
 * Contributors: Admin
 * Write a function that takes a string as input and returns the string reversed.

 * Example:
 * Given s = "hello", return "olleh".
*/

char* reverseString(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
    
    return s;
}