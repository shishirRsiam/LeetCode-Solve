class Solution(object):
    def gcd(self, a, b):
        # Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
        while b:
            a, b = b, a % b  # Update a to b and b to a % b until b becomes 0
        return a  # Return the GCD

    def insertGreatestCommonDivisors(self, head):
        # Function to insert GCDs between nodes in a linked list
        ans = ListNode(0)  # Create a dummy node to help build the new list
        cur = ans  # Pointer to the last node in the new list

        # Loop through the original linked list until the second last node
        while head.next:
            gcd_val = self.gcd(head.val, head.next.val)  # Calculate GCD of the current and next node values
            
            cur.next = ListNode(head.val)  # Create a new node for the current node's value
            cur.next.next = ListNode(gcd_val)  # Create a new node for the GCD value
            
            head = head.next  # Move to the next node in the original list
            cur = cur.next.next  # Move to the last node in the new list (the newly added GCD node)

        cur.next = ListNode(head.val)  # After exiting the loop, add the last node's value
        
        return ans.next  # Return the new list starting from the first actual node (skipping the dummy node)