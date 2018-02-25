//https://leetcode.com/problems/escape-the-ghosts/description/


class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        
        int _sizeG = ghosts.size();
        int my_moves = abs(target[0]) + abs(target[1]);
        int gmoves=0;
        
        for(int i=0 ;i<_sizeG;i++){
            gmoves = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            if(gmoves <= my_moves)
                return false;
        }
        
        return true;
    }
};

/*
[[1,9],[2,-5],[3,8],[9,8],[-1,3]]
[8,-10]
*/
