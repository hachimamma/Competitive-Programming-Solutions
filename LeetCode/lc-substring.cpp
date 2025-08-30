#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size(); right++) {
            if (lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};