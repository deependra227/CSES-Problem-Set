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

	vector < vector<pair<int, int>>> adj(n + 1);

	for(int i = 0 ; i < m ; ++i)
	{
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	lli dist[n + 1], ways[n + 1], min_f[n + 1], max_f[n + 1], vis[n + 1];

	for(int i = 1 ; i <= n; ++i)
	{
		dist[i] = LLONG_MAX;
		ways[i] = 0;
		min_f[i] = LLONG_MAX;
		max_f[i] = LLONG_MIN;
		vis[i] = 0;
	}

	dist[1] = 0;
	ways[1] = 1;
	min_f[1] = 0;
	max_f[1] = 0;

	priority_queue<pair<lli, int>> pq;
	pq.push({0, 1});

	while(!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();

		if(vis[u])continue;

		vis[u] = 1;

		for(auto [v, c] : adj[u])
		{
			if(dist[u] + c > dist[v])continue;

			if(dist[u] + c  == dist[v])
			{
				ways[v] = add(ways[v], ways[u]);
				min_f[v] = min(min_f[v], min_f[u] + 1);
				max_f[v] = max(max_f[v], max_f[u] + 1);
			}
			else {
				dist[v] = dist[u] + c;
				ways[v] = ways[u];
				min_f[v] = min_f[u] + 1;
				max_f[v] = max_f[u] + 1;
				pq.push({ -dist[v], v});
			}
		}
	}

	cout << dist[n] << ' ' << ways[n] << ' ' << min_f[n] << ' ' << max_f[n] << '\n';

	return 0;
}