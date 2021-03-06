//Binary Tree Paths
//Given a binary tree, return all root-to-leaf paths.
//For example, given the following binary tree:
//   1
// /   \
//2     3
// \
//  5
//All root-to-leaf paths are:
//["1->2->5", "1->3"]
//Explore at each node

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;

    binaryTreePaths(result, root, to_string(root->val));
    return result;
}


// c++ initializer 
// http://en.cppreference.com/w/cpp/utility/initializer_list
vector<string> binaryTreePaths(TreeNode* root) {
  if (root == nullptr)
    return {};
  if (root->left == nullptr && root->right == nullptr)
    return {to_string(root->val)};

  vector<string> left  = binaryTreePaths(root->left);
  vector<string> right = binaryTreePaths(root->right);
  left.insert(left.end(), begin(right), end(right));
  for (auto &e : left)
    e = to_string(root->val) + "->" + e;
  return left;
}
