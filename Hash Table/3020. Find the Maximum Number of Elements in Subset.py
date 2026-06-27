class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        count = Counter(nums)

        ans = 1
        nums = list(set(nums))
        nums.sort()
        if 1 in count:
            ans = max(ans, count[1])
            nums.remove(1)

        for val in nums:
            cur_count, cur_val = 0, val
            while cur_val in count:
                cur_count += 1
                if count[cur_val] == 1:
                    break

                cur_count += 1
                count.pop(cur_val)
                cur_val *= cur_val

            ans = max(ans, cur_count)

        return ans - (ans % 2 == 0)