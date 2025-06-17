int MOD = 1e9 + 7;
using ll = long long;
class Solution {
public:
    ll findPower(ll a, ll b)
    {
        if(b == 0) return 1;

        ll half = findPower(a, b / 2);

        ll result = (half * half) % MOD;
        if(b % 2) result = (result * a) % MOD;

        return result;
    }
    ll nCr(ll n, ll r, vector<ll> &factorial, vector<ll> &fermatFactorial)
    {
        return factorial[n] * fermatFactorial[n - r] % MOD * fermatFactorial[r] % MOD;
    }
    int countGoodArrays(int n, int m, int k) 
    {
        vector<ll> factorial(n + 1, 1), fermatFactorial(n + 1);
        for(int i = 2; i <= n; i++)
            factorial[i] = (factorial[i - 1] * i) % MOD;
        
        for(int i = 0; i <= n; i++)
            fermatFactorial[i] = findPower(factorial[i], MOD - 2);

        ll ans = nCr(n - 1, k, factorial, fermatFactorial);

        return (ans * m % MOD * findPower(m - 1, n - k - 1)) % MOD;
    }
};