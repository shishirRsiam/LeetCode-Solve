class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int i = 0, j = colors.size()-1, ans;
        while(i<=j)
        {
            if(colors[i] != colors[j])
            {
                ans = j-i;
                break;
            }
            j--;
        }
        i = 0;
        while(colors[i] == colors.back()) i++;
        return max(ans, int(colors.size())-i-1);
        return -1;
    }
};