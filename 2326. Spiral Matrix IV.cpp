class Solution {
public:
    // Helper function to get the value of the current ListNode and move to the next node
    int getValue(ListNode* &head)
    {
        int val = -1;  // Default value if no more nodes are left
        if (head)      // If the current ListNode exists
        {
            val = head->val;  // Get the current node's value
            head = head->next;  // Move to the next node
        }
        return val;  // Return the value (either the node's value or -1)
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        // Initialize the boundaries for row and column
        int rowStart = 0, colStart = 0;
        int rowEnd = m - 1, colEnd = n - 1;

        // Initialize the matrix with size m x n, filled with -1
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Keep filling the matrix in spiral order as long as we have nodes and within bounds
        while (head && rowStart <= rowEnd && colStart <= colEnd)
        {
            // Traverse from left to right across the top row
            for (int i = colStart; i <= colEnd; i++) 
            {
                ans[rowStart][i] = getValue(head);  // Fill the current row (rowStart) from colStart to colEnd
            }
            rowStart++;  // Move the top boundary down (one less row to fill)

            // Traverse from top to bottom along the rightmost column
            for (int i = rowStart; i <= rowEnd; i++) 
            {
                ans[i][colEnd] = getValue(head);  // Fill the rightmost column (colEnd) from rowStart to rowEnd
            }
            colEnd--;  // Move the right boundary left (one less column to fill)

            // Traverse from right to left across the bottom row (if still within bounds)
            if (rowEnd >= rowStart) 
            {
                for (int i = colEnd; i >= colStart; i--) 
                {
                    ans[rowEnd][i] = getValue(head);  // Fill the bottom row (rowEnd) from colEnd to colStart
                }
                rowEnd--;  // Move the bottom boundary up (one less row to fill)
            }

            // Traverse from bottom to top along the leftmost column (if still within bounds)
            if (colEnd >= colStart) 
            {
                for (int i = rowEnd; i >= rowStart; i--) 
                {
                    ans[i][colStart] = getValue(head);  // Fill the leftmost column (colStart) from rowEnd to rowStart
                }
                colStart++;  // Move the left boundary right (one less column to fill)
            }
        }

        // Return the filled matrix
        return ans;
    }
};