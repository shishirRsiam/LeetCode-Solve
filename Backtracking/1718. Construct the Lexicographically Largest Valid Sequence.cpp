class Solution {
    public:
        vector<int> ans;
        bool backtrack(int idx, int &n, vector<int> &arr, vector<bool> &used)
        {
            if(idx == arr.size()) 
            {
                ans = max(ans, arr);
                return true;
            }
            if(arr[idx]) return backtrack(idx + 1, n, arr, used);
    
            for(int i = n; i > 0; i--)
            {
                if(used[i]) continue;
    
                arr[idx] = i;
                used[i] = true;
                if(i == 1)
                {
                    if(backtrack(idx + 1, n, arr, used)) return true;
                } 
                else if(i + idx < arr.size() and not arr[i + idx])
                {
                    arr[i + idx] = i;
                    if(backtrack(idx + 1, n, arr, used)) return true;
    
                    arr[i + idx] = 0;
                }
                arr[idx] = 0;
                used[i] = false;
            }
            return false;
        }
        vector<int> constructDistancedSequence(int n) 
        {
            vector<int> arr(n + n - 1);
            vector<bool> used(n + n - 1);
            backtrack(0, n, arr, used);
            return ans;
        }
    };