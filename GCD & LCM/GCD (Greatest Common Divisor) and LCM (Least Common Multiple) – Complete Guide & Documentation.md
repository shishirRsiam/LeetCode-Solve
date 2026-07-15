# GCD (Greatest Common Divisor) and LCM (Least Common Multiple) – Complete Guide & Documentation

**Class:** Programming and Mathematics (For 9th–12th grade and university students)  
**Language:** English

---

## 1. Introduction

In the world of mathematics and computer programming, **GCD** (Greatest Common Divisor) and **LCM** (Least Common Multiple) are two fundamental and highly important concepts. They are widely used in simplifying fractions, number theory, cryptography, and various algorithm designs. In this documentation, we will discuss the mathematical definitions of these two concepts, their core relationship, and the most efficient algorithm for computing them—the Euclidean Algorithm. We will also look at their implementation in **Python** and **C++**.

---

## 2. Mathematical Definition

### 2.1. GCD (Greatest Common Divisor)
The **Greatest Common Divisor** of two or more integers is the largest positive integer that divides each of the numbers completely (leaving a remainder of 0).

> **Example:** The divisors of 12 and 18 are:
> * 12 = 1, 2, 3, 4, 6, 12
> * 18 = 1, 2, 3, 6, 9, 18
>
> The common divisors are 1, 2, 3, and 6. The largest among them is **6**.
> ∴ GCD(12, 18) = 6

### 2.2. LCM (Least Common Multiple)
The **Least Common Multiple** of two or more integers is the smallest positive integer that is divisible by each of the numbers completely.

> **Example:** The multiples of 12 and 18 are:
> * Multiples of 12: 12, 24, 36, 48, 72...
> * Multiples of 18: 18, 36, 54, 72...
>
> The common multiples are 36, 72... The smallest among them is **36**.
> ∴ LCM(12, 18) = 36

---

## 3. The Core Relationship Between GCD and LCM

For two numbers \( a \) and \( b \), there is a fundamental mathematical formula:

> \[
> \boxed{\text{GCD}(a, b) \times \text{LCM}(a, b) = a \times b}
> \]

This means that if we can compute the GCD, we can easily find the LCM:

> \[
> \text{LCM}(a, b) = \frac{a \times b}{\text{GCD}(a, b)}
> \]

**Caution:** In actual code, if the numbers are very large, calculating \( a \times b \) first might cause an **Integer Overflow**. Therefore, it is safer to perform the division first, i.e., \( (a / \text{GCD}) \times b \).

---

## 4. The Efficient Method: Euclidean Algorithm

The oldest and fastest method to find the GCD is the **Euclidean Algorithm**. It is based on the simple principle:

> \[
> \text{GCD}(a, b) = \text{GCD}(b, a \mod b)
> \]
> Continue this until \( b = 0 \). When \( b = 0 \), \( a \) is the GCD.

**Steps:**
1. If `b` equals 0, return `a`.
2. Otherwise, compute the remainder when `a` is divided by `b` (`a % b`).
3. Set `a = b` and `b = remainder`.
4. Go back to step 1.

**Example (12 and 18):**
*   GCD(12, 18) → GCD(18, 12%18 = 12) → GCD(18, 12)
*   GCD(18, 12) → GCD(12, 18%12 = 6) → GCD(12, 6)
*   GCD(12, 6) → GCD(6, 12%6 = 0) → GCD(6, 0)
*   Since b = 0, the answer is **6**.

**Time Complexity:** \( O(\log \min(a, b)) \) – which is extremely fast.

---

## 5. Implementation in Python

Python makes writing the Euclidean Algorithm very straightforward. Using Python's tuple unpacking, we can write compact code.

```python
# 1. Function to find GCD - Euclidean Algorithm (Iterative)
def gcd(a, b):
    while b != 0:
        a, b = b, a % b  # Simultaneously assign a = b and b = remainder
    return abs(a)  # Return absolute value to handle negative numbers

# 2. Function to find LCM
def lcm(a, b):
    if a == 0 or b == 0:
        return 0  # Check to avoid division by zero
    return abs(a // gcd(a, b) * b)  # Divide first, then multiply to avoid overflow

# ---------- Driver Code ----------
if __name__ == "__main__":
    num1 = 12
    num2 = 18
    
    g = gcd(num1, num2)
    l = lcm(num1, num2)
    
    print(f"Numbers: {num1} and {num2}")
    print(f"GCD: {g}")
    print(f"LCM: {l}")
    
    # Verify the relationship
    print(f"\nVerification: GCD * LCM = {g} * {l} = {g * l}")
    print(f"a * b = {num1} * {num2} = {num1 * num2}")
```

**Output:**
```
Numbers: 12 and 18
GCD: 6
LCM: 36

Verification: GCD * LCM = 6 * 36 = 216
a * b = 12 * 18 = 216
```

---

## 6. Implementation in C++

When coding in C++, you must always be mindful of **Integer Overflow**. Therefore, when calculating LCM, use the formula \( (a / gcd) \times b \) to stay safe. While C++17 provides `std::gcd` in the `<numeric>` header, we will write our own functions for better understanding.

```cpp
#include <iostream>
#include <cstdlib> // For abs() function
using namespace std;

// 1. Function to find GCD - Euclidean Algorithm (Iterative)
int gcd(int a, int b) {
    a = abs(a); // Handle negative numbers
    b = abs(b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 2. Function to find LCM
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0; // Check to avoid division by zero
    }
    a = abs(a);
    b = abs(b);
    
    // To avoid overflow, divide first (a / gcd) then multiply by b
    return (a / gcd(a, b)) * b;
}

// ---------- Driver Code ----------
int main() {
    int num1 = 12;
    int num2 = 18;
    
    int g = gcd(num1, num2);
    int l = lcm(num1, num2);
    
    cout << "Numbers: " << num1 << " and " << num2 << endl;
    cout << "GCD: " << g << endl;
    cout << "LCM: " << l << endl;
    
    // Verify the relationship
    cout << "\nVerification: GCD * LCM = " << g << " * " << l << " = " << g * l << endl;
    cout << "a * b = " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    
    return 0;
}
```

**Output:**
```
Numbers: 12 and 18
GCD: 6
LCM: 36

Verification: GCD * LCM = 6 * 36 = 216
a * b = 12 * 18 = 216
```

---

## 7. Extension for Multiple Numbers

If you need to find the GCD or LCM of more than two numbers, you can compute them **pairwise**:

> \[
> \text{GCD}(a, b, c) = \text{GCD}(\text{GCD}(a, b), c)
> \]

Similarly for LCM:

> \[
> \text{LCM}(a, b, c) = \text{LCM}(\text{LCM}(a, b), c)
> \]

**Example (Python):**
```python
from functools import reduce

numbers = [12, 18, 24]
gcd_all = reduce(gcd, numbers)  # 12,18 -> 6 ; 6,24 -> 6
lcm_all = reduce(lcm, numbers)  # 12,18 -> 36 ; 36,24 -> 72
```

---

## 8. Conclusion & Best Practices

1.  **Always use the Euclidean Algorithm for GCD.** It can be written iteratively or recursively. The iterative approach avoids the risk of stack overflow, making it safer.
2.  **Avoid Overflow:** When calculating LCM, never write \( (a \times b) / \text{GCD} \) directly. Always use \( (a / \text{GCD}) \times b \).
3.  **Handle Negative Numbers:** Most algorithms work on positive integers. Always convert inputs to their absolute values using `abs()` or equivalent functions.
4.  **Built-in Functions:** C++17 offers `std::gcd` and `std::lcm` (in `<numeric>`), and Python has `math.gcd` (Python 3.5+) and `math.lcm` (Python 3.9+). However, understanding the underlying logic to write your own code is the most important skill.

I hope this documentation gives you a complete understanding of GCD and LCM. Please run the code yourself and test it with various inputs.

**Best of luck!**  