class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()

        n = len(arr)
        min_abs = 10**10
        for i in range(n - 1):
            min_abs = min(min_abs, abs(arr[i] - arr[i + 1]))
        
        ans = []
        for i in range(n - 1):
            if abs(arr[i] - arr[i + 1]) == min_abs:
                ans.append([arr[i], arr[i + 1]])
        return ans