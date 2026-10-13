/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        queue<TreeNode*> bfs;
        unordered_set<TreeNode*> visited;

        bfs.push(target);
        visited.insert(target);

        int distance = 0;

        while (!bfs.empty()) {
            int size = bfs.size();

            if (distance == k) {
                vector<int> ans;

                while (!bfs.empty()) {
                    ans.push_back(bfs.front()->val);
                    bfs.pop();
                }

                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    bfs.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    bfs.push(node->right);
                }

                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    bfs.push(parent[node]);
                }
            }

            distance++;
        }

        return {};
    }
};