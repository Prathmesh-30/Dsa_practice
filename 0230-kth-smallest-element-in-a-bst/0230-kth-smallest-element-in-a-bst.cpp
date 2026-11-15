class Solution {
private:
    void inorder(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        inorder(root, values);

        return values[k - 1];
    }
};