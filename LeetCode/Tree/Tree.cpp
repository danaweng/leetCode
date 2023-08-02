//
//  Tree.cpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//

#include "Tree.hpp"
#include "DP.hpp"

//MARK: - 【树】
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 示例 1：
 输入：root = [4,2,7,1,3,6,9]
 输出：[4,7,2,9,6,3,1]

 来源：力扣（LeetCode）
 链接：https://leetcode.cn/problems/invert-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return root;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

//MARK: 二叉树遍历
// 前序遍历 - 迭代法
vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
}

// 中序遍历
void inorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

// 中序遍历迭代版本
vector<int> inorderTraversal_iteration(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
}

// 层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode *> queue;
    if (root != nullptr) {
        queue.push(root);
    }
    vector<vector<int>> result;
    while (!queue.empty()) {
        vector<int> vector;
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = queue.front();
            queue.pop();
            vector.push_back(node->val);
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }
        result.push_back(vector);
    }
    return result;
    
}
//vector<vector<int>> levelOrder(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root != NULL) que.push(root);
//        vector<vector<int>> result;
//        while (!que.empty()) {
//            int size = que.size();
//            vector<int> vec;
//            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
//            for (int i = 0; i < size; i++) {
//                TreeNode* node = que.front();
//                que.pop();
//                vec.push_back(node->val);
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//            result.push_back(vec);
//        }
//        return result;
//    }

//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode-solutio/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

bool isSymmetric(TreeNode* root) {
    return check(root, root);
}

int minDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    int leftMinDeep = minDepth(root->left);
    int rightMinDeep = minDepth(root->right);
    if (root->left == nullptr) {
        return (1 + rightMinDeep);
    }
    if (root->right == nullptr) {
        return (1 + leftMinDeep);
    }
    return min(leftMinDeep, rightMinDeep) + 1;
    
}

//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


/*********************************************************************************************************/
/**平衡二叉树 **/
/**********************************************************************************************************/
int isBalancedHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(isBalancedHeight(root->left), isBalancedHeight(root->right)) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return abs(isBalancedHeight(root->left) - isBalancedHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/*********************************************************************************************************/
/**二叉树的所有路径 **/
/**********************************************************************************************************/
//void construct_paths(TreeNode* root, string path, vector<string>& paths) {
//       if (root != nullptr) {
//           path += to_string(root->val);
//           if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
//               paths.push_back(path);                              // 把路径加入到答案中
//           } else {
//               path += "->";  // 当前节点不是叶子节点，继续递归遍历
//               construct_paths(root->left, path, paths);
//               construct_paths(root->right, path, paths);
//           }
//       }
//   }
//
//   vector<string> binaryTreePaths(TreeNode* root) {
//       vector<string> paths;
//       construct_paths(root, "", paths);
//       return paths;
//   }

void construct_paths(TreeNode *node, string path, vector<string> &paths) {
    
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    construct_paths(root, "", paths);
    return paths;
}


//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/binary-tree-paths/solution/er-cha-shu-de-suo-you-lu-jing-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


int main()
{
    vector<vector<int>> obstacleGrid = {{1,0}};
    uniquePathsWithObstacles(obstacleGrid);
    return 0;
}

///// 对称二叉树 symmetric
//bool check(TreeNode *p, TreeNode *q) {
//    if (!p && !q) return true;
//    if (!p || !q) return false;
//    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
//}
//
//bool isSymmetric(TreeNode* root) {
//    return check(root, root);
//}

//bool check(TreeNode *u, TreeNode *v) {
//    queue <TreeNode*> q;
//    q.push(u); q.push(v);
//    while (!q.empty()) {
//        u = q.front(); q.pop();
//        v = q.front(); q.pop();
//        if (!u && !v) continue;
//        if ((!u || !v) || (u->val != v->val)) return false;
//
//        q.push(u->left);
//        q.push(v->right);
//
//        q.push(u->right);
//        q.push(v->left);
//    }
//    return true;
//}
//
//bool isSymmetric(TreeNode* root) {
//    return check(root, root);
//}


//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

