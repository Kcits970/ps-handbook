using pii = pair<int, int>;
vector<vector<pii>> T;

pii dfs(int cur, int prev)
{
	int d = 0, v = cur;
	for (auto [next, w] : T[cur])
	{
		if (next == prev) continue;
		auto [dd, vv] = dfs(next, cur);
		if (dd+w > d) d = dd+w, v = vv;
	}

	return {d, v};
}

int diam()
{
	auto [d1, a] = dfs(1, 0);
	auto [d2, b] = dfs(a, 0);
	return d2;
}