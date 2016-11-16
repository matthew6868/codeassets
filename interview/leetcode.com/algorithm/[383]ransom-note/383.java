/*
 *   Author:matthew6868(mxu.public@outlook.com)
 *   Date: 2016-11-15
 *
 *   383. Ransom Note  
 *   Total Accepted: 29494
 *   Total Submissions: 64802
 *   Difficulty: Easy
 *   Contributors: Admin
 *   Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 *
 *   Each letter in the magazine string can only be used once in your ransom note.
 *
 *   Note:
 *   You may assume that both strings contain only lowercase letters.
 *
 *   canConstruct("a", "b") -> false
 *   canConstruct("aa", "ab") -> false
 *   canConstruct("aa", "aab") -> true
 */
public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        // reference implementaion => https://discuss.leetcode.com/topic/53864/java-o-n-solution-easy-to-understand/10

        // consider null or empty case
        if (ransomNote == null || ransomNote.isEmpty()) {
            return true;
        }

        if (magazine == null || magazine.isEmpty()) {
            return false;
        }
        
        // first, remember the numbers of each letter in magazine string
        // second, subtract the numbers of eachr letter in ransomNote string and
        // if result is negetive, it means there was more letters not exist in magazine string.
        int[] letters = new int[26];
        for (char c : magazine.toCharArray()) {
            letters[c - 'a']++;
        }
        
        for (char c : ransomNote.toCharArray()) {
            if (--letters[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
}