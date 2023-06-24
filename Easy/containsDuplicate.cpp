#include <iostream>
#include <vector>

using namespace std;

/*
* Given an integer array nums 
* return true if any value appears at least twice in the array
* and return false if every element is distinct.
*/

/* 
* Approach 1: Brute Force
*
* The time complexity of this approach is O(n^2), where n is the * * length of the array.
*
* so, this approach is not efficient for large arrays -> TLE
*/

bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

/* 
* Approach 2: Sorting
*
* The time complexity of this approach is O(n log n)
* where n is the length of the array.
*/

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}

/* 
* Approach 3: Hash Set
*
* The time complexity of this approach is O(n)
* where n is the length of the array.
*/

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num) > 0)
            return true;
        seen.insert(num);
    }
    return false;
}
