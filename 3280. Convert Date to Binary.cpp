class Solution {
public:
    // Function to convert a bitset to a binary string and remove leading zeros.
    string getBinaryString(bitset<32>& bits) {
        // Convert the bitset to a binary string representation.
        string s = bits.to_string();
        // Find the index of the first '1' in the binary string.
        int idx = s.find('1');
        // Return the substring starting from the first '1' to remove leading zeros.
        return s.substr(idx);
    }
    
    string convertDateToBinary(string date) {
        // Extract the year, month, and day from the input date string.
        bitset<32> year(stoi(date.substr(0, 4)));    // Convert the first 4 characters (year) to an integer and then to a bitset.
        bitset<32> month(stoi(date.substr(4, 2)));   // Convert the next 2 characters (month) to an integer and then to a bitset.
        bitset<32> day(stoi(date.substr(6, 2)));     // Convert the last 2 characters (day) to an integer and then to a bitset.
        
        // Get the binary string for year, month, and day, removing leading zeros.
        string ans = getBinaryString(year);
        ans += "-" + getBinaryString(month);
        ans += "-" + getBinaryString(day);
        
        // Return the final binary string representation of the date.
        return ans;
    }
};