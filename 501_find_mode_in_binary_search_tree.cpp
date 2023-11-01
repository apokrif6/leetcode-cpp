//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

//If the tree has more than one mode, return them in any order.

//Assume a BST is defined as follows:

//    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//    Both the left and right subtrees must also be binary search trees.

//Example 1:
//Input: root = [1,null,2,2]
//Output: [2]

//Example 2:
//Input: root = [0]
//Output: [0]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int currentVal, currentCount, maxCount = 0;
    std::vector<int> modes;
    void traversal(TreeNode* node) {
        if (!node)
            return;

        traversal(node->left);

        currentCount = node->val == currentVal ? currentCount + 1 : 1;
        
        if (currentCount == maxCount) {
            modes.push_back(node->val);
        } else if (currentCount > maxCount) {
            maxCount = currentCount;
            modes = {node->val};
        }

        currentVal = node->val;

        traversal(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);

        return modes;
    }
};
