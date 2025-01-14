class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int> C(n), count(51);
        for(int i = 0; i < n; i++)
        {
            count[A[i]] += 1, count[B[i]] += 1;
            if(i == 0) C[i] = A[i] == B[i];
            else 
            {
                C[i] = C[i - 1];
                if(A[i] == B[i]) C[i] += 1;
                else C[i] += (count[A[i]] == 2) + (count[B[i]] == 2);
            }
        }
        return C;    
    }
};