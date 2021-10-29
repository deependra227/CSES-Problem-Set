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
const lli INF = 1e18 + 1;
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
	int n , m , q ;
	cin >> n >> m >> q;
	vector < vector<lli>> dist(n + 1, vector<lli>(n + 1, INF));

	for(int i = 0 ; i <= n ; ++i)dist[i][i] = 0;

	for(int i = 0 ; i < m; ++i)
	{
		int u , v , w;
		cin >> u >> v >> w;
		dist[v][u] = dist[u][v] = min(dist[v][u], w);
	}

	for(int k = 1; k <= n ; ++k)
	{
		for(int u =  1 ; u <= n ; ++u)
		{
			for(int v = 1; v <= n; ++v)
			{
				dist[v][u] = dist[u][v] = min( dist[u][v], dist[u][k] + dist[k][v] );
			}
		}
	}


	while(q--)
	{
		int u , v;
		cin >> u >> v;

		if(dist[u][v] == INF)
			cout << -1 << '\n';
		else cout << dist[u][v] << '\n';
	}

	// for(auto& it : dist) {
	// 	for(auto& i : it)
	// 		cout << (i == INF ? -1 : i) << ' '; cout << endl;
	// }

	return 0;
}