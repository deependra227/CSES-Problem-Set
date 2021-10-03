#include <bits/stdc++.h>
using namespace std;
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
vector<pii> dir = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(vector<string>& grid, int i , int j)
{
	if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].length())return;

	if(grid[i][j] == '#')return;

	grid[i][j] = '#';

	for(auto& [dx, dy] : dir)
		dfs(grid, i + dx, j + dy);

	return;
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
	int ans = 0;

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ; ++j)
		{
			if(grid[i][j] == '.')
				dfs(grid, i, j), ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}