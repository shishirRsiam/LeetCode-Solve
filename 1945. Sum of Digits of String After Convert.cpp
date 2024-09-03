class Solution {
public:
    // Helper function to calculate the sum of digits of a string representation of a number.
    string getValue(string s) {
        int sum = 0, val;
        // Iterate through each character in the string 's'
        for(auto ch : s) {
            // Convert the character to its corresponding integer value
            val = ch - '0';
            // Add the integer value to the sum
            sum += val;
        }
        // Return the sum as a string
        return to_string(sum);
    }

    int getLucky(string s, int k) {
        string sum;
        // Convert each character in the string 's' to its corresponding position in the alphabet
        for(auto ch : s) {
            int val = ch - 'a' + 1;
            // Concatenate the string representation of the number to 'sum'
            sum += to_string(val);
        }

        // Repeat the digit sum operation 'k' times
        while(k--) {
            // Update 'sum' by converting it to the sum of its digits using getValue
            sum = getValue(sum);
        }

        // Convert the final string 'sum' back to an integer and return it
        return stoi(sum);
    }
};