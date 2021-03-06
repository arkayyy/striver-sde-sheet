class Solution
{
public:
    // INTUITION: Sliding window + frequency map
    int lengthOfLongestSubstring(string s)
    {

        if (s.length() == 0)
            return 0;

        vector<int> freq(256, 0);

        int l = 0, r = 0;
        int maxLen = INT_MIN;

        while (r < s.length())
        {
            // increasing frequency of right pointer char
            freq[s[r]]++;

            while (freq[s[r]] > 1) // only when right pointer char is rep
            {
                freq[s[l]]--; // left pointer sliding one by one and simultaneously decreasing freq
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};