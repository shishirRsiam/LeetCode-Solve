class Solution:
    def countLargestGroup(self, n: int) -> int:
        max_count = 0
        count = defaultdict(int)
        for val in range(1, n + 1):
            sum = 0
            for ch in str(val):
                sum += ord(ch) - ord('0')
            count[sum] += 1
            max_count = max(max_count, count[sum])
        
        ans = 0
        for val in count:
            ans += count[val] == max_count
        return ans