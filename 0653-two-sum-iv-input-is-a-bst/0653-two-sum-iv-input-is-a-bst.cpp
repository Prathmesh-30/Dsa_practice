class Solution {
private:
    class BSTIterator {
        stack<TreeNode*> st;
        bool reverse;

        void pushAll(TreeNode* node) {
            while (node) {
                st.push(node);
                node = reverse ? node->right : node->left;
            }
        }

    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        TreeNode* peek() {
            return st.top();
        }

        int next() {
            TreeNode* node = st.top();
            st.pop();

            if (reverse)
                pushAll(node->left);
            else
                pushAll(node->right);

            return node->val;
        }
    };

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false);
        BSTIterator right(root, true);

        while (left.peek() != right.peek()) {
            int sum = left.peek()->val + right.peek()->val;

            if (sum == k)
                return true;
            else if (sum < k)
                left.next();
            else
                right.next();
        }

        return false;
    }
};