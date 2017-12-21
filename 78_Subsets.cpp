/*
78-Subsets https://leetcode.com/problems/subsets/description/
Solution:
use backtracking
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> unique_subset;
        sort(nums.begin(),nums.end());
        helper(nums,unique_subset,res,0);
        return res;
    }
    
    void helper(vector<int>& nums, vector<int>& unique_subset, vector<vector<int>>& res,int start){
        //vector<int> temp;
        //temp = unique_subset;
        //res.push_back(temp);
        res.push_back(unique_subset);
        int _size = nums.size();
        for(int i=start;i<_size;i++){
            unique_subset.push_back(nums[i]);
            helper(nums,unique_subset,res,i+1);
            unique_subset.pop_back();
        }
    }
};
