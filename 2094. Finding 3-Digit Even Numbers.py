class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        store = SortedList()
        for i in range(n):
            if not digits[i]: continue
            for j in range(n):
                if i == j: continue
                for k in range(n):
                    if j == k or digits[k] % 2 or k == i: continue
                    s = str(digits[i]) + str(digits[j]) + str(digits[k])
                    if int(s) not in store:
                        store.add(int(s))
        return list(store)