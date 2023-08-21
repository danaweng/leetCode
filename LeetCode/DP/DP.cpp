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

//MARK: - 斐波那契数
// https://leetcode.cn/problems/fibonacci-number/
// 常规版本dp
int fib1(int n) {
    if (n < 2) {
        return n;
    }
    // dp公式：dp[n] = dp[n-1] + dp[n-2]
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//空间优化版本dp
int fib2(int n) {
    //dp初始化
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    // dp顺序
    for (int i = 2; i <= n; i++) {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}

// 递归版本
int fib3(int n) {
    if (n < 2) {
        return n;
    }
    return fib3(n-1) + fib3(n - 2);
}


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


#pragma mark - 整数拆分
/*
 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

 返回 你可以获得的最大乘积 。
 
 解题关键：
 当 i > 2时，假设对正整数 i 拆分出的第一个正整数是 j（ 1 <=j < i），则有以下两种方案：

 将 i 拆分成 j 和 i-j 的和，且 i-j 不再拆分成多个正整数，此时的乘积是 j*(i−j)

 将 i 拆分成 j 和 i-j 的和，且 i-j 继续拆分成多个正整数，此时的乘积是 j*dp[i-j]
 
 还要注意在计算dp[i]的过程中dp[i]是不断变化的，记得要取最大值

 https://leetcode.cn/problems/integer-break/description/
 */
int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
        }
    }
    
    return dp[n];
}
/**本题也可以用贪心，每次拆成n个3，如果剩下是4，则保留4，然后相乘，但是这个结论需要数学证明其合理性！**/
int integerBreak2(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    
    int result = 1;
    while (n > 4) {
        result = result * 3;
        n = n - 3;
    }
    result = result * n;
    return result;
}

#pragma mark - 不同的二叉搜索树
/**
 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 输入：n = 3
 输出：5
 
 1,2,3,4,5
 4
 
 https://leetcode.cn/problems/unique-binary-search-trees/
 */
/*这里要先复习下搜索二叉树的概念：简单说就是右子树所有节点>根节点>左子树所有节点，子树也是二叉搜索树
二叉搜索树是一个有序树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉搜索树
 */

// 解题思路：dp[n]，它的二叉搜索树有多少种呢？可以从根节点可能的情况开始计算
// for:i=1~n 根节点的值                  1                2                 3           ...           n
// L(代表左子树节点数)                L(0)  R(n-1)     L(1)  R(n-2)      L(2)  R(n-3)            L(n-1)  R(0)
// R(代表右子树节点数)
// 而其中的L(k),R(i-k),就是左右子树节点为k,i-k下的搜索二叉树的可能情况
int numTrees(int n) {
    
    vector<int> dp(n+1);
    dp[0] = 1;// 空树也是一种状态，同时为了后面其他子树为空树的case下，相乘不会为0
    for(int i = 2; i <= n; i++) {// 自底向上计算dp[n]（1～n）
        for(int j = 1; j <= i; j++) {// 这里就是根节点从1～i取值的一个遍历
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

#pragma mark - 背包问题
/*题目：
 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
 */

/* 解题关键：
不放物品i：
    由dp[i - 1][j]推出，即背包容量为j，里面不放物品i的最大价值，
    此时dp[i][j]就是dp[i - 1][j]。(其实就是当物品i的重量大于背包j的重量时，物品i无法放进背包中，所以背包内的价值依然和前面相同。)
放物品i：
    由dp[i - 1][j - weight[i]]推出，dp[i - 1][j - weight[i]] 为背包容量为j - weight[i]的时候不放物品i的最大价值，
    那么dp[i - 1][j - weight[i]] + value[i] （物品i的价值），就是背包放物品i得到的最大价值
所以递归公式： dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
 */
int maxValueOfBag (int maxWeight, vector<int> &weight, vector<int> &value) {
    int num = (int)weight.size();
    vector<vector<int>> dp(num, vector<int>(maxWeight + 1, 0));
//    for (int i = 0; i < num; i++) {// 不用初始化了
//        dp[i][0] = 0;
//    }
    
    for (int j = weight[0]; j <= maxWeight; j++) {
        dp[0][j] = value[0];
    }
    
    for(int i = 1; i < num; i++) {
        for(int j = 0; j <= maxWeight; j++) {
            if (j < weight[i]) {// 不可以放这个物品的情况下
                dp[i][j] = dp[i-1][j];
            } else {// 可以放这个物品的情况下
                int dp1 = dp[i-1][j];// 不放这个物品
                int dp2 = dp[i-1][j-weight[i]] + value[i];// 放这个物品
                dp[i][j] = max(dp1, dp2);
            }
        }
    }
    
    return dp[num-1][maxWeight];
}

/// 空间优化版本，这里只使用一个数组
int maxValueOfBag2 (int maxWeight, vector<int> &weight, vector<int> &value) {
    int num = (int)weight.size();
    vector<int> dp(num, 0);
    
    for (int i = 0; i < num; i++) {
        //for (int j = 0; j <= maxWeight; j++) {
        // 这里会有问题，因为dp[j]是依赖于之前的数据dp[0,1,2..j],这样就有可能导致依赖的数据被多次改写，
        // dp[0] dp[1] dp[2] ... dp[num]
        // <----------------------------- // 依赖左边的数据，但是从左到右循环顺序会导致左边的数据可能把物体多放了几次，多加了value
        // 从右到左到循环顺序则没有这种问题，为什么会有改写问题呢，这是因为我们使用了滚动数组，如果按照二纬数组的话，就不会数据被改动的问题
        // 从右到左，因为右边的不会被依赖，因此肯定不会被影响到
        
        for (int j = maxWeight; j >= weight[i]; j--) {//
            if (j >= weight[i]) {// 不可以放这个物品的情况下
                int dp1 = dp[j];// 不放这个物品
                int dp2 = dp[j-weight[i]] + value[i];// 放这个物品，增加收益减少容量
                dp[j] = max(dp1, dp2);
            }
        }
    }
    
    return dp[maxWeight];
}


/* 背包问题具体应用：
 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 输入：nums = [1,5,11,5]
 输出：true
 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// https://leetcode.cn/problems/partition-equal-subset-sum/solutions/442320/fen-ge-deng-he-zi-ji-by-leetcode-solution/
 */
// 解题关键，相当于从这些数中选择是否要放到子集中，使得子集和为sum(nums) / 2, 因为每次只能放一次，所以为0/1背包问题
bool canPartition(vector<int>& nums) {
    vector<int>dp(20001,0);// 元素小于100, 元素有可能的个数小于200， 总共的值小于20000;
    int sum = 0;
    for(int i = 0 ; i < (int)nums.size(); i++) {
        sum += nums[i];
    }
     
    
    if (sum % 2 == 1) {// 奇数不可以
        return false;
    }
    
    int result = sum / 2;
    for (int i = 0 ; i < (int)nums.size(); i++) {
        for (int j = result; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
        }
    }
    
    return (dp[result] == result);
}


/*
 1049. 最后一块石头的重量 II

 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
 
 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 
 如果 x == y，那么两块石头都会被完全粉碎；
 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
 
 输入：stones = [2,7,4,1,8,1]
 输出：1
 解释：
 组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
 组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
 组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
 组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
 
 1 <= stones.length <= 30
 1 <= stones[i] <= 100
 
 https://leetcode.cn/problems/last-stone-weight-ii/
 */

int lastStoneWeightII(vector<int>& stones) {
    int num = (int)stones.size();
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum+=stones[i];
    }
    
    int result = sum / 2;
    vector<int> dp(1501,0);
    for (int i = 0; i < num; i++) {
        for (int j = result; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    
    return (sum - dp[result]) - dp[result];

}

