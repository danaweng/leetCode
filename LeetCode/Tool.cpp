//
//  Tool.cpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//

#include "Tool.hpp"

void printVector(vector<int>& nums) {
    for(vector<int>::iterator iterator = nums.begin(); iterator != nums.end(); iterator++) {
        cout << *iterator << endl ;
    }
}

vector<int> nums;
void cinnum() {
        vector<int> nums;
        cout << "输入int 数组" << endl;
        for (int temp = 0; cin >> temp;) {
            nums.push_back(temp);
            if (cin.get() == '\n')
                break;
        }

        cout << "输入元素个数为：" << nums.size()<<endl;

        for (int i = 0; i < nums.size(); i++)
            cout <<"nums["<<i<<"] : "<< nums[i]<<endl;
        
        system("pause");
}
