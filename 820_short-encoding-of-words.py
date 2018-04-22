#https://leetcode.com/contest/weekly-contest-81/problems/short-encoding-of-words/

'''
USE A TRIE TO INSERT THE WORDS IN REVERSE ORDER. 
During insertion check if words already there or if atleast on of the indexs is non zero
'''
class TrieNode:
    def __init__(self):
        self.nodes = [None]*26
        self.word = False
    
        
class Solution:

    def __init__(self):
        self.root = TrieNode()  

    def insert(self, word):
        walker = self.root
        for i in range(len(word)):
            index = ord(word[i]) - ord('a')

            if not walker.nodes[index]:
                walker.nodes[index] = TrieNode()
            
            walker = walker.nodes[index]
        
        if walker.word: #detect if the word is already there
            return True
        
        walker.word = True
        
        for i in range(26):
            if walker.nodes[i]:
                return True
        
        return False
    
    def minimumLengthEncoding(self, words):
        words.sort(key=len, reverse=True)
        
       # print(words)
        lw = len(words)
            
        for i in range(lw):
            ret_val = self.insert(words[i][::-1])
            #print(ret_val)
            if ret_val:
                words[i]=""
            #print("word is", words[i])
        
        #print(words)
        length_fin = 0
        count=0
        for i in range(lw):
            if words[i] != "":
                length_fin += len(words[i])
                count+=1
    
        return  length_fin + count
    
    
    
    #=====================This leads to TLE===========================================
    def minimumLengthEncodingTLE(self, words):

        count = 0
        lw = len(words)
        for i in range(lw):
            
            if words[i] != "":
                for j in range(lw):
                    #if( len(words[i]) <= len(words[j]) and j != i):
                    if(j != i):
                        #print("j_wprd = ", words[j])
                        lst = len(words[j])
                        tmp = words[j][ lst-len(words[i]) : lst]
                        #print("tmp = ", tmp)
                        if ( tmp == words[i]):
                            words[i]=""
                            break
        
        #print(words)
        length_fin = 0
        for i in range(lw):
            if words[i] != "":
                length_fin += len(words[i])
                count+=1
            
        return  length_fin + count
                       
            
