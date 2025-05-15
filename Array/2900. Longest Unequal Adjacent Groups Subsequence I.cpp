class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ans = []
        i, n = 0, len(words)
        while i < n:
            ans.append(words[i])
            while i < n - 1 and groups[i] == groups[i + 1]:
                i += 1
            i += 1
        return ans



class Solution(object):
    def getLongestSubsequence(self, words, groups):
        flag = 0
        n = len(words)
        arr1, arr2 = [], []
        for i in range(n):
            if flag != groups[i]:
                arr1.append(i)
                flag = groups[i]
        flag = 1
        for i in range(n):
            if flag != groups[i]:
                arr2.append(i)
                flag = groups[i]
                
        arr = arr1
        if len(arr2) > len(arr1):
            arr = arr2
            
        ans = []
        for index in arr:
            ans.append(words[index])
        return ans