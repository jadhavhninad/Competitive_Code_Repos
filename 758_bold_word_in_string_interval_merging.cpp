#include <functional>
#include <queue>
#include <vector>
#include <iostream>

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >_intervals={};
        vector<pair<int,int>>fin_list={};
        size_t start;
        int end;
        
        for(int i=0;i<words.size();i++){
            start = S.find(words[i]);
            end = int(start) + words[i].length();
            
            while(start != string::npos){
                _intervals.push(make_pair(start,end));
                start = S.find(words[i],start+1);
                end = int(start) + words[i].length();
            }
            
        }
        
        
        int n_s=0, n_e=0,temp_s=0,temp_e=0;
        
        while(!_intervals.empty()){
            temp_s = _intervals.top().first;
            temp_e = _intervals.top().second;
            cout << temp_s << "," << temp_e << endl;
            if(n_e ==0 ){
                n_s = temp_s;
                n_e = temp_e;
            }
            else if(temp_s <= n_e){
                n_e = max(n_e,temp_e);
            }
            else{
                //cout << n_s << "," << n_e << endl;
                fin_list.push_back(make_pair(n_s,n_e));
                n_s = temp_s;
                n_e = temp_e;
            }
            _intervals.pop();
        }
        
        if(n_e != 0)
            fin_list.push_back(make_pair(n_s,n_e));
        
        if(fin_list.size() ==0 || S.length()==0)
            return S;
        
        int _first=0,_last=0,shift=0;
        for(int i=0;i<fin_list.size();i++){
            _first = fin_list[i].first;
            _last = fin_list[i].second;
            S.insert(_last+shift,"</b>");
            S.insert(_first+shift,"<b>");
            shift+=7;
        }
        cout << "loop3 done" << endl;
        return S;
    }
};

