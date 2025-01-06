class Solution(object):
    def minOperations(self, boxes):
        n = len(boxes)
        ans = [0]*n
        count = op = 0
        for i in range(n):
            ans[i] = op
            count += boxes[i] == '1'
            op += count
        op = count = 0
        for i in range(n-1, -1, -1):
            ans[i] += op
            count += boxes[i] == '1'
            op += count
        return ans