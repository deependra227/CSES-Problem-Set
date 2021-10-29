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
void dijsktra(vector<vector<pii>>& adj, vector<lli>& dist, int src)
{
	vector<int> vis(adj.size(), 0);
	priority_queue<pair<lli, int>> pq;
	pq.push({0, src});
	dist[src] = 0;

	while(!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();

		if(vis[u])continue;

		vis[u] = 1;

		for(auto& [v, w] : adj[u])
		{
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				pq.push({ -dist[v], v});
			}

		}

	}
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
	cin >> n >> m ;
	vector<vector<pii>> adj1(n + 1, vector<pii>()), adj2(n + 1);
	vector<vector<int>> edges(m);


	for(int i = 0 ; i < m; ++i)
	{
		int u , v , w;
		cin >> u >> v >> w;
		adj1[u].push_back({v, w});
		adj2[v].push_back({u, w});
		edges[i] = {u, v, w};
	}

	vector<lli> dist1(n + 1, INF), dist2(n + 1, INF);
	dijsktra(adj1, dist1, 1);
	dijsktra(adj2, dist2, n);
	lli ans = INF;

	/*
	  1 -> ith ----- (i+1)th -> N
	  Ans = Min of dist1 + w/2 + dist2.

	  dist1 = distance betwen 1 to ith node . Forward Dijkstra
	  To get distance between (i+1)th node to Nth node. It is equivalent of distance betwen
	  Nth node to (i+1)th => Take Nth node as source and run dijkstra algo.

	*/

	for(auto& e : edges)
	{
		int u = e[0], v = e[1] , w = e[2];
		ans = min(ans, dist1[u] + w / 2 + dist2[v]);
	}

	cout << ans << endl;


	return 0;
}