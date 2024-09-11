class Solution(object):
    def minBitFlips(self, start, goal):
        return bin(start ^ goal).count('1')   