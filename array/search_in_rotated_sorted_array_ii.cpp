/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2022/06/27
 * @Description:
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 */

/**
 * There is an integer array nums sorted in non-decreasing order (not
 * necessarily with distinct values). Before being passed to your function,
 * nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that
 * the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1],
 * ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be
 * rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 *
 * Given the array nums after the rotation and an integer target, return true
 * if target is in nums, or false if it is not in nums.
 *
 * You must decrease the overall operation steps as much as possible.
 *
 * Example 1:
 *      Input: nums = [2,5,6,0,0,1,2], target = 0
 *      Output: true
 * Example 2:
 *      Input: nums = [2,5,6,0,0,1,2], target = 3
 *      Output: false
 * Constraints:
 *      1 <= nums.length <= 5000
 *      -10^4 <= nums[i] <= 10^4
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
  bool search1(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) return true;
    }
    return false;
  }

  bool existsInFirst(vector<int>& nums, int start, int element) {
    return nums[start] <= element;
  }

  bool isBinarySearchHelpful(vector<int>& nums, int start, int element) {
    return nums[start] != element;
  }

  bool search2(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    int end = n - 1;
    int start = 0;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) {
        return true;
      }

      if (!isBinarySearchHelpful(nums, start, nums[mid])) {
        start++;
        continue;
      }

      bool pivotArray = existsInFirst(nums, start, nums[mid]);

      bool targetArray = existsInFirst(nums, start, target);

      if (pivotArray ^ targetArray) {
        if (pivotArray) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      } else {
        if (nums[mid] < target) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return false;
  }

  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
      mid = (left + right) >> 1;
      if (nums[mid] == target) return true;
      if (nums[left] == nums[mid] && (nums[right] == nums[mid])) {
        ++left, --right;
      } else if (nums[left] <= nums[mid]) {
        if ((nums[left] <= target) && (nums[mid] > target))
          right = mid - 1;
        else
          left = mid + 1;
      } else {
        if ((nums[mid] < target) && (nums[right] >= target))
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  bool answer = true;
  Solution s;
  auto result = s.search(nums, target);
  assert(result == answer);

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  answer = false;
  result = s.search(nums, target);
  assert(result == answer);

  nums = {1};
  target = 0;
  answer = false;
  result = s.search(nums, target);
  assert(result == answer);
}
