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
#include <iostream>

class Codec {

    // Utilities for joining and separating string by delimiters
    std::string join(std::vector<std::string> v, const std::string& delim) {
        std::stringstream ss;
        for (const auto& i : v) {
            // If this is not the first item, first append a delimiter
            if (&i != &v[0]) {
                ss << delim;
            }
            ss << i;
        }
        return ss.str();
    }

    std::vector<std::string> split(std::string s, char delim) {
        std::vector<std::string> elems;
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    // Do inorder traversal
    void dfs_serialize(TreeNode* root, std::vector<std::string>& res) {
        if (root == nullptr) {
            res.push_back("N");
            return;
        }

        // Recursive case: non-null node
        // Preorder traversal
        res.push_back(std::to_string(root->val));
        dfs_serialize(root->left, res);
        dfs_serialize(root->right, res);
    }

    TreeNode* dfs_deserialize(const std::vector<std::string>& v, int& i) {
        // Base case: if the node is null, increment index and return null tree
        if (v[i] == "N") {
            i++;
            return nullptr;
        }
        // Recursive case: non null node
        // Construct the tree here by preorder traversal:
        // 1. Create a node for this value and increment the index
        TreeNode* node = new TreeNode(std::stoi(v[i]));
        i++;
        // 2. Recursively construct the left and right subtrees
        node->left = dfs_deserialize(v, i);
        node->right = dfs_deserialize(v, i);
        // We're done constructing this subtree, so return a pointer to its root
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::vector<std::string> res;
        dfs_serialize(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::string> v = split(data, ',');
        // Construct this node, and point its left and right to the recurisvely deserialized subtrees
        int i = 0;
        TreeNode* root = dfs_deserialize(v, i);
        return root;
    }
};
