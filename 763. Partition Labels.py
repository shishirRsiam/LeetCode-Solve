class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        def get_index(ch):
            return ord(ch) - ord('a')

        n = len(s)
        max_idx = [0] * 26
        for i, ch in enumerate(s):
            max_idx[get_index(ch)] = i

        ans = []
        i, cur, next_partition = 0, -1, max_idx[get_index(s[0])]
        while next_partition < n:
            while i <= next_partition:
                next_partition = max(next_partition, max_idx[get_index(s[i])])
                i += 1
            ans.append(next_partition - cur)
            if i == n: break
            cur = next_partition
            next_partition = max_idx[get_index(s[i])]

        return ans