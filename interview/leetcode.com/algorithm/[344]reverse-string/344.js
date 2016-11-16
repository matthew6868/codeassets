/**
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
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
    var result = [];
    for (var i = s.length - 1, j = 0; i >= 0; i--, j++) {
        result[i] = s[j]
    }
    
    return result.join('');
};