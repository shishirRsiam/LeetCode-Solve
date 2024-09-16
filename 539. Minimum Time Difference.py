class Solution(object):
    def timeConvertToMinutes(self, time):
        hourToMinute = int(time[:2]) * 60
        minute = int(time[3:])
        return hourToMinute + minute

    def findMinDifference(self, timePoints):
        # Sort the time points
        timePoints.sort()

        # Add the first time point again at the end to account for the circular nature of time
        timePoints.append(timePoints[0])

        ans = float('inf')
        n = len(timePoints)


        # Loop through the time points to find the minimum difference
        for i in range(n - 1):
            time_one = self.timeConvertToMinutes(timePoints[i])
            time_two = self.timeConvertToMinutes(timePoints[i + 1])

            # // Calculate the difference between consecutive time points
            ans = min(ans, abs(time_one - time_two))

            # Calculate the difference considering the circular nature of time
            ans = min(ans, abs(time_one - (1440 + time_two)))

        return ans