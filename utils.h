/**
 * @Author: xuqi
 * @Email: xuqi86@gmail.com
 * @Date: create in 2021/3/11 2:29 下午
 * @Description: 
 */
#ifndef UTILS_H
#include <string>
#include <vector>
#endif

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

