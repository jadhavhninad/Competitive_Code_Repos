/*
759. Employee free time
https://leetcode.com/contest/weekly-contest-66/problems/employee-free-time/
discuss:https://discuss.leetcode.com/topic/116259/simple-java-solution-using-priority-queue/4
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        
        vector<Interval>res={};
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>__intervals={};
        int _size = schedule.size();
        
        if(_size == 0)
            return res;
            
        //Create a min_heap
        for(int i=0; i<_size; i++){
            //cout << schedule[i].start << endl;
            for(int j=0;j<schedule[i].size();j++)
                __intervals.push(make_pair(schedule[i][j].start,schedule[i][j].end));
        }
        
        
        int f_start = __intervals.top().first;
        int f_end = __intervals.top().second;
        __intervals.pop();
            
        while(!__intervals.empty()){
            int temp_start = __intervals.top().first;
            int temp_end = __intervals.top().second;
            
            if(temp_start > f_end){
                //new standard to create a new object in the vector of type T.
                res.push_back({f_end,temp_start});
                f_start = temp_start;
                f_end = temp_end;
            }
            else if(temp_start <= f_end){
                f_end = f_end > temp_end ? f_end : temp_end;
            }
            __intervals.pop();
        }
        
        
        return res;
    }
};
