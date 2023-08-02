//
//  ArrayRelative.cpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//  

#include "ArrayRelative.hpp"


//MARK: - 【数组】二分查找
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//
//
//示例 1:
//
//输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4
//示例 2:
//
//输入: nums = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不存在 nums 中因此返回 -1
//
//

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + ((right - left) >> 1);// 防止溢出
        //mid = left + (right - left) / 2;// 防止溢出
        if (nums[mid] < target) {// 在右边
            left = mid + 1;
        } else if (nums[mid] > target) {//左边
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/binary-search
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//MARK: - 数组
// 数组中利用二分法
//int search(vector<int>& nums, int target) {
//    unordered_map<int, int> map;
//    for (int i = 0 ; i < nums.size(); i++) {
//        map[nums[i]] = i;
//    }
//
//    if (map.count(target)) {
//        return map[target];
//    } else {
//        return -1;
//    }
//}

int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }


vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
    }

