class Solution {
public:
    int generateKey(int num1, int num2, int num3) 
    {
        vector<string> vec;  // Create a vector to store the string representations of the numbers

        // Convert each integer to a string and store it in the vector
        vec.push_back(to_string(num1));  // Convert num1 to string and add to the vector
        vec.push_back(to_string(num2));  // Convert num2 to string and add to the vector
        vec.push_back(to_string(num3));  // Convert num3 to string and add to the vector

        // Ensure each string has exactly 4 digits by padding with leading zeros if necessary
        for(int i = 0; i < 3; i++)  // Loop over each string in the vector
        {
            for(int j = vec[i].size(); j < 4; j++)  // If the string has less than 4 digits
                vec[i].insert(vec[i].begin(), '0');  // Insert '0' at the beginning of the string
            
            cout << vec[i] << endl;  // Output the padded string for debugging purposes
        }
        
        string ans;  // Initialize an empty string to store the final result

        // Iterate over each digit position (0 to 3) in the strings
        for(int i = 0; i < 4; i++) 
        {
            // Find the minimum character at the current position across all three strings
            char ch = min({vec[0][i], vec[1][i], vec[2][i]});
            // Append the minimum character to the result string
            ans += ch;
        }

        // Convert the resulting string back to an integer and return it
        return stoi(ans);
    }
};