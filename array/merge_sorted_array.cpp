/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/15 10:21
 * @Description: https://leetcode.com/problems/merge-sorted-array/
*/

/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
 *
 * Example 1:
 *      Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 *      Output: [1,2,2,3,5,6]
 * Example 2:
 *      Input: nums1 = [1], m = 1, nums2 = [], n = 0
 *      Output: [1]
 * Constraints:
 *      nums1.length == m + n
 *      nums2.length == n
 *      0 <= m, n <= 200
 *      1 <= m + n <= 200
 *      -10^9 <= nums1[i], nums2[i] <= 10^9
 */

#include <vector>
#include "../utils.h"

using namespace std;

void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0) {
        nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
}

/**
 * 时间复杂度 : O(1)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      两个集合从后往前merge，每次取两个集合最大的元素插入nums1中
 * @param nums1
 * @param m
 * @param nums2
 * @param n
 */
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int a = m - 1;
    int b = n - 1;
    int i = m + n - 1;    // calculate the index of the last element of the merged array

    // go from the back by A and B and compare and put to the A element which is larger
    while (a >= 0 && b >= 0) {
        if (nums1[a] > nums2[b]) nums1[i--] = nums1[a--];
        else nums1[i--] = nums2[b--];
    }
    // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
    while (b >= 0) nums1[i--] = nums2[b--];
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    merge(nums1, m, nums2, n);
    printVector(nums1);

}