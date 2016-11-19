/*
 *  Source: https://leetcode.com/problems/intersection-of-two-arrays/
 *  Author: matthew6886(mxu.public@outlook.com)
 *  Date: 2016-11-19

    349. Intersection of Two Arrays   QuestionEditorial Solution  My Submissions
    Total Accepted: 59697
    Total Submissions: 132297
    Difficulty: Easy
    Contributors: Admin
    Given two arrays, write a function to compute their intersection.

    Example:
    Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

    Note:
    Each element in the result must be unique.
    The result can be in any order.
*/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> uniqueSet;
        
        for (auto it1 : nums1) {
            if (uniqueSet.find(it1) == uniqueSet.end()) {
                for (auto it2 : nums2) {
                    if ((it1 ^ it2) == 0) {
                        uniqueSet.insert(it1);
                    }
                }
            }
        }
        
        vector<int> result;
        for (auto it : uniqueSet) {
            result.push_back(it);
        }
        
        return result;
    }

    // href => https://discuss.leetcode.com/topic/67119/two-sinple-c-solution-using-sort-unique-and-hashmap
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, short> h; //hashmap
        vector<int> result; //return vector

        for(auto &i: nums1) 
            if(h[i]==0) h[i]++;
        for(auto &i: nums2) 
            if(h[i]--==1) 
                result.push_back(i);
        return result;
    }

    vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        auto it1 = unique(nums1.begin(), nums1.end());
        nums1.resize(it1 - nums1.begin());
        
        auto it2 = unique(nums2.begin(), nums2.end());
        nums2.resize(it2 - nums2.begin());
        auto it = set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums1.begin());
        nums1.resize(it-nums1.begin());
        return nums1;
    }
};