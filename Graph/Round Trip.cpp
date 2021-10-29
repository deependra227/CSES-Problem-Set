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
int cycle_end;
int dfs(vector<vector<int>>& adj, vector<int>& vis, int u, vector<int>& par)
{
	vis[u] = 1;

	for(auto& v : adj[u])
	{
		if(v == par[u])continue;

		par[v] = u;

		if(vis[v] == 1)
		{
			cycle_end = v;
			return true;
		}


		if(vis[v] == 0)
			if(dfs(adj, vis, v, par)) return true;


	}

	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n , m ;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>());
	vector<int> vis(n + 1, 0), par(n + 1, -1);

	for(int i = 0 ; i < m ; ++i)
	{
		int a , b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cycle_end = -1;

	for(int i = 1; i <= n ; ++i)
	{
		if(vis[i] == 0 && dfs(adj, vis, i, par))break;
	}

	if(cycle_end == -1)cout << "IMPOSSIBLE" << '\n';
	else {
		int start = cycle_end;
		vector<int> ans;
		ans.push_back(cycle_end);
		cycle_end = par[cycle_end];

		while(cycle_end != start)
		{
			ans.push_back(cycle_end);
			cycle_end = par[cycle_end];
		}

		ans.push_back(start);
		cout << ans.size() << '\n';
		pv(ans);

	}

	return 0;
}