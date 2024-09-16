
## Intuition and Approach

### Problem Explanation:
We are given a list of time points in 24-hour format (e.g., "23:59", "00:00"). We need to find the minimum difference in minutes between any two time points. Since time is cyclic (i.e., it resets after 24 hours), we also need to account for the time difference between the last and the first time in the list.

#### Approach:
1. Convert Time to Minutes:
We first convert the time points from "HH:MM" format into minutes from the start of the day. For example, "02:30" becomes 2 * 60 + 30 = 150 minutes.

2. Sort the Time Points:
Sorting allows us to easily find the minimum difference between consecutive times. After sorting, the minimum difference will be between consecutive times, except for the last and the first, which needs to be handled separately due to the 24-hour cyclic nature of the time.

3. Find the Minimum Difference:
We compute the difference between consecutive times and keep track of the minimum. For the circular case (last and first times), we compute the difference by considering the total minutes in a day (1440 minutes).

#if it's help, please up ⬆ vote! ❤️

###### Let's Connect on LinkedIn: www.linkedin.com/in/shishirrsiam
###### Let's Connect on Facebook: www.fb.com/shishirrsiam

#Complexity
- Time complexity:
O(nlogn)<!--Add your time complexity here, e.g.$$O(n) $$-->

    - Space complexity : O(n)<!--Add your space complexity here, e.g.$$O(n) $$-->

#Code
```cpp[] class Solution
{
public:
    int timeConvertToMinutes(string time)
    {
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }

    int findMinDifference(vector<string> &timePoints)
    {
        // Sort the time points
        sort(begin(timePoints), end(timePoints));

        // Add the first time point again at the end to account for the circular nature of time
        timePoints.push_back(timePoints[0]);

        // Variable to store the minimum difference
        int ans = INT_MAX, n = timePoints.size(), time_one, time_two;

        // Loop through the time points to find the minimum difference
        for (int i = 0; i < n - 1; i++)
        {
            time_one = timeConvertToMinutes(timePoints[i]);
            time_two = timeConvertToMinutes(timePoints[i + 1]);

            // Calculate the difference between consecutive time points
            ans = min(ans, abs(time_one - time_two));

            // Calculate the difference considering the circular nature of time
            ans = min(ans, abs(time_one - (1440 + time_two)));
        }
        return ans;
    }
};
```