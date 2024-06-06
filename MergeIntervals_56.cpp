/*
Leetcode : #56 {https://leetcode.com/problems/merge-intervals/description/}

I/P: [[1,3],[2,6],[8,10],[15,18]]
     1 . 3
     . 2 . . . 6
     . . . . . . . 8 . 10
     . . . . . . . . . . . . . . 15 . . 18

O/P: [[1,6],[8,10],[15,18]]

Brute Force: 
Merge all overlapping intervals and return an array of all non-overlapping intervals 
that cover all intervals in the input.
Step 1: sort the array by the first element, sort by the second element if at any moment first element is equal.
1,3 2,6 8,9 9,11 8,10 2,4 15,18 16,17

1,3 2,4 2,6 8,9 8,10 9,11 15,18 16,17
.
start iterating over this sorted array
let's say 1,3 is the possible interval

Overlapping
1,3  2,4  
if the first element is before the last element of the previous
in order to accumulate: 1,4

if the last element is less than then end of interval => element already covered

1,6 8,11 15,18

Step 2: sort the array by the second element

//Brute Force : O(2n) :: Not Good
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i < n; i++) {
            int beg = intervals[i][0];
            int end = intervals[i][1];
            if(!ans.empty() || end <= ans.back()[1])
                continue;
            for(int j = i+1; j < n; j++) {
                if(intervals[j][0] <= end)
                    end = max(end, intervals[j][1]);
                else
                    break;
            }
            ans.push_back({beg, end});
        }
        return ans;
    }

Advaced Approach: 
1,3 2,4 2,6 8,9 8,10 9,11 15,18 16,17
    .   .   .   .    .    .
1,4 -> 1,6  8,9 -> 8,10 -> 8,11 
*/
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i < n; i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else { // lying inside interval
                //last element :: ans.back()[1]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};