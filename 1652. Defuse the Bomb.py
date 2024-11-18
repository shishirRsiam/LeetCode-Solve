class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n

        ans = []
        nums = code + code + code
        for i in range(n, n + n):
            if k > 0:
                ans.append(sum(nums[i + 1 : i + k + 1]))
            else:
                ans.append(sum(nums[i + k : i]))
        return ans