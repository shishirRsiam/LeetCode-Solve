class Solution:
    def delta(self, pass_count, total):
        return ((pass_count + 1) / (total + 1)) - (pass_count / total)
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        maxHeap = []
        for passed, total in classes:
            heappush(maxHeap, (-self.delta(passed, total), passed, total))
        
        for _ in range(extraStudents):
            delta, passed, total = heappop(maxHeap)
            passed += 1
            total += 1
            heappush(maxHeap, (-self.delta(passed, total), passed, total))
        
        result = 0.0
        while maxHeap:
            _, passed, total = heappop(maxHeap)
            result += passed / total
        
        return result / len(classes)