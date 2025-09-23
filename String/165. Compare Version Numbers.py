class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def spliteVersion(s, code=""):
            arr = []
            for ch in s:
                if ch == '.':
                    arr.append(int(code))
                    code = ""
                else:
                    code += ch
            while arr and arr[-1] == 0:
                arr.pop()
            return arr

        v1_arr = spliteVersion(version1 + ".")
        v2_arr = spliteVersion(version2 + ".")
        if v1_arr == v2_arr:
            return 0

        n = min(len(v1_arr), len(v2_arr))
        for i in range(n):
            if v1_arr[i] < v2_arr[i]:
                return -1
            if v1_arr[i] > v2_arr[i]:
                return 1

        return 1 if len(v1_arr) > len(v2_arr) else -1
    


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def spliteVersion(s, code=""):
            arr = []
            for ch in s:
                if ch == '.':
                    arr.append(code)
                    code = ""
                else:
                    code += ch
            while arr and int(arr[-1]) == 0:
                arr.pop()
            return arr

        v1_arr = spliteVersion(version1 + ".")
        v2_arr = spliteVersion(version2 + ".")

        n = min(len(v1_arr), len(v2_arr))
        for i in range(n):
            if int(v1_arr[i]) < int(v2_arr[i]):
                return -1
            if int(v1_arr[i]) > int(v2_arr[i]):
                return 1

        v1_sum =  sum([int(s) for s in v1_arr])
        v2_sum =  sum([int(s) for s in v2_arr])

        if v1_sum < v2_sum:
            return -1
        if v1_sum > v2_sum:
            return 1
        return 0
    