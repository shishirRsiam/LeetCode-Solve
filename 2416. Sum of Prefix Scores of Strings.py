# Definition of the TrieNode class
class TrieNode:
    def __init__(self):
        self.count = 0                     # Initialize the count of prefix occurrences to 0
        self.children = [None] * 26        # Initialize the children array with 26 None (for 'a' to 'z')

# Definition of the Solution class
class Solution:
    def sumPrefixScores(self, words: list[str]) -> list[int]:
        root = TrieNode()  # Create the root of the Trie

        # 1. Insert all words into the Trie and count the occurrence of each prefix
        for w in words:
            node = root                     # Start at the root for each word
            for ch in w:
                index = ord(ch) - ord('a')  # Convert character to its corresponding index (0 to 25)
                if not node.children[index]: # If the corresponding TrieNode doesn't exist, create a new one
                    node.children[index] = TrieNode()
                node = node.children[index] # Move to the child node
                node.count += 1             # Increment the count for this prefix

        # 2. Calculate the sum of prefix scores for each word
        ans = []  # List to store the prefix scores for each word

        for w in words:
            sum_score = 0                   # Variable to store the sum of counts for the current word
            node = root                     # Start at the root again
            for ch in w:
                index = ord(ch) - ord('a')  # Convert character to index
                node = node.children[index] # Move to the corresponding child node
                sum_score += node.count     # Add the count of this prefix to the sum
            ans.append(sum_score)           # Store the result in the answer list

        return ans                          # Return the final result
