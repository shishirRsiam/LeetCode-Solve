class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        n, m = len(mat), len(mat[0])
        for i in range(n):
            prev_sum = 0
            for j in range(m):
                prev_sum += mat[i][j]
                mat[i][j] = prev_sum

        def BinarySearchOnAns(val):
            for i in range(n - val + 1):
                for j in range(m - val + 1):

                    square_sum = 0
                    for r in range(i, i + val):
                        right = mat[r][j + val - 1]
                        left = mat[r][j - 1] if j > 0 else 0
                        square_sum += (right - left)

                    if square_sum <= threshold:
                        return True
            return False


        ans = 0
        i, j = 0, min(n, m)
        while i <= j:
            mid = (i + j) // 2
            if BinarySearchOnAns(mid):
                i = mid + 1
                ans = mid
            else:
                j = mid - 1
        return ans