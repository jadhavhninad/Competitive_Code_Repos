#https://leetcode.com/contest/weekly-contest-77/problems/unique-morse-code-words/

class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        charList = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        morsewords=[];
        for word in words:
            morseword=""
            for char in word:
                morseword += charList[ord(char) - ord('a')]
            if morseword in morsewords:
                continue
            else:
                morsewords.append(morseword)
        
        return len(morsewords)