You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            mp[ch] = i;
        }
        vector<int>ans;
        int maxi=0;
        int prev = -1;
        for(int i=0;i<s.size();i++)
        {
            maxi = max(maxi,mp[s[i]]);
            if(maxi==i)
            {
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;
    }
};