## Development Environment

The source code provided in this repository is written in C programming language. To compile and run the code, you can simply use a online C editor like the one shared below. It will require you to input a value.

I recommend running the code using [programiz](https://www.programiz.com/c-programming/online-compiler). You can copy and paste the code into the respective online compiler and execute it. Then input any value.

Result using the number 10 would look like:
![image](https://github.com/waleed-wajdan/BitnineInternshipTest/assets/135476607/792b44e7-b882-49a8-ac7c-5b31b9a109b6)


# Quick Review of Fibonacci Functions with Time Complexity Analysis

Below is a summary of three different functions for calculating Fibonacci numbers and their respective time complexities:

## Func1: Naive Recursive Implementation
**Advantages:**
- Simple and easy to understand the implementation.
- Directly follows the mathematical definition of the Fibonacci sequence.
- Suitable for small inputs and educational purposes.

**Disadvantages:**
- Exponential time complexity due to redundant calculations.
- Highly inefficient for large inputs.
- Prone to causing a stack overflow for significantly large values of `n`.

## Func2: Recursive Implementation with Memoization
**Advantages:**
- Utilizes memoization to store previously computed values, reducing redundant calculations.
- Improves efficiency compared to func1, making it suitable for moderate-sized inputs.
- Maintains the simplicity of recursion.

**Disadvantages:**
- Still involves recursion, which may lead to a stack overflow for very large `n`.
- May consume significant memory space to store the memoization array for large values of `n`.
- Slightly more complex than the naive recursive approach.

## Func3: Iterative Implementation with Bottom-Up Approach
**Advantages:**
- Efficient linear time complexity, making it highly suitable for large inputs.
- Does not rely on recursion, avoiding potential stack overflow issues.
- Utilizes less memory compared to func2 since it does not require memoization.

**Disadvantages:**
- Slightly more complex than func1.
- May be less intuitive for those unfamiliar with the bottom-up approach.
- Requires explicit implementation of the iterative logic.

In summary, Func1 is simple but inefficient for large inputs, Func2 improves efficiency with memoization but still has recursion-related drawbacks, and Func3 is the most efficient and memory-friendly implementation. The choice of which implementation to use depends on the specific requirements and constraints of the problem at hand. For most cases, Func3 would be the preferred choice due to its superior efficiency and practicality for calculating Fibonacci numbers, especially for larger values of `n`.
