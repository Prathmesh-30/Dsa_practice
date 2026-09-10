class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> nge;

        // Find Next Greater Element for every element in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove elements that cannot be the answer
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, there is no greater element
            if (st.empty()) {
                nge[nums2[i]] = -1;
            } 
            else {
                nge[nums2[i]] = st.top();
            }

            // Current element becomes a candidate
            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};