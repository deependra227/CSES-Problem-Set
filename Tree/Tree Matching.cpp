#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define sv(a) for (auto &it : a) cin >> it;
#define pv(a)  for (auto & it : a)     cout << it << " ";  cout << '\n';
#define all(x) (x).begin(), (x).end()
#define pv2(a) for(auto& it : a){for(auto i : it)cout << i << ' ';cout << '\n';}
const int MOD = 1e9 + 7;
const lli INF = 1e18 + 2;
typedef pair<int, int> pii;
int add(int a, int b) {
	if(a + b >= MOD) {
		return a + b - MOD;
	}

	return a + b;
}
int prod(int a, int b) {
	return (a * 1LL * b) % MOD;
}
bool compareBysecond(pair<lli, lli> a, pair<lli, lli> b)
{
	if (a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}
int log(lli x)
{
	int cnt = 0;

	while (x > 0)
	{
		cnt++;
		x = x >> 1;
	}

	return cnt;
}
lli max(lli a, lli b)
{
	if (a < b) return b;
	else return a;
}
lli min(lli a, lli b)
{
	if (a > b) return b;
	else return a;
}

int dp[200002][2];
int dfs(vector<vector<int>>& adj, int u , int par, int flag)
{
	// cout << u << flag << ' ' << dp[u][flag] << endl;

	if(dp[u][flag] != -1)return dp[u][flag];

	if(flag) {
		dp[u][flag] = 0;

		for(auto& v : adj[u])
			if(v != par) dp[u][flag] += dfs(adj, v, u, 0);
	}
	else {
		int sum = 0;

		for(auto& v : adj[u])
			if(v != par)sum += dfs(adj, v, u, 0);

		dp[u][flag] = 0;

		for(auto& v : adj[u])
			if(v != par)
				dp[u][flag] = max(dp[u][flag], sum - dfs(adj, v, u, 0) + dfs(adj, v, u, 1) + 1);
	}

	return dp[u][flag];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n;
	vector<vector<int>> adj(n + 1, vector<int>());

	for(int i = 0 ; i < n - 1; ++i)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dp, -1, sizeof dp);

	cout << dfs(adj, 1, 0, 0) << '\n';

	return 0;
}