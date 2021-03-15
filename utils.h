/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/11 2:29 下午
 * @Description: 
 */
#ifndef LEETCODE_UTILS_H_
#define LEETCODE_UTILS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(const vector<string> &v, char c) {
    string s = "";
    for (vector<string>::const_iterator p = v.begin();p != v.end(); ++p) {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }
    return s;
}

template <typename AnyType>
void printVector(vector<AnyType> &nums) {
    for (int i = 0; i < nums.size();i++) {
        cout << nums[i];
        if(i != nums.size() - 1){
            cout << ",";
        }
    }
    cout << endl;
}

#endif // LEETCODE_UTILS_H_