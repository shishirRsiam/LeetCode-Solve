class Solution {
public:
    vector<int> arr;
    int cache[51][51];
    int solve(int i, int j)
    {
        if(j - i + 1 < 3) return 0;

        int &res = cache[i][j];
        if(res != -1) return res;

        int min_sum = INT_MAX;
        for(int k = i + 1; k < j; k++)
        {
            int cur_sum = (arr[i] * arr[j] * arr[k]) + solve(i, k) + solve(k, j);
            min_sum = min(min_sum, cur_sum);
        }

        return res = min_sum;
    }
    int minScoreTriangulation(vector<int>& values) 
    {
        arr = values;
        memset(cache, -1, sizeof(cache));
        return solve(0, arr.size() - 1);
    }
};