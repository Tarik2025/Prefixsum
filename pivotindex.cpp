#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums1) << endl; // Output: 3

    vector<int> nums2 = {1, 2, 3};
    cout << pivotIndex(nums2) << endl; // Output: -1

    vector<int> nums3 = {2, 1, -1};
    cout << pivotIndex(nums3) << endl; // Output: 0

    return 0;
}

