//
//  main.cpp
//  LeetCode
//
//  Created by danaweng on 2022/12/3.
//  主函数入口，进行用例测试

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include "DP.hpp"
#include "Tool.hpp"


//1. 两数之和
//https://leetcode.cn/problems/two-sum/?favorite=2cktkvj
//nums = [2,7,11,15], target = 9

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //        std::unordered_map<std::string, std::string> umap{
        //            {"Python教程","http://c.biancheng.net/python/"},
        //            {"Java教程","http://c.biancheng.net/java/"},
        //            {"Linux教程","http://c.biancheng.net/linux/"} };
        //
        //        umap.find("Python教程");
        //
        
        //440 ms    10 MB
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;

        
//        //608 ms    9.8 MB
//        vector<int> result;
//        for(int i = 0; i < nums.size(); i++) {
//            for(int j = i+1; j < nums.size(); j++) {
//                if (nums.at(i) + nums.at(j) == target) {
//                    result.push_back(i);
//                    result.push_back(j);
//                    return result;
//                }
//            }
//        }
//
//        return result;
//
//
//        unordered_map<int, int> hashtable;
//        for (int i = 0; i < nums.size(); ++i) {
//            auto it = hashtable.find(target - nums[i]);
//            if (it != hashtable.end()) {
//                return {it->second, i};
//            }
//            hashtable[nums[i]] = i;
//        }
//        return {};
//
//        / 8 ms    10.5 MB
//        unordered_map<int, int> map;
//        for (int i = 0;i<nums.size();i++) {
//            auto it = map.find(target - nums[i]);
//            if (it != map.end()) {
//                return {it->second, i};
//            }
//            map[nums[i]] = i;
//            //map.emplace(nums[i],i);
//        }
//
//        return {};
//

        unordered_map<int, int> tmpMap;
        for(int i = 0 ;i < nums.size(); i++) {
            auto it = tmpMap.find(target - nums[i]);
            if (it != tmpMap.end()){
                return {it->second, i};
            }
            tmpMap[nums[i]] = i;
        }
        return {};
    }
    
    
    ///Valid parentheses 有效的括号
    /// https://leetcode.cn/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/

    bool isValidParentheses(string s) {
        // 不是偶数，直接返回
        if (s.length() == 0 || s.length() % 2 == 1) {
            return false;
        }
        
        // 用map记录
        unordered_map<char, char> unorder_map = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        
        // for扫描string，如果左边符号，进行入栈，右边符号，进行出栈
        stack<char> stack; // stack 用于存在左边符号
        for (char c : s) {
            // 右边符号，进行出栈
            if (unorder_map.count(c)) {// 如果是右边符号
                if (stack.empty() || stack.top() != unorder_map[c]) {//找到这个
                    return false;
                }
                stack.pop();// 左边符号，进行入栈
            } else  {
                stack.push(c);
            }
        }
        return stack.empty();
    }
    

    
};

