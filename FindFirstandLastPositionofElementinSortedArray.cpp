34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
My code:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target))
        {return {-1,-1};
            
        }
        int u=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int>res;
        
        return {l,--u};
    }
};
