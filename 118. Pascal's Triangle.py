class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for i in range(1, numRows):
            row = [1]
            for j in range(1, i):
                row.append(ans[i - 1][j - 1] + ans[i - 1][j])
            row.append(1)
            ans.append(row)
        return ans