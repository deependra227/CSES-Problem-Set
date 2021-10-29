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
	int n , m;
	cin >> n >> m;
	vector<string> grid(n);
	sv(grid);

	pii src, des;

	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			if(grid[i][j] == 'A') {src = {i, j};}
			else if(grid[i][j] == 'B') {des = {i, j};}

	vector<vector<int>> vis(n, vector<int>(m, 0)), parent(n, vector<int>(m, 0));

	queue <pii> q;
	q.push(src);
	vis[src.first][src.second] = 1;

	vector<int> dx = { -1, 1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	vector<char> dc = {'U', 'D', 'R', 'L'};

	while(!q.empty())
	{
		auto& [x, y] = q.front();
		q.pop();

		for(int i = 0 ; i < 4;  ++i)
		{
			int xx = x + dx[i] , yy = y + dy[i];

			if(xx < 0 || xx >= n || yy < 0 || yy >= m)continue;

			if(grid[xx][yy] == '#' || vis[xx][yy])continue;

			vis[xx][yy] = 1;
			parent[xx][yy] = i;
			q.push({xx, yy});

		}

	}

	if(vis[des.first][des.second])
	{
		cout << "YES" << '\n';
		string ans = "";

		while(des != src)
		{
			int p = parent[des.first][des.second];
			ans += dc[p];
			des = {des.first - dx[p], des.second - dy[p]};
		}

		reverse(ans.begin(), ans.end());
		cout << ans.length() << '\n';
		cout << ans << '\n';
	}
	else cout << "NO" << '\n';

	return 0;
}