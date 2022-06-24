/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/12 14:42
 * @Description: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Clarification:
 *      Confused why the returned value is an integer but your answer is an array?
 *      Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.
 *
 * Example 1:
 *      Input: nums = [1,1,2]
 *      Output: 2, nums = [1,2]
 *      Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 *      It doesn't matter what you leave beyond the returned length.
 * Example 2:
 *      Input: nums = [0,0,1,1,1,2,2,3,3,4]
 *      Output: 5, nums = [0,1,2,3,4]
 *      Explanation: Your function should return length = 5, with the first five elements of nums being modified to
 *      0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
 * Constraints:
 *      0 <= nums.length <= 3 * 10^4
 *      -10^4 <= nums[i] <= 10^4
 *      nums is sorted in ascending order.
 */

#include <iostream>
#include <vector>
#include "../utils.h"

using namespace std;

/**
 * 时间复杂度 : O(n)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      使用pos表示未重复数据最新的位置，然后从第一个位置开始，跟前一个数字比较是否相等，不相等就替换掉pos，然后pos+1
 * @param nums
 * @return
 */
int removeDuplicates1(vector<int> &nums) {
    if (nums.empty()) return 0;
    int pos = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) nums[pos++] = nums[i];
    }
    return pos;
}

/**
 * 时间复杂度 : O(n)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      使用STL, distance用于计算两个迭代器的范围内包含元素的个数,
 *      unique是去除容器或者数组中相邻元素重复出现的元素，去除是将重复元素放到容器的末尾，返回值是去重后的尾指针
 *      unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数
 * @param nums
 * @return
 */
int removeDuplicates2(vector<int> &nums){
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

/**
 * 时间复杂度 : O(n)
 * 空间复杂度 : O(1)
 * 解题思路：
 *      使用STL, upper_bound返回一个迭代器，指向范围 [first,last) 中比较大于 val 的第一个元素。
 * @param nums
 * @return
 */
template<typename Init, typename OutIt>
OutIt removeDuplicates(Init first, Init last, OutIt output){
    while(first != last){
        *output++ = *first;
        first = upper_bound(first, last, *first);
    }
    return output;
}

int removeDuplicates(vector<int> &nums){
    return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
}




int main() {
    vector<int> nums = {1, 1, 2};
    cout << removeDuplicates(nums) << endl;
    printVector(nums);
    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
    printVector(nums);
}
