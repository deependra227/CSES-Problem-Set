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
bool compare(vector<int>& a, vector<int>& b)
{
	return a.size() > b.size();
}
vector<int> ans;
vector<int> dfs(vector<vector<int>>& adj, int u, int par)
{
	vector<vector<int>> c;

	for(auto& v : adj[u])
		if(v != par)
			c.push_back(dfs(adj, v, u));

	sort(c.begin(), c.end(), compare);

	if(c.size() == 0)c.push_back({});

	c[0].push_back(u);

	if(c.size() > 1)
	{
		if(c[0].size() + c[1].size() + 1 > ans.size())
		{
			ans = {};

			for(auto& it : c[0])ans.push_back(it);

			for(auto& it : c[1])ans.push_back(it);
		}
	}

	if(c[0].size() > ans.size())ans = c[0];

	return c[0];
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
	cin >> n;
	vector<vector<int>> adj(n + 1, vector<int>());

	for(int i = 0 ; i < n - 1;  ++i)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans.clear();
	ans = {1};
	dfs(adj, 1, 0);
	pv(ans);
	return 0;
}