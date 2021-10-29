#include <bits/stdc++.h>
using namespace std;

// /*Ordered Set*/
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
pair<int, int> t[100002];
int child[100002];
pair<int, int> dfs(vector<vector<int>>& adj, int u)
{
	if(u == (adj.size() - 1)) {
		return {1, 1};
	}

	if(t[u].first != -1)return t[u];

	if(adj[u].size() == 0)return {1, 0};

	int ans = 0;

	int flag = 0;

	for(auto& v : adj[u])
	{
		auto c = dfs(adj, v);

		if(c.second == 1)
			if(c.first > ans)
			{
				ans = c.first;
				child[u] = v;
				flag = 1;
			}
	}

	return t[u] = {ans + 1, flag};
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);

	for(int i = 0 ; i < m  ; ++i)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	memset(t, -1, sizeof t);
	memset(child, -1, sizeof child);

	auto ans = dfs(adj, 1);

	if(ans.second == 0)
	{
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}

	cout << t[1].first << '\n';
	int u = 1;

	while(u != -1) {
		cout << u << ' ';
		u = child[u];
	}

	return 0;
}