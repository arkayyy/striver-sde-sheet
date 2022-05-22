#include <bits/stdc++.h> 

//INTUITION: If the cumulative sum at any two index is found to be same, that means the subarray b/w those 
//two indexes has a zero sum.

//ALGO: We use a map to see if the current cumulative sum has been encountered before, if encountered,
//we find the length between those 2 indexes.
int LongestSubsetWithZeroSum(vector < int > arr) {
	unordered_map<int,int> mp;
	int sum = 0;
	int ans = 0;
	mp[0] = -1;
	for(int i = 0; i<arr.size(); i++)
	{
		sum+=arr[i];
		if(mp.find(sum)!=mp.end()) {ans = max(ans, i-mp[sum]); mp[sum] = min(mp[sum],i);}
		else mp[sum] = i;
	}
	return ans;
}