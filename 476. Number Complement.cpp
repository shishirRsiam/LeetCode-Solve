class Solution {
public:
    int findComplement(int num) 
    {
        bitset<32>bit(num);
        string s = bit.to_string();

        bool flag = false;
        for(auto &ch:s)
        {
            if(ch == '1') flag = true;
            if(flag)
                ch = (ch == '1' ? '0' : '1');
        }
        int number = stoi(s, NULL, 2);
        return number;
    }
};