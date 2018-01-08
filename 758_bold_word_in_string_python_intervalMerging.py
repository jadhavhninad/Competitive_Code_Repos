//https://leetcode.com/contest/weekly-contest-66/problems/bold-words-in-string/
//758 - bold words string - using merging intervals python

try:
    import Queue as Q  # ver. < 3.0
except ImportError:
    import queue as Q

class Solution:
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        _intervals = Q.PriorityQueue()
        fin_list=[]
        
        for word in words:
            #print(word)
            start = S.find(word, 0)
            end = start + len(word)
            
            while (start != -1):
                _intervals.put((start,end))
                start = S.find(word, start+1)
                end = start + len(word)
        
        n_s,n_e=0,0
        
        while not _intervals.empty():
            temp_s,temp_e=_intervals.get()
            #print(temp_s,",",temp_e)
            if(n_e == 0):
                n_s = temp_s
                n_e = temp_e
            elif(temp_s <= n_e):
                n_e = max(n_e,temp_e)
            else:
                #print("--------")
                #print(n_s,",",n_e)
                fin_list.append((n_s,n_e))
                n_s,n_e =temp_s,temp_e
                #print("--------")
            
        if(n_e !=0):
            fin_list.append((n_s,n_e))
        
        #while not _intervals.empty():
        #    print(_intervals.get())

        #for val in fin_list:
            #print(val)
        
        if(len(fin_list)==0 or len(S)==0):
            return S
        
        ret = list(S)
        #print(ret)
        shift=0

        for val in fin_list:
            first,last = val
            ret.insert(last+shift,"</b>")
            ret.insert(first+shift,"<b>")
            #print(ret)
            shift+=2
        
        return "".join(ret)
            
