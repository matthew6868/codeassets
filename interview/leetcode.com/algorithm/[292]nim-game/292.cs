/*
 *  Source: https://leetcode.com/problems/nim-game/
 * 	Author: matthew6868(mxu.public@outlook.com)
 * 	Date: 2016-11-5
 *
 *	292. Nim Game   QuestionEditorial Solution  My Submissions
 *	Total Accepted: 107452
 *	Total Submissions: 197475
 *	Difficulty: Easy
 *	Contributors: Admin
 *	You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 *
 *	Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 *
 *	For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 *
 *	Hint:
 *
 *	If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
 * 	Solution tips: https://leetcode.com/articles/nim-game/
*/
public class Solution {
    public bool CanWinNim(int n) {
        return n % 4 != 0 ? true : false;
    }
}