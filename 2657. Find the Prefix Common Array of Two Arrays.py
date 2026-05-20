class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        n = len(A)
        unique_vals = set()
        for i in range(n):
            unique_vals.add(A[i])
            unique_vals.add(B[i])

            count = 0 
            for target in unique_vals:
                count += target in A[:i+1] and target in B[:i+1]
            ans.append(count)    

        return ans