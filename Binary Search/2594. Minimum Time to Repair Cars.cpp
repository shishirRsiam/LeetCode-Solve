class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) 
        {
            auto canRepair = [&](long &mid)
            {
                int repairedCar = 0;
                for(auto &rank : ranks)
                {
                    repairedCar += long(sqrt(mid / rank));
                    if (repairedCar >= cars) return true;
                }
                return false;
            };
    
    
            long left = 1, right = 1e15, mid;
            while(left <= right)
            {
                mid = left + (right - left) / 2;
                if(canRepair(mid)) right = mid - 1;
                else left = mid + 1;
            }
            return left;    
        }
    };