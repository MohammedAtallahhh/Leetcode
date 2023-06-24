/*
* Given an array of integers nums and an integer target
* return indices of the two numbers such that they add up to target.
* 
* You may assume that each input would have exactly one solution, * and you may not use the same element twice.
*
* You can return the answer in any order.
*/

/*
* Approach 1: Two-pointer technique
*
* Time complexity: O(n)
* starting from the beginning and end of the array.
* It iterates through the array once 
* until the pointers meet or find the target sum.
* Since it only requires a single pass through the array
* the time complexity is O(n)
* where n is the size of the input array.
*/

int* twoSum(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    static int res[2];
    
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[left] + arr[right] > target)
            right--;
            
        else if (arr[left] + arr[right] < target)
            left++;
            
        else {
            res[0] = left;
            res[1] = right;
        }
    }
    
    return res;
}

/*
* Approach 2: Two-pass Hash Table
* Time complexity: O(n)
*
* In the first pass, it builds a hash table
* by storing each element of the array
* as a key and its corresponding index as the value.
* In the second pass, it finds the complement of each element
* and checks if it exists in the hash table.
* If a complement is found, it returns the indices of the two numbers. The time complexity is O(n) because both passes iterate through the array once.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    // Build the hash table
    for (int i = 0; i < n; i++) {
        numMap[nums[i]] = i;
    }

    // Find the complement
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement) && numMap[complement] != i) {
            return {i, numMap[complement]};
        }
    }

    return {}; // No solution found
}


/*
* Approach 3: One-pass Hash Table
* Time complexity: O(n)
* It iterates through the array once,
* while simultaneously building the hash table
* and checking for complements. 
* It stores each element of the array in the hash table 
* along with its index. 
* For each element, it calculates the complement 
* and checks if it exists in the hash table.
* If a complement is found, it returns the indices of the two numbers. The time complexity is O(n) because it only requires a single pass through the array.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}
