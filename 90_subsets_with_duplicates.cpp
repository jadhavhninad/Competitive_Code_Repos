/*
98_subsets_with_duplicates
Use backtracking, ignore duplicated sets
*/


https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        
        //sorting becomes necessary as we have duplicated now.
        
        sort(nums.begin(), nums.end());
        helper(res,nums,temp,0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, int start){
        
        res.push_back(temp);
        int _size = nums.size();
        for(int i=start;i<_size;i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(res,nums,temp,i+1);
            temp.pop_back();
        }
    }
};
