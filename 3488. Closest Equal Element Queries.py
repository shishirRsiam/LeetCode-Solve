class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        store = defaultdict(list)
        for i in range(n):
            store[nums[i]].append(i)
        
        def get_index(arr, target):
            i, j = 0, len(arr) - 1
            ans = 10**10
            while i <= j:
                mid = (i + j) // 2
                if arr[mid] <= target:
                    ans = mid
                    i = mid + 1
                else: j = mid - 1
            return ans

        ans = []
        qs = len(queries)
        for i in range(qs):
            found_array = store[nums[queries[i]]]
            f_n = len(found_array)
            if f_n == 1:
                ans.append(-1)
                continue

            index = get_index(found_array, queries[i])
            res = 10 ** 10
            if index:
                dist = abs(found_array[index - 1] - queries[i])
                res = min(res, dist, n - dist)
            if index < f_n - 1:
                dist = abs(found_array[index + 1] - queries[i])
                res = min(res, dist, n - dist)

            dist = abs(found_array[0] - queries[i])
            res = min(res, n - dist)

            dist = abs(found_array[f_n - 1] - queries[i])
            res = min(res, n - dist)

            ans.append(res)
        return ans