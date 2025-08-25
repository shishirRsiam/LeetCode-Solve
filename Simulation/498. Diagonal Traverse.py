class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        store = defaultdict(deque)
        n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(m):
                index_sum = i + j
                if index_sum % 2:
                    store[index_sum].append(mat[i][j])
                else:
                    store[index_sum].appendleft(mat[i][j])
        return [val for index_sum in store for val in store[index_sum]]