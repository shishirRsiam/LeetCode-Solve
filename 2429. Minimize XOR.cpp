class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int num1_count = bitset<33>(num1).count();    
        int num2_count = bitset<33>(num2).count(); 
        string bit = bitset<32>(num1).to_string();

        if(num1_count < num2_count)
        {
            for(int i = 31; i >= 0 and num2_count - num1_count; i--)
                if(bit[i] == '0') bit[i] = '1', num1_count += 1;
        }
        else 
        {
            for(int i = 31; i >= 0 and num1_count - num2_count; i--)
                if(bit[i] == '1') bit[i] = '0', num2_count += 1;
        }
        return int(stoi(bit, NULL, 2));  
    }
};