class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        auto canEating = [&](int &mid)
        {
            long h_count = 0;
            for(auto &pile : piles)
                h_count += pile <= mid ? 1 : ceil(double(pile) / mid);
            return h_count <= h;
        };

        int ans = -1, left = 1, right = 1e9, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(canEating(mid)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        return ans;    
    }
};