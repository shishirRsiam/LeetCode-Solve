class Solution(object):
    def checkTwoChessboards(self, coordinate1, coordinate2):
        # Convert coordinates to ASCII and add their values
        one = ord(coordinate1[0]) + int(coordinate1[1])
        two = ord(coordinate2[0]) + int(coordinate2[1])

        # Return true if both sums have the same parity
        return one % 2 == two % 2