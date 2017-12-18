/*
748. Shortest Completing Word
Solution:
1. Add the strings to a min_heap
2. detect alphabets in the licenseplate string by  checking their int value. Store their count (all lowercase) in a map
3. for each min_heap top, store count of each unique char in map. Then compare the count with the licenseplate count. If all match, return that string,
else pop and repeat for next.
4. Note: we need to insert the original index of the words to resolve clash (returning the smallest word that occurs first.)

*/
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        priority_queue<pair<int, pair<int,string>> , vector<pair<int, pair<int,string>>>, greater<pair<int, pair<int,string>>> > strlength;
        
        int _size = words.size();
        int lps = licensePlate.length();
        unordered_map<char,int> lp_char_val;
        
        for(int i=0;i<_size;i++){
            strlength.push(make_pair(words[i].length(), make_pair(i,words[i])));
            //cout << strlength.top().second << endl;
        }
        
        for(int k=0;k<lps;k++){
            //cout << licensePlate[k] - '0' << endl;
            if(licensePlate[k] - '0' <=9)
                continue;
            else{
                //cout << licensePlate[k] << endl;
                if(lp_char_val[tolower(licensePlate[k])]) lp_char_val[tolower(licensePlate[k])]+=1;
                else
                    lp_char_val[tolower(licensePlate[k])] = 1;
            }
        }
    
        
        while(true){
            string str = strlength.top().second.second;
            //cout << str << endl;
            int len = str.length();
            unordered_map<char,int> wordCharCount;
            
            for(int j=0;j<len;j++){
                if(wordCharCount[tolower(str[j])]) wordCharCount[tolower(str[j])]+=1;
                else
                    wordCharCount[tolower(str[j])] = 1;
            }
            
            bool flag = true;
            for(auto itr = lp_char_val.begin(); itr!= lp_char_val.end(); itr++){
                if(itr->second > wordCharCount[tolower(itr->first)]){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return str;
            
            strlength.pop();
            
        }
        
        
    }
};

/*testcases

"B687015"
["born","give","would","nice","in","understand","blue","force","have","that"]
"GrC8950"
["measure","other","every","base","according","level","meeting","none","marriage","rest"]

*/
