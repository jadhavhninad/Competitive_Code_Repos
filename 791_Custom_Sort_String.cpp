/*
https://leetcode.com/contest/weekly-contest-73/problems/custom-sort-string/
*/

class Solution {
public:
    string customSortString(string S, string T) {
        
        int _size = S.length();
        string res="";
        for(int i=0; i<_size; i++){
            size_t n = count(T.begin(), T.end(), S[i]);
            for(int j=0; j<n; j++)
                res+=S[i];
        }
        
        int _size_t = T.length();
        for(int i=0; i<_size_t;i++){
            if(S.find(T[i]) != string::npos)
                continue;
            else
                res+=T[i];
        }
      return res;  
    }
};
