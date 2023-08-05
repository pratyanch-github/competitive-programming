# Dynamic Programming Patterns

## Introduction

Before diving into the topic, let me introduce myself. I am a Mobile Developer currently working in Warsaw and spending my free time preparing for interviews. I began my interview preparation journey two years ago. Initially, I struggled with even the easy problems and often had to refer to editorials and discussion sections for solutions. However, with consistent effort, I have solved around 800 problems and occasionally participate in contests, solving 3 to 4 problems on average. Now, let's come back to the topic.

## Dynamic Programming and Its Patterns

Recently, I have focused my attention on Dynamic Programming (DP) because it is one of the hardest topics in interview preparation. After solving about 140 DP problems, I have noticed several patterns that can be found in different problems. These patterns can be helpful in solving DP problems effectively. Below are the main patterns I have identified:

### 1. Minimum (Maximum) Path to Reach a Target

**Problem list:** [LeetCode Problem List](https://leetcode.com/list/55ac4kuc)

**Statement:**
Given a target, find the minimum (maximum) cost, path, or sum to reach the target.

**Approach:**
Choose the minimum (maximum) path among all possible paths before the current state, then add the value for the current state.

```
routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]
```

**Top-Down:**
```cpp
for (int j = 0; j < ways.size(); ++j) {
    result = min(result, topDown(target - ways[j]) + cost / path / sum);
}
return memo[/*state parameters*/] = result;
```

**Bottom-Up:**
```cpp
for (int i = 1; i <= target; ++i) {
   for (int j = 0; j < ways.size(); ++j) {
       if (ways[j] <= i) {
           dp[i] = min(dp[i], dp[i - ways[j]] + cost / path / sum) ;
       }
   }
}
return dp[target];
```

**Similar Problems:**
- 746. Min Cost Climbing Stairs (Easy)
- 64. Minimum Path Sum (Medium)
- 322. Coin Change (Medium)
- 931. Minimum Falling Path Sum (Medium)
- and more...

### 2. Distinct Ways

**Problem List:** [LeetCode Problem List](https://leetcode.com/list/55ajm50i)

**Statement:**
Given a target, find the number of distinct ways to reach the target.

**Approach:**
Sum all possible ways to reach the current state.

```
routes[i] = routes[i-1] + routes[i-2], ... , + routes[i-k]
```

**Top-Down:**
```cpp
for (int j = 0; j < ways.size(); ++j) {
    result += topDown(target - ways[j]);
}
return memo[/*state parameters*/] = result;
```

**Bottom-Up:**
```cpp
for (int i = 1; i <= target; ++i) {
   for (int j = 0; j < ways.size(); ++j) {
       if (ways[j] <= i) {
           dp[i] += dp[i - ways[j]];
       }
   }
}
return dp[target];
```

**Similar Problems:**
- 70. Climbing Stairs (Easy)
- 62. Unique Paths (Medium)
- 1155. Number of Dice Rolls With Target Sum (Medium)
- 688. Knight Probability in Chessboard (Medium)
- and more...

### 3. Merging Intervals

**Problem List:** [LeetCode Problem List](https://leetcode.com/list/55aj8s16)

**Statement:**
Given a set of numbers, find an optimal solution for a problem considering the current number and the best you can get from the left and right sides.

**Approach:**
Find all optimal solutions for every interval and return the best possible answer.

```
dp[i][j] = dp[i][k] + result[k] + dp[k+1][j]
```

**Top-Down:**
```cpp
for (int k = i; k <= j; ++k) {
    result = max(result, topDown(nums, i, k-1) + result[k] + topDown(nums, k+1, j));
}
return memo[/*state parameters*/] = result;
```

**Bottom-Up:**
```cpp
for(int l = 1; l<n; l++) {
   for(int i = 0; i<n-l; i++) {
       int j = i+l;
       for(int k = i; k<j; k++) {
           dp[i][j] = max(dp[i][j], dp[i][k] + result[k] + dp[k+1][j]);
       }
   }
}
return dp[0][n-1];
```

**Similar Problems:**
- 1130. Minimum Cost Tree From Leaf Values (Medium)
- 96. Unique Binary Search Trees (Medium)
- 546. Remove Boxes (Medium)
- 375. Guess Number Higher or Lower II (Medium)
- and more...

### 4. DP on Strings

**Problem List:** [LeetCode Problem List](https://leetcode.com/list/55afh7m7)

**General problem statement for this pattern can vary, but most of the time you are given two strings where lengths of those strings are not big.**

**Statement:**
Given two strings s1 and s2, return some result.

**Approach:**
Most of the problems on this pattern require a solution that can be accepted in O(n^2) complexity.

**Top-Down:**
```cpp
for (int i = 1; i <= n; ++i) {
   for (int j = 1; j <= m; ++j) {
       if (s1[i-1] == s2[j-1]) {
           dp[i][j] = /*code*/;
       } else {
           dp[i][j] = /*code*/;
       }
   }
}
```

**If you are given one string s, the approach may vary slightly:**

```cpp
for (int l = 1; l < n; ++l) {
   for (int i = 0; i < n-l; ++i) {
       int j = i + l;
       if (s[i] == s[j]) {
           dp[i][j] = /*code*/;
       } else {
           dp[i][j] = /*code*/;
       }
   }
}
```

**Similar Problems:**
- 1143. Longest Common Subsequence (Medium)
- 647. Palindromic Substrings (Medium)
- 516. Longest Palindromic Subsequence (Medium)
- 712. Minimum ASCII Delete Sum for Two Strings (Medium)
- and more...

### 5. Decision Making

**Problem List:** [LeetCode Problem List](https://leetcode.com/list/55af7bu7)

**The general problem statement for this pattern is for a given situation, decide whether to use or not to use the current state. So, the problem requires you to

 make a decision at a current state.**

**Statement:**
Given a set of values, find an answer with an option to choose or ignore the current value.

**Approach:**
If you decide to choose the current value, use the previous result where the value was ignored; vice-versa, if you decide to ignore the current value, use the previous result where the value was used.

**Top-Down:**
```cpp
for (int i = 1; i < n; ++i) {
   for (int j = 1; j <= k; ++j) {
       dp[i][j] = max({dp[i][j], dp[i-1][j] + arr[i], dp[i-1][j-1]});
       dp[i][j-1] = max({dp[i][j-1], dp[i-1][j-1] + arr[i], arr[i]});
   }
}
```

**Similar Problems:**
- 198. House Robber (Easy)
- 121. Best Time to Buy and Sell Stock (Easy)
- 714. Best Time to Buy and Sell Stock with Transaction Fee (Medium)
- 309. Best Time to Buy and Sell Stock with Cooldown (Medium)
- and more...

## Conclusion

I hope these patterns will be helpful in your interview preparation journey. Good luck! 😊
