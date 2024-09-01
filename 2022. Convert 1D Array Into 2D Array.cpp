class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        // Create a 2D vector 'ans' to store the final 2D array
        vector<vector<int>> ans;
        
        // Check if the total number of elements (m * n) matches the size of the original array
        // If not, return an empty 2D vector
        if(n * m != original.size()) return ans;

        int cnt = 0; // Counter to track the number of elements added to a row
        vector<int> temp; // Temporary vector to store the current row

        // Iterate through each element in the original array
        for(int val : original)
        {
            temp.push_back(val); // Add the current element to the current row
            cnt++; // Increment the counter
            
            // If the current row is full (contains 'n' elements)
            if(cnt == n)
            {
                cnt = 0; // Reset the counter
                ans.push_back(temp); // Add the completed row to the 2D array
                temp.clear(); // Clear the temporary vector for the next row
            }
        }
        return ans; // Return the constructed 2D array
    }
};