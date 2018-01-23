//55. Jump Game
//https://leetcode.com/problems/jump-game/description/



class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int next = 0, _size = nums.size();
        int lastReachable = _size-1;
        
        for(int i= _size-1; i>=0; i--){
            if(i + nums[i] >= lastReachable)
                lastReachable = i;
        }
        
        return lastReachable == 0;
    }
};
