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
	vector<vector<int>> adj(n + 1);
	vector<int> indegree(n + 1, 0);

	for(int i = 0 ; i < m  ; ++i)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;

	for(int i = 1; i <= n ; ++i)if(indegree[i] == 0)q.push(i);

	vector<int> ans;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		ans.push_back(u);

		for(auto& v : adj[u])
		{
			indegree[v]--;

			if(indegree[v] == 0)
				q.push(v);
		}
	}

	if(ans.size() != n) cout << "IMPOSSIBLE" << '\n';
	else pv(ans);

	return 0;
}