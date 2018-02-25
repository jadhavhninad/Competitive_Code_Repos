/*
https://leetcode.com/problems/sliding-window-maximum/description/
Use position of the max element in the sliding window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int _size = nums.size();
        int start = 0, end =start+k-1, max_pos=-1;
        vector<int> maxset;
        
        if(_size == 0)
            return maxset;
        
       
        int max_num = nums[0];
        
        while(end < _size){
            int chk = end;
            while((end - start + 1) <= k){
                if(start > max_pos){
                    //cout << start << " " << end << endl;
                    max_pos = get_max_val(start,end,nums);   
                    //cout << max_pos << endl;
                    //max_num = nums[max_pos];
                }
                else if(nums[end] > nums[max_pos]){
                    //max_num = nums[end];
                    max_pos = end;
                }
                 end+=1;
            }
            
            maxset.push_back(nums[max_pos]);
            start++;
            
        }
        return maxset;
        
    }
    
    int get_max_val(int first, int last, vector<int>& nums){
        int max_value = nums[first];
        int max_pos = first;
        for(int i=first; i<=last;i++){
            if(nums[i] > max_value){
                max_value = nums[i];
                max_pos = i;
            }
        }
        return max_pos;
    }
};
