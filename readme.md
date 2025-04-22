# Analysis and Design of Algorithms

##  Program Descriptions

###  Peak Finding
- **1DPeakFinding.cpp**  
  Implements a binary search-based approach to find a peak element in a 1D array, where an element is a peak if it is not smaller than its neighbors.

- **2dpeakfinding.cpp**  
  Extends the peak finding concept to 2D matrices using a divide-and-conquer strategy, helping reduce time complexity over brute force methods.

---

###  Dynamic Programming
- **LongestCommonSubsequence.cpp**  
  Finds the longest subsequence present in both sequences using dynamic programming. Useful in text comparison, diff tools, and bioinformatics.

- **MatrixChainMultiplication.cpp**  
  Optimizes the multiplication order of matrices to minimize scalar multiplications using a bottom-up dynamic programming approach.

- **TravellingSalesmanProb.cpp**  
  Solves the TSP problem using bitmasking and memoization, finding the shortest route to visit all cities exactly once and return to the origin.

- **fractionalknapsack.cpp**  
  Greedy algorithm to maximize profit by allowing the division of items. Unlike the 0-1 knapsack, it allows picking fractions of items.

- **multistagegraph.cpp**  
  Solves shortest path problems in a Directed Acyclic Graph (DAG) structured in stages using dynamic programming.

- **stagecountinMSG.cpp**  
  Calculates the number of stages in a multistage graph, useful for graph partitioning and stage-wise optimization problems.

---

###  Graph Algorithms
- **APSP.cpp**  
  Implements the Floyd-Warshall algorithm to compute shortest paths between all pairs of vertices in a weighted graph.

- **Dijkstra.cpp**  
  Uses a greedy algorithm with a priority queue (min-heap) to find the shortest path from a single source to all other nodes.

- **PrimsAlgo.cpp**  
  Constructs a Minimum Spanning Tree (MST) from a graph using Prim's algorithm, which grows the MST by selecting the minimum weight edge at each step.

- **kruskals.cpp**  
  Constructs an MST using Kruskal’s algorithm by sorting edges and using Disjoint Set Union (DSU) to avoid cycles.

---

###  Backtracking
- **NQueenProb.cpp**  
  Classic backtracking problem that places N queens on an N×N chessboard so that no two queens threaten each other.

---

###  Matrix Multiplication
- **Strassen'sMatrixMultiplication.cpp**  
  Efficient matrix multiplication using Strassen's divide-and-conquer algorithm, which is faster than the standard cubic method.

- **conventionalMM.cpp**  
  Implements standard matrix multiplication using a triple nested loop. Good for understanding matrix operations and base cases.

---

###  Sorting
- **iterativequicksort.cpp**  
  Non-recursive implementation of QuickSort using an explicit stack. Helpful in environments where recursion depth is limited.

---

###  Geometry
- **convexhull.cpp**  
  Computes the convex hull for a set of points using Graham’s scan or Andrew’s monotone chain method. Useful in computer graphics and GIS.

- **magicsquare.cpp**  
  Generates a magic square of odd order (n x n), where the sum of numbers in all rows, columns, and diagonals is the same.

---


