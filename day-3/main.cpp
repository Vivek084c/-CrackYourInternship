// Chocolate Distribution Problem
// # Difficulty: EasyAccuracy: 49.91%Submissions: 225K+Points: 2
// # Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// # 1. Each student gets exactly one packet.
// # 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    // sorting the array
    sort(a.begin(), a.end());
    if (m == a.size()){
        return abs(a[a.size()-1] - a[0]);
    }
    else{
   
        int mindif = INT_MAX;
        int j=m-1;
        int i=0;
        
        
        while (j<a.size()-1){
            j=i + m - 1;
            int diff = abs(a[j] - a[i]);
            if (diff < mindif){
                mindif = diff;
            }
            
            i++;
        }
        return mindif;
    }
    }   
};