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

void dfs(vector<vector<int>>& up, vector<vector<int>>& adj, int u, int p)
{
	up[u][0] = p;
	int l = ceil(log2(adj.size() - 1));

	for(int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];

	for(auto& v : adj[u])
		if(v != p)
			dfs(up, adj, v, u);

}
int kth_ancestor(vector<vector<int>>& up, int x, int k)
{
	int l = floor(log2(k));

	if((k & (k - 1)) == 0)return up[x][l];

	while(l)
	{
		if(up[x][l] != 0)
			x = up[x][l];

		l--;
	}

	return up[x][l] ? up[x][l] : -1;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<vector<int>> adj(n + 1, vector<int>());

	for(int i = 2 ; i <= n ; ++i)
	{
		int v;
		cin >> v;
		adj[v].push_back(i);
		adj[i].push_back(v);
	}

	int l = ceil(log2(n));

	vector<vector<int>> up(n + 1, vector<int>(l + 1));
	dfs(up, adj, 1, 0);

	while(q--)
	{
		int x , k;
		cin >> x >> k;
		cout << kth_ancestor(up, x, k) << '\n';
	}

	return 0;
}