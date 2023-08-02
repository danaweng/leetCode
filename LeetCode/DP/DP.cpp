//
//  DP.cpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;


//MARK: - 动态规划
 int climbStairs(int n) {
//    if (n == 1) {
//        return 1;
//    }
//
//    if (n == 2) {
//        return 2;
//    }
//
//    return (climbStairs(n-1) + 1 + climbStairs(n-2) + 2);
    
   //0 ms    6.1 MB
//    vector<int> vector;
//    vector.push_back(0);
//    vector.push_back(1);
//    vector.push_back(2);
//
//    for(int i = 3; i <= n; i++) {
//        vector.push_back((vector[i-1] + vector[i-2]));
//    }
//    return vector[n];
    
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int n1 = 1;
    int n2 = 2;
    int sum = 0;
    for(int i = 3; i <= n; i++) {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return sum;
    
}


/**
 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 输出：6
 解释：你将从下标为 0 的台阶开始。
 - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 总花费为 6 。

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/min-cost-climbing-stairs
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int minCostClimbingStairs(vector<int>& cost) {
    
    vector<int> dp(cost.size()+1);
    dp[0] = 0;
    dp[1] = 0;
    
    for(int i = 2; i <= cost.size(); i++) {
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }
    
    return dp[cost.size()];

}

/**
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

 问总共有多少条不同的路径？
 输入：m = 3, n = 2
 输出：3
 解释：
 从左上角开始，总共有 3 条路径可以到达右下角。
 1. 向右 -> 向下 -> 向下
 2. 向下 -> 向下 -> 向右
 3. 向下 -> 向右 -> 向下

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/unique-paths
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 dp[m][n] = dp[m-1][n] + dp[m][n-1]
  */


int uniquePaths(int m, int n) {
    // 这里vector 二维数组的初始化注意一下
    //vector<vector<int>> v(10, vector<int>(10));
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    
    for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}


/**
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

 网格中的障碍物和空位置分别用 1 和 0 来表示。
 
 

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/unique-paths-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = (int)obstacleGrid.size();
    int n = (int)obstacleGrid.at(0).size();

    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = 1;
        } else {
            break;// 注意这里，如果出现过一个阻塞，后面应该都设置成0
        }
    }

    for(int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}


//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
//        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                if (obstacleGrid[i][j] == 1) continue;
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//}
//        return dp[m - 1][n - 1];
//    }


/**
 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 输入：n = 3
 输出：5
 
 1,2,3,4,5
 4
 
 https://leetcode.cn/problems/unique-binary-search-trees/
 */
int numTrees(int n) {
    
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

