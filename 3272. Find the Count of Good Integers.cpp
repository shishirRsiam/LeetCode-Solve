class Solution {
public:
    long long countGoodIntegers(int n, int k) 
    {
        int digit = (n + 1) / 2;
        int start = pow(10, digit - 1), end = pow(10, digit) - 1;

        unordered_set<string> store;
        for(int num = start; num <= end; num++)
        {
            string leftHalf = to_string(num), rightHalf = leftHalf;
            if(n % 2) rightHalf.pop_back();

            reverse(rightHalf.begin(), rightHalf.end());
            auto fullString = leftHalf + rightHalf;

            if(stoll(fullString) % k) continue;
            sort(fullString.begin(),  fullString.end());
            store.insert(fullString);
        }

        vector<int> factorial(11, 1);
        for(int i = 2; i < 11; i++)
            factorial[i] = factorial[i - 1] * i;

        long long ans = 0;
        for(auto &num : store)
        {
            vector<int> count(11);
            for(auto &ch : num) count[ch - '0'] += 1;

            int totalZero = count[0];
            int totalDigits = num.size();
            int nonZeroDigits = totalDigits - totalZero;

            long perm = (nonZeroDigits * factorial[totalDigits - 1]);
            for(int i = 0; i < 10; i++)
                perm /= factorial[count[i]];
            ans += perm;
        }
        return ans;
    }
};