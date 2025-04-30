# Analysis and Design of Alogorithms

---

### 1. **Fractional Knapsack Problem**
- **Problem Type**: Greedy Algorithm  
- **Description**: Given a set of items, each with a weight and a value, the task is to determine the most valuable combination of items that fit into a knapsack of fixed capacity. The difference from the 0/1 Knapsack Problem is that fractional items are allowed to be taken (i.e., items can be split).  
- **Key Concept**: Greedy Strategy  
- **Time Complexity**: O(n log n) (due to sorting)  

---

### 2. **1D Peak Finding**
- **Problem Type**: Divide and Conquer  
- **Description**: In a 1-dimensional array, a peak is an element that is greater than or equal to its neighbors. The task is to find one such peak element. A peak does not necessarily have to be the global maximum.  
- **Key Concept**: Binary Search (Divide and Conquer)  
- **Time Complexity**: O(log n)  

---

### 3. **2D Peak Finding**
- **Problem Type**: Divide and Conquer  
- **Description**: A 2D peak element in a matrix is an element that is greater than or equal to its neighbors in all four directions (up, down, left, right). The problem involves finding one such peak element.  
- **Key Concept**: Divide and Conquer  
- **Time Complexity**: O(n log m) where n is the number of rows and m is the number of columns.

---

### 4. **Magic Square**
- **Problem Type**: Backtracking  
- **Description**: A magic square is a square matrix where the sum of the numbers in each row, each column, and the two diagonals are the same. The task is to generate or verify a magic square for a given size.  
- **Key Concept**: Backtracking, Mathematical Constraints  
- **Time Complexity**: Varies based on the approach used.

---

### 5. **Iterative QuickSort**
- **Problem Type**: Sorting  
- **Description**: QuickSort is a divide-and-conquer algorithm that sorts an array by partitioning it into smaller subarrays and then recursively sorting those subarrays. This iterative version eliminates recursion, using an explicit stack to manage subarrays.  
- **Key Concept**: Divide and Conquer, Iterative Approach  
- **Time Complexity**: O(n log n) on average, O(n^2) in the worst case.

---

### 6. **Conventional Matrix Multiplication**
- **Problem Type**: Matrix Operations  
- **Description**: This algorithm multiplies two matrices using the standard method, which involves iterating over each row and column.  
- **Key Concept**: Matrix Operations  
- **Time Complexity**: O(n^3) for matrices of size n × n

---

### 7. **Strassen’s Matrix Multiplication**
- **Problem Type**: Matrix Operations  
- **Description**: Strassen’s algorithm is an optimized version of matrix multiplication that reduces the time complexity by dividing the problem into smaller subproblems and solving them recursively.  
- **Key Concept**: Divide and Conquer, Optimization  
- **Time Complexity**: O(n^2.81)

---

### 8. **Convex Hull**
- **Problem Type**: Geometry  
- **Description**: The Convex Hull of a set of points is the smallest convex polygon that can enclose all the points. This algorithm finds the boundary of the set of points in a 2D plane.  
- **Key Concept**: Computational Geometry, Convex Hull Algorithms  
- **Time Complexity**: O(n log n)

---

### 9. **Prim’s Algorithm**
- **Problem Type**: Graph Algorithms  
- **Description**: Prim’s algorithm is a greedy algorithm that finds the minimum spanning tree (MST) of a weighted undirected graph. The MST connects all the vertices with the minimum total edge weight.  
- **Key Concept**: Greedy Algorithm  
- **Time Complexity**: O(E log V) with a priority queue, where E is the number of edges and V is the number of vertices.

---

### 10. **Dijkstra’s Algorithm (Shortest Path)**
- **Problem Type**: Graph Algorithms  
- **Description**: Dijkstra's algorithm finds the shortest paths from a source vertex to all other vertices in a weighted graph. It uses a greedy approach to ensure the shortest path is chosen at each step.  
- **Key Concept**: Greedy Algorithm, Shortest Path  
- **Time Complexity**: O(E log V) with a priority queue.

---

### 11. **Kruskal’s Algorithm**
- **Problem Type**: Graph Algorithms  
- **Description**: Kruskal’s algorithm finds the minimum spanning tree (MST) by sorting the edges of the graph and adding the smallest edge to the MST, ensuring no cycles are formed.  
- **Key Concept**: Greedy Algorithm, Union-Find  
- **Time Complexity**: O(E log E), where E is the number of edges.

---

### 12. **All Pair Shortest Path**
- **Problem Type**: Graph Algorithms  
- **Description**: This problem involves finding the shortest paths between every pair of vertices in a weighted graph. The **Floyd-Warshall algorithm** is commonly used to solve this problem.  
- **Key Concept**: Dynamic Programming, All Pair Shortest Path  
- **Time Complexity**: O(V^3), where V is the number of vertices.

---

### 13. **Multi-Stage Graph Problem**
- **Problem Type**: Dynamic Programming  
- **Description**: In this problem, a graph is divided into multiple stages, and the task is to find the shortest path from a source node to a destination node across different stages.  
- **Key Concept**: Dynamic Programming, Graph Theory  
- **Time Complexity**: Depends on the number of stages and vertices.

---

### 14. **Stage Count**
- **Problem Type**: Dynamic Programming  
- **Description**: Given a graph with multiple stages, this problem involves finding the minimum number of stages required to traverse from a source to a destination node.  
- **Key Concept**: Graph Theory, Dynamic Programming  
- **Time Complexity**: Depends on the graph size.

---

### 15. **Matrix Chain Multiplication**
- **Problem Type**: Dynamic Programming  
- **Description**: The problem involves finding the most efficient way to multiply a sequence of matrices to minimize the number of scalar multiplications.  
- **Key Concept**: Dynamic Programming, Matrix Operations  
- **Time Complexity**: O(n^3), where n is the number of matrices.

---

### 16. **0/1 Knapsack Problem**
- **Problem Type**: Dynamic Programming  
- **Description**: In the 0/1 Knapsack Problem, given a set of items, each with a weight and value, determine the maximum value of items that can be included in a knapsack without exceeding its capacity.  
- **Key Concept**: Dynamic Programming  
- **Time Complexity**: O(n * W), where n is the number of items and W is the knapsack capacity.

---

### 17. **Travelling Salesman Problem**
- **Problem Type**: NP-hard Problem  
- **Description**: The Travelling Salesman Problem involves finding the shortest possible route that visits each city once and returns to the starting point.  
- **Key Concept**: Brute Force, Dynamic Programming (Held-Karp), Approximation Algorithms  
- **Time Complexity**: O(n!), O(n^2 * 2^n) (dynamic programming).

---

### 18. **Longest Common Subsequence**
- **Problem Type**: Dynamic Programming  
- **Description**: This problem involves finding the longest subsequence common to two sequences (strings or arrays).  
- **Key Concept**: Dynamic Programming  
- **Time Complexity**: O(m * n), where m and n are the lengths of the two sequences.

---

### 19. **N – Queens Problem**
- **Problem Type**: Backtracking  
- **Description**: The N-Queens problem involves placing N queens on an N×N chessboard such that no two queens threaten each other.  
- **Key Concept**: Backtracking  
- **Time Complexity**: Varies based on the value of N.

---

### 20. **M-Colourable Problem**
- **Problem Type**: Backtracking  
- **Description**: The M-Colourable Problem is to determine whether a graph can be colored with M colors such that no two adjacent vertices have the same color.  
- **Key Concept**: Graph Theory, Backtracking  
- **Time Complexity**: Exponential in the worst case.

---

### 21. **Hamiltonian Cycle**
- **Problem Type**: Backtracking  
- **Description**: A Hamiltonian cycle in a graph is a cycle that visits every vertex exactly once and returns to the starting vertex. The task is to determine if such a cycle exists.  
- **Key Concept**: Backtracking, Graph Theory  
- **Time Complexity**: O(n!), where n is the number of vertices.

---

### 22. **Sum of Subsets Problem**
- **Problem Type**: Backtracking  
- **Description**: Given a set of positive integers and a target sum, the problem is to find all subsets of the given set whose sum equals the target value.  
- **Key Concept**: Backtracking, Subset Generation  
- **Time Complexity**: O(2^n) in the worst case (since all subsets are checked)  

---
