/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2022/06/24 12:09 下午
 * @Description: https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

/**
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 *
 * Prior to being passed to your function, nums is possibly rotated at
 * an unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 *      Input: nums = [4,5,6,7,0,1,2], target = 0
 *      Output: 4
 * Example 2:
 *      Input: nums = [4,5,6,7,0,1,2], target = 3
 *      Output: -1
 * Example 3:
 *      Input: nums = [1], target = 0
 *      Output: -1
 * Constraints:
 *      1 <= nums.length <= 5000
 *      -10^4 <= nums[i] <= 10^4
 *      All values of nums are unique.
 *      nums is an ascending array that is possibly rotated.
 *      -10^4 <= target <= 10^4
 */
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * 时间复杂度 : O(n)
   * 空间复杂度 : O(1)
   * 解题思路：
   *      循环遍历，但不符合题目要求时间复杂度为O(log n)
   * @param nums
   * @param target
   * @return
   */
  int search1(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) return i;
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (target == nums[mid]) return mid;
      // there exists rotation; the middle element is in the left part of the
      // array
      if (nums[mid] > nums[r]) {
        if (target < nums[mid] && target >= nums[l])
          r = mid - 1;
        else
          l = mid + 1;
      }
      // there exists rotation; the middle element is in the right part of the
      // array
      else if (nums[mid] < nums[l]) {
        if (target > nums[mid] && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
      // there is no rotation; just like normal binary search
      else {
        if (target < nums[mid])
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  int answer = 4;
  Solution s;
  auto result = s.search(nums, target);
  assert(result == answer);

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  answer = -1;
  result = s.search(nums, target);
  assert(result == answer);

  nums = {1};
  target = 0;
  answer = -1;
  result = s.search(nums, target);
  assert(result == answer);
}
