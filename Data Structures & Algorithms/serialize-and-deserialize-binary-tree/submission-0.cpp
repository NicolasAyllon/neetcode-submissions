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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> preorder;
        dfs(root, preorder);
    
        std::stringstream ss;
        ss << preorder[0];
        for (int i = 1; i < preorder.size(); ++i) {
            ss << "," << preorder[i];
        }
        // std::cout << ss.str() << '\n';
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string token;
        vector<string> preorder = {};
        while (std::getline(ss, token, ',')) {
            std::cout << token << '\n';
            preorder.push_back(token);
        }

        int index = 0;
        TreeNode* root = buildTree(index, preorder);
        return root;
    }

private:
    void dfs(TreeNode* node, vector<string>& vals) {
        // If the node is null, push back "N"
        if (node == nullptr) {
            vals.emplace_back("N");
            return;
        }
        // Otherwise, preorder traversal:
        // 1. append this node's value
        vals.emplace_back(std::to_string(node->val));
        // 2. process node's left child
        dfs(node->left, vals);
        // 3. process node's right child
        dfs(node->right, vals);
    }

    TreeNode* buildTree(int& i, const vector<string>& preorder) {
        // Build this TreeNode
        if (preorder[i] == "N") {
            ++i;
            return nullptr;
        }
        // Otherwise, we have a value (this node is not null)
        TreeNode* node = new TreeNode(std::stoi(preorder[i++]));
        node->left = buildTree(i, preorder);
        node->right = buildTree(i, preorder);

        return node;
    }
};
