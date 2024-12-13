class Solution {
public:
    int getStep(int n)
    {
        int count = 0;
        while(n != 1)
        {
            count += 1;
            if(n % 2) n = (3 * n) + 1;
            else n /= 2;
        }
        return count;
    }
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int, int>>arr;
        for(int val = lo; val <= hi; val++)
        {
            int power = getStep(val);
            arr.push_back({power, val});
        }
        sort(begin(arr), end(arr));

        return arr[k - 1].second;
    }
};