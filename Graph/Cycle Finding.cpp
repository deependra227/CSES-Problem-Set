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
	int n , m ;
	cin >> n >> m ;
	vector<vector<int>> edges(m);
	vector<int> par(n + 1, -1);

	for(int i = 0 ; i < m; ++i)
	{
		int u , v , w;
		cin >> u >> v >> w;
		edges[i] = {u, v, w};

		if(u == v && w < 0) {
			cout << "YES" << '\n';

			cout << u << ' ' << v << '\n';
			return 0;
		}

	}

	vector<lli> dist(n + 1, INF);

	for(int i = 0 ; i < n - 1; ++i)
	{
		for(auto& e : edges)
		{
			if(dist[e[0]] + e[2] < dist[e[1]])
			{
				dist[e[1]] = dist[e[0]] + e[2];
				par[e[1]] = e[0];

			}
		}
	}

	int end = -1 , start = -1;

	for(auto& e : edges)
	{
		if(dist[e[0]] + e[2] < dist[e[1]])
		{
			par[e[1]] = e[0];
			end = e[1];
			break;
		}
	}

	if(end != -1)
	{
		cout << "YES" << '\n';
		vector<int> ans;

		/*
			Case1 : End node belongs to Negative cycle
			Case2 : There is -ve cycle leading to this particular node.
			To make sure that the node belong to cycle
			we will go iterate n-1 time
				end = par[end]
			this will work beacuse cycle can be atmost n-1 node away from
			the current node(end)

		*/
		for (int i = 0; i < n; ++i)
			end = par[end];

		start = end;

		while(1)
		{
			ans.push_back(end);
			end = par[end];

			if(start == end && ans.size() > 1)break;
		}

		ans.push_back(start);
		reverse(ans.begin(), ans.end());
		pv(ans);
	}
	else cout << "NO" << '\n';

	return 0;
}