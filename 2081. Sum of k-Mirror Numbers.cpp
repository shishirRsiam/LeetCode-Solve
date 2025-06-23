class Solution {
public:
    bool checkIsMirror(long haha, int k)
    {
        string s = to_string(haha), ok;
        if(s[0] == '0') return false;
        
        long num = haha;
        while(num)
        {
            int mod = num % k;
            num = num / k;
            ok += (mod + '0');

            if(ok[0] == '0') break;
        }
        if(ok[0] == '0') return false;

        auto temp = ok;
        reverse(begin(temp), end(temp));
        return (temp == ok);
    }
    
    long ans = 0;
    void generatePalindromes(int n, int k, int &count) 
    {
        if(not count) return;

        vector<long> store;
        if (n == 1) 
        {
            for (int i = 0; i <= 9; i++)
                store.push_back(i);

            for(long haha : store)
            {
                if(not count) return;
                if(checkIsMirror(haha, k))
                    count -= 1, ans += haha;
            }
            return;
        }

        int half = n / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; i++) 
        {
            string left = to_string(i), right = left;
            reverse(right.begin(), right.end());

            if (n % 2 == 0) store.push_back(stoll(left + right));
            else 
                for (char mid = '0'; mid <= '9'; mid++) 
                    store.push_back(stoll(left + mid + right));
        }

        for(long haha : store)
        {
            if(not count) return;
            if(checkIsMirror(haha, k))
                count -= 1, ans += haha;
        }
    }

    long long kMirror(int k, int n) 
    {
        for(int l = 1; l < 12; l++)
        {
            string s(l, '0');
            generatePalindromes(l, k, n);
        }

        return ans;
    }
};