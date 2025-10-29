class Solution:
    def smallestNumber(self, n: int) -> int:
        binary_string = ""
        binary_string_lenth = len(bin(n)[2:])
        for _ in range(binary_string_lenth):
            binary_string += "1"
        return int(binary_string, 2)