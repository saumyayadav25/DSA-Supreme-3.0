# Dynamic Programming 
It is a technique for problem solving.
#### When to apply?
- Overlapping Sub Problems
- Optimal sub-structure
  (big problem can be solved from small problems)

#### Fibonacci recursive tree
<img src="https://miro.medium.com/v2/resize:fit:925/1*svQ784qk1hvBE3iz7VGGgQ.jpeg">

> **DP:** solve each subproblem only once and store the results. It avoids redundant computations.

#### Fibonacci tree after using dp(memoization)
<img src="https://media.licdn.com/dms/image/C4E12AQEtD06ODcOAxA/article-cover_image-shrink_600_2000/0/1652693639101?e=2147483647&v=beta&t=6Jy4ps0ugKYXh8RcW_p3xHcIXYCRq8ZhWDXNjdXfKnI">

### DP QUESTIONS APPROACH
- **Top - down approach (recursion + memoization)**
- **Bottom - up approach (loop)**
- **Space optimisation (find pattern if any)**

## Top - Down approach

***recursion+memoization***

#### STEPS:
1) find out if it is 1D/2D/3D dp(check how many function parameters are getting changed in function call). Based on that, create dp array and pass in function
2) answer in recursive code-> store in dp array and return in dp array
3) if answer already exists in dp array: no need to process again, just return the answer.

<img src="https://miro.medium.com/v2/format:webp/1*rCch4Ju3PcPPMpvFireFyQ.png">
TC: O(N) <br>
SC: O(N)

## Bottom - Up Approach

***iterative***

#### STEPS:
1) create dp array (1D/2D/3D? , size ?, initialize ?)
2) analyse base cases in recursive approach-> update dp array
3) check parameters, reverse it, run loop
<img src="https://miro.medium.com/v2/1*9YUE1V0fYhFujaXEcmX3wg.png">
TC: O(N) <br>
SC: O(N)

## Space Optimization
In this fibonacci example, 
**we can observe that, to get f(n) we need only two previous states f(n-1) and f(n-2) and not whole dp array.**
Store these states in prev and curr.

TC: O(N) <br>
SC: O(1)
