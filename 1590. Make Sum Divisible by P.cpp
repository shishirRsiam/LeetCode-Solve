class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        long sum = 0;

        // Calculate the total sum of the array
        for (auto val : nums)
            sum += val;

        // Calculate the remainder when the total sum is divided by p
        long target = sum % p;

        // If the total sum is already divisible by p, return 0 (no need to remove any subarray)
        if (target == 0)
            return 0;

        // Use a hash map to store remainders of prefix sums and their corresponding indices
        unordered_map<long, int> mp;

        int n = nums.size(); // Size of the array
        int ans = n;         // Initialize the answer to the size of the array (worst case, remove the entire array)

        sum = 0;    // Reinitialize sum to track the prefix sum
        mp[0] = -1; // To handle cases where the entire prefix sum is divisible by p

        // Loop through each element of the array
        for (int i = 0; i < n; i++)
        {
            // Update the prefix sum modulo p
            sum = (sum + nums[i]) % p;

            // Calculate the remainder (mod p) that would make the total divisible by p
            long rem = (sum - target + p) % p;

            // Check if the remainder has been seen before
            // If it has, it means that removing the subarray between mp[rem] and i would make the sum divisible by p
            if (mp.count(rem))
                ans = min(ans, i - mp[rem]); // Update the answer with the smallest subarray length

            // Store the current prefix sum modulo p with its index
            mp[sum] = i;
        }

        // If ans remains equal to n, no valid subarray was found, so return -1
        return ans == n ? -1 : ans;
    }
};
