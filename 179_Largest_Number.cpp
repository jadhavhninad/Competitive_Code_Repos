//https://leetcode.com/problems/largest-number/description/
//179. Largest Number

class Solution {
public:
    static bool strcmparator(string a, string b){
        string one = a + b;
        string two = b + a;
        
        //note : compare does not return boolean
        /*
        int ret = one.compare(two);
        if(ret > 0)
            return 1;
        else
            return 0;
        */
        return one > two;
    }
        
    string largestNumber(vector<int>& nums) {
        
        vector<string> numtos;
        int _size = nums.size();
        string res="";
        
        if(_size == 0)
            return res;
        
        for(int i=0; i<_size; i++){
            numtos.push_back(to_string(nums[i]));
        }
        
        sort(numtos.begin(),numtos.end(),strcmparator); 
        
        //cout << "------" << endl;
        
        /*for(int i=0;i<_size; i++)
            cout << numtos[i] << endl;
        */
        //cout << "------" << endl;
        if(numtos[0]=="0")
            return "0";
        
        for(int i=0;i<_size;i++){
          res.append(numtos[i]);
        }
        
        return res;
    }
};

/*Test

[7162,9908,53,9,876,1023,333,90,678]
[3, 30, 34, 5, 9]
[9908,9,90]

*/
