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
int cycle;
bool dfs(vector<vector<int>>& adj, int u , vector<int>& vis, vector<int>& par )
{
	vis[u] = 1;

	for(auto& v : adj[u])
	{

		par[v] = u;

		if(vis[v] == 1) {
			cycle = v;
			return true;
		}

		if(vis[v] == 2)continue;

		if(vis[v] == 0 && dfs(adj, v, vis, par)) return true;;
	}


	vis[u] = 2;

	return false;
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

	vector<int> vis(n + 1, 0), par(n + 1, -1);
	cycle = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(vis[i] != 0)continue;

		if(dfs(adj, i, vis, par)) break;

	}


	if(cycle == -1)cout << "IMPOSSIBLE" << '\n';
	else {
		vector<int> ans;
		int start = cycle;
		ans.push_back(cycle);
		cycle = par[cycle];

		while(start != cycle)
		{
			ans.push_back(cycle);
			cycle = par[cycle];

			if(cycle < 0 )break;
		}

		ans.push_back(cycle);
		reverse(all(ans));
		cout << ans.size() << '\n';
		pv(ans);
	}

	return 0;
}