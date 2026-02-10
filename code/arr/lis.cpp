void solve()
{
	int n;
	vector<int> A(n+1);

	int sz = 0; // length of lis.
	vector<int> dp(n+1, INT_MAX); dp[0] = INT_MIN;
	vector<int> loc(n+1), trace(n+1);

	for (int i = 1; i <= n; i++)
	{
		int j = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		sz = max(sz, j), dp[j] = A[i], loc[j] = i, trace[i] = loc[j-1];
	}

	// lis traceback (1-based).
	vector<int> lis(1);
	for (int i = loc[sz]; i >= 1;)
	{
		lis.push_back(A[i])
		i = trace[i];
	}
	reverse(lis.begin()+1, lis.end());
}
