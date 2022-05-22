// VIDEO EXPLANATION: https://www.youtube.com/watch?v=2NI0cB1lc1E

int Solution::solve(vector<int> &A, int B)
{
    vector<int> prefixXor(A.size());
    unordered_map<int, int> mp;
    prefixXor[0] = A[0];
    for (int i = 1; i < A.size(); ++i)
        prefixXor[i] = A[i] ^ prefixXor[i - 1];
    int ans = 0;
    for (int i = 0; i < prefixXor.size(); ++i)
    {
        if (prefixXor[i] == B)
            ++ans;
        int xor1 = prefixXor[i] ^ B; // if upto index i i.e. prefixXor[i],  there had been a subarray whose xor is B.
        // Then, by xorring B again, we eleminate that B. So the rest part should be present as a previous prefix xor
        // value that we had encountered.
        if (mp.find(xor1) != mp.end())
            ans += mp[xor1]; // so how many times we encountered that xor value, we add it to our answer
        ++mp[prefixXor[i]];
    }
    return ans;
}
