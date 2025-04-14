class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans, n = 0, len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if abs(arr[i] - arr[j]) > a:
                        continue
                    if abs(arr[j] - arr[k]) > b:
                        continue
                    if abs(arr[i] - arr[k]) > c:
                        continue
                    ans += 1
        return ans