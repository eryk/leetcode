/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/14 22:05
 * @Description: https://leetcode.com/problems/maximum-subarray/
 */

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * Example 1:
 *      Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *      Output: 6
 *      Explanation: [4,-1,2,1] has the largest sum = 6.
 * Example 2:
 *      Input: nums = [1]
 *      Output: 1
 * Example 3:
 *      Input: nums = [5,4,-1,7,8]
 *      Output: 23
 * Constraints:
 *      1 <= nums.length <= 3 * 10^4
 *      -10^5 <= nums[i] <= 10^5
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *
 * @param nums
 * @return
 */
int maxSubArray1(vector<int> &nums) {
    int curMax = nums[0], preMax = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        preMax = max(preMax + nums[i], nums[i]);
        curMax = max(curMax, preMax);
    }
    return curMax;
}

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      To calculate sum(0,i), you have 2 choices: either adding sum(0,i-1) to a[i], or not. If sum(0,i-1) is negative,
 *      adding it to a[i] will only make a smaller sum, so we add only if it's non-negative.
 * @param nums
 * @return
 */
int maxSubArray(vector<int> &nums) {
    if (nums.empty()) { return 0; }
    int maxSum = nums[0], sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (sum < 0) { sum = nums[i]; }
        else { sum += nums[i]; }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    nums = {1};
    cout << maxSubArray(nums) << endl;
    nums = {5, 4, -1, 7, 8};
    cout << maxSubArray(nums) << endl;
    nums = {-2, -1};
    cout << maxSubArray(nums) << endl;
}