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
    public bool CanConstruct(string ransomNote, string magazine) {
        int foundCount = 0;
        int[] usedIndexes = new int[magazine.Length];
        
        for (int i = 0; i < ransomNote.Length; ++i) {
            char source = ransomNote[i];
            for (int j = 0; j < magazine.Length; ++j) {
                if (usedIndexes[j] == 0 && (magazine[j] ^ source) == 0) {
                    foundCount++;
                    usedIndexes[j] = 1;
                    break;
                }
            }
        }
        
        if (foundCount == ransomNote.Length) {
            return true;
        }
        
        return false;
    }
}