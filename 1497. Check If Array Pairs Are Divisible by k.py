class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        // Create a hash map to store the frequency of remainders when divided by k
        unordered_map<int, int> mp;
        
        // Loop through each value in the array
        for(auto val : arr)
        {
            // Calculate remainder after dividing by k, ensuring it's positive
            int mod = ((val % k) + k) % k;
            // Increment the frequency of this remainder in the map
            mp[mod]++;
        }

        // Loop through each remainder and its count in the map
        for(auto [rem, cnt] : mp)
        {
            // Case 1: if the remainder is 0, we need an even count of such elements 
            // because they must pair with another element of remainder 0
            if(not rem) 
            {
                if(cnt % 2) return false;  // If the count is odd, pairing is not possible
            }
            // Case 2: if remainder is exactly half of k (e.g., k=6, rem=3),
            // we also need an even count of such elements to pair with themselves
            else if(rem + rem == k)
            {
                if(cnt % 2) return false;  // If count is odd, pairing is not possible
            }
            // Case 3: for other remainders, the count of current remainder 
            // must match the count of (k - remainder) for them to pair up
            else if(mp[rem] != mp[k - rem]) return false; // If counts don't match, return false
        }
        
        // If all conditions are satisfied, return true (i.e., it's possible to arrange pairs)
        return true;
    }
};