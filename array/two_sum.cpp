/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/9 11:23 上午
 * @Description: https://leetcode.com/problems/two-sum/
 */

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example1:
 *      Input: nums = [2,7,11,15], target = 9
 *      Output: [0,1]
 *      Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example2:
 *      Input: nums = [3,2,4], target = 6
 *      Output: [1,2]
 *
 * Example3:
 *      Input: nums = [3,3], target = 6
 *      Output: [0,1]
 *
 * Constraints:
 *      2 <= nums.length <= 103
 *      -109 <= nums[i] <= 109
 *      -109 <= target <= 109
 *      Only one valid answer exists.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 时间复杂度 : O(1)
     * 空间复杂度 : O(1)
     * 解题思路：
     *  1. 将nums列表存入map
     *  2. 循环nums，如果map中存在target - nums[i]则返回
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int> &nums, int target) {

        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i) {
                return {i, m[target - nums[i]]};
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums({2, 7, 11, 15});
    int target = 13;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

}