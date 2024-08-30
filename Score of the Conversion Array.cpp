#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrefixScore(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixScore(n);
    int maxVal = nums[0];
    prefixScore[0] = 2 * nums[0];

    for (int i = 1; i < n; ++i) {
        maxVal = max(maxVal, nums[i]);
        prefixScore[i] = prefixScore[i - 1] + nums[i] + maxVal;
    }

    return prefixScore;
}

int main() {
    vector<int> nums1 = {2, 3, 7, 5, 10};
    vector<int> result1 = findPrefixScore(nums1);
    for (int score : result1) {
        cout << score << " "; // Output: 4 10 24 36 56
    }
    cout << endl;

    vector<int> nums2 = {1, 1, 2, 4, 8, 16};
    vector<int> result2 = findPrefixScore(nums2);
    for (int score : result2) {
        cout << score << " "; // Output: 2 4 8 16 32 64
    }
    cout << endl;

    return 0;
}
