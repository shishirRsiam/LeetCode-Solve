class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        s = self.countAndSay(n - 1)

        count, l = 1, len(s)
        convert, prev = "", s[0]
        for i in range(1, l):
            if s[i] == prev: 
                count += 1
            else:
                convert += str(count) + prev
                prev = s[i]
                count = 1
        return convert + str(count) + prev