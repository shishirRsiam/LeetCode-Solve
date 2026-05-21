class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        store = set()
        st1 = set(arr1)
        st2 = set(arr2)

        for val in arr2:
            cur = ""
            s = str(val)
            for ch in s:
                cur += ch
                if int(cur) not in store:
                    store.add(int(cur))

        ans = 0
        for val in st1:
            cur = ""
            s = str(val)
            for ch in s:
                cur += ch
                if int(cur) in store:
                    ans = max(ans, int(len(cur)))
        return ans
    

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        count = {}
        for val in arr1:
            s = str(val)
            n = len(s)
            for i in range(n):
                cur = s[:i+1]
                if cur not in count:
                    count[cur] = 0
                count[cur] =+ 1

        ans = 0
        for val in arr2:
            s = str(val)
            n = len(s)
            for i in range(n):
                cur = s[:i+1]
                if cur in count:
                    ans = max(ans, len(cur))
        return ans