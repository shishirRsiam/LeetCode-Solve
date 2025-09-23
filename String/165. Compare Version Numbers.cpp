class Solution {
public:
    vector<int> getValue(string s)
    {
        vector<int>ret;
        string x;
        for(char c:s)
        {
            if(c=='.')
            {
                ret.push_back(stoi(x));
                x.clear();
            }
            else x += c;
        }
        ret.push_back(stoi(x));
        return ret;
    }
    int compareVersion(string version1, string version2) 
    {
        vector<int> v1 = getValue(version1), v2 = getValue(version2);
        while(v1.size() and v1.back()==0) v1.pop_back();
        while(v2.size() and v2.back()==0) v2.pop_back();
        if(v1 == v2) return 0;

        int n = min(v1.size(), v2.size());
        for(int i=0;i<n;i++)
        {
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }
        return v1.size() > v2.size() ? 1 : -1;
    }
};