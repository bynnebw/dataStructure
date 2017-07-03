/*
**  关于二叉树合并到问题，在leetcode中看到，但是并没有找到用c语言解决这个问题的方法
**  自己思来想去，也没有找到合适的方法来解决这个问题，先采用提供的c++版本的解决方法
**  黏贴在这里，作为日后的一个参考。这里主要是核心的解决问题的部分。
*/


//其实有关二叉树的解决问题，一班都会用递归方法来进行解决。其实一开始我也是想到使用递归的方法进行
//问题的求解的，但是鉴于c语言对于二叉树的定义与求解，自己不是很清楚，所以也只能暂时搁浅一段时间。

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 && t2 ) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
    }
};