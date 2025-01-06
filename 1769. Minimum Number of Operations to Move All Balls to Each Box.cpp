class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int>idx, ans;
        int n = boxes.size();
        for(int i=0;i<n;i++)
            if(boxes[i] == '1') 
                idx.push_back(i);
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(auto ii:idx)
                sum += abs(ii - i);
            ans.push_back(sum);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size(), oneCount = 0, op = 0;
        vector<int>ans(n);

        for(int i=0;i<n;i++)
        {
            ans[i] = op;
            oneCount += boxes[i] == '1';
            op += oneCount;
        }
        oneCount = op = 0;
        for(int i=n-1;i>=0;i--)
        {
            ans[i] += op;
            oneCount += boxes[i] == '1';
            op += oneCount;
        }
        return ans;
    }
};