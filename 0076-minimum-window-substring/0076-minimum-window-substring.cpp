class Solution {
public:
    string minWindow(string s, string t) {

        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> need;
        unordered_map<char, int> have;

        // Count characters required from t
        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            // Put current character into window
            have[c]++;

            // Did we just satisfy a required character?
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            // Window contains everything we need
            while (formed == required) {

                // Check if this window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];

                have[leftChar]--;

                // Did removing it break the requirement?
                if (need.count(leftChar) &&
                    have[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};