//https://leetcode.com/contest/weekly-contest-73/problems/rotated-digits/

class Solution {
public:
    int rotatedDigits(int N) {
        
        int count = 0;
        for(int i=1;i<=N;i++){
            
            string number = to_string(i);
            if(number.find('3') != string::npos || number.find('4')!= string::npos || number.find('7')!=string::npos)
                count++;
            
            int invalids=0; 
            for(int j=0; j< number.size(); j++){
                if(number[j] == '0' || number[j] == '1' || number[j] == '8' )
                    invalids+=1;
            }
            
            if(invalids == number.size())
                count+=1;
            
        }
        
        return N - count;
    }
};
