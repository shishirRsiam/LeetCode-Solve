// Definition of a TrieNode
class TrieNode
{
public:
    int count;              // This will store the count of words sharing the current prefix
    TrieNode *children[26]; // Array to hold pointers to the next TrieNode for each letter (26 lowercase letters)

    // Constructor
    TrieNode() : count(0), children{NULL} {} // Initialize count to 0, and all children pointers to NULL (nullptr)
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        // Create the root of the Trie
        auto *root = new TrieNode();

        // 1. Insert each word into the Trie and count the occurrence of each prefix
        for (auto w : words)
        {                      // Iterate through each word in the list of words
            auto *node = root; // Start from the root node for each word

            // Insert each character of the word into the Trie
            for (auto ch : w)
            {                         // For each character in the word:
                int assci = ch - 'a'; // Convert the character to its index ('a' = 0, 'b' = 1, ..., 'z' = 25)

                // If the corresponding TrieNode doesn't exist, create a new node
                if (!node->children[assci])
                    node->children[assci] = new TrieNode();

                // Move to the next TrieNode (child)
                node = node->children[assci];

                // Increment the count for this prefix (each prefix is counted as it appears)
                node->count += 1;
            }
        }

        // 2. Calculate the sum of prefix scores for each word
        vector<int> ans; // Vector to store the result (prefix sums for each word)

        // Traverse through the words again to compute their prefix scores
        for (auto w : words)
        {                      // For each word in the list:
            auto sum = 0;      // Variable to store the sum of prefix counts for this word
            auto *node = root; // Start from the root node

            // Traverse through the word in the Trie to compute the sum
            for (auto ch : w)
            {                                 // For each character in the word:
                int assci = ch - 'a';         // Convert the character to its index
                node = node->children[assci]; // Move to the corresponding child node in the Trie

                // Add the current prefix's count to the sum
                sum += node->count;
            }

            // Store the sum of prefix scores for this word in the result vector
            ans.push_back(sum);
        }

        // Return the final result vector containing prefix sums for all words
        return ans;
    }
};
