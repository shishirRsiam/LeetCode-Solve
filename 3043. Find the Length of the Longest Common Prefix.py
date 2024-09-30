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