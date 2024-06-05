/*
Leetcode : #48 {https://leetcode.com/problems/rotate-image/description/}

1 2 3    7 4 1  |  00 01 02
4 5 6 -> 8 5 2  |  10 11 12
7 8 9    9 6 3  |  20 21 22
i.e rotate the matrix by 90 degrees clockwise

Approach : 
Step 1: transpose the matrix: interchanging the columns and rows of the matrix
1 2 3    1 4 7
4 5 6 -> 2 5 8
7 8 9    3 6 9

Step 2: swap the columns: reverse each row
1 4 7    7 4 1
2 5 8 -> 8 5 2
3 6 9    9 6 3
*/
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        //transpose
        for(int i=0; i < r; i++) {
            for(int j=0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //swap cols
        for(int i=0; i < r; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};