class Solution:
    def minimumSwaps(self, arr):
        n, swaps = len(arr), 0
        store = [(arr[i], i) for i in range(n)]
        store.sort()
        
        visited = [0] * n
        for i in range(n):
            if visited[i] or i == store[i][1]: continue

            x, cycle_count = i, 0
            while not visited[x]:
                visited[x] = 1
                x = store[x][1]
                cycle_count += 1
            swaps += cycle_count - 1

        return swaps

    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        minSwaps = 0
        queue = deque([root])
        while(queue):
            arr = []
            n = len(queue)
            for _ in range(n):
                node = queue.popleft()
                arr.append(node.val)

                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            minSwaps += self.minimumSwaps(arr)

        return minSwaps