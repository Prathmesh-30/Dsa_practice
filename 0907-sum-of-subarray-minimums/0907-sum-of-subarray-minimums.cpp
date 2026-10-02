#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    // Finds the previous strictly smaller index for every element.
    vector<int> findPreviousLess(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, -1);
        stack<int> indices;

        // Scan from left to right.
        for (int i = 0; i < n; i++) {

            // Remove elements that are greater than or equal to arr[i].
            while (!indices.empty() &&
                   arr[indices.top()] >= arr[i]) {
                indices.pop();
            }

            // Remaining top is the previous strictly smaller element.
            if (!indices.empty()) {
                previousLess[i] = indices.top();
            }

            // Store current index.
            indices.push(i);
        }

        return previousLess;
    }

    // Finds the next smaller-or-equal index for every element.
    vector<int> findNextLessOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextLessOrEqual(n, n);
        stack<int> indices;

        // Scan from right to left.
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements strictly greater than arr[i].
            while (!indices.empty() &&
                   arr[indices.top()] > arr[i]) {
                indices.pop();
            }

            // Remaining top is the next smaller-or-equal element.
            if (!indices.empty()) {
                nextLessOrEqual[i] = indices.top();
            }

            // Store current index.
            indices.push(i);
        }

        return nextLessOrEqual;
    }

public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long mod = 1000000007;

        // Find boundaries.
        vector<int> previousLess = findPreviousLess(arr);
        vector<int> nextLessOrEqual = findNextLessOrEqual(arr);

        long long answer = 0;

        for (int i = 0; i < n; i++) {

            // Number of choices for starting position.
            long long leftChoices =
                i - previousLess[i];

            // Number of choices for ending position.
            long long rightChoices =
                nextLessOrEqual[i] - i;

            // Number of subarrays where arr[i] is the minimum.
            long long contribution =
                (arr[i] * leftChoices) % mod;

            contribution =
                (contribution * rightChoices) % mod;

            answer =
                (answer + contribution) % mod;
        }

        return (int)answer;
    }
};