class Solution {
public:
    int checkAllPossible(int val, vector<int>& tops, vector<int>& bottoms)
    {
        int n = tops.size();
        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(tops[i] == val) continue;
            if(bottoms[i] != val)
            {
                count1 = n;
                break;
            }
            count1 += 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(bottoms[i] == val) continue;
            if(tops[i] != val)
            {
                count2 = n;
                break;
            }
            count2 += 1;
        }
        return min(count1, count2);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int ans = tops.size();
        for(int val = 1; val <= 6; val++)
            ans = min(ans, checkAllPossible(val, tops, bottoms));
        return ans == tops.size() ? -1 : ans; 
    }
};