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
	cin >> n >> m;
	vector<string> grid(n);
	sv(grid);
	vector<pair<int, int>> q;
	vector<pair<int, int>> monsters;
	vector<vector<char>> par(n, vector<char>(m, '@'));

	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ; ++j) {
			if(grid[i][j] == 'A') {
				q.push_back({i, j});
			}

			if(grid[i][j] == 'M')monsters.push_back({i, j}), grid[i][j] = 'M';
		}
	}

	vector<int> dx = { -1, 1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	string dc = "UDRL";
	int flag = 0;
	pii des = { -1, -1};

	while(q.size())
	{
		vector<pii> newMosters, newQ;

		for(auto& [i, j] : monsters)
		{
			for(int k = 0 ; k < 4 ; ++k)
			{
				int Mi = dx[k] + i, Mj = dy[k] + j;

				if(Mi < 0 || Mj < 0 || Mi >= n || Mj >= m)continue;

				if(grid[Mi][Mj] != '.')continue;

				grid[Mi][Mj] = 'M';
				newMosters.push_back({Mi, Mj});
			}
		}

		for(auto& [x, y] : q)
		{
			if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {
				flag = 1;
				des = {x, y};
				break;
			}

			for(int k = 0 ; k < 4 ; ++k)
			{
				int Ai = dx[k] + x;
				int Aj = dy[k] + y;

				if(Ai < 0 || Aj < 0 || Ai >= n || Aj >= m)continue;


				if(grid[Ai][Aj] != '.')continue;


				grid[Ai][Aj] = 'A';
				par[Ai][Aj] = dc[k];

				if(Ai == 0 || Aj == 0 || Aj == m - 1 || Ai == n - 1) {
					flag = 1;
					des = {Ai, Aj};
					break;
				}

				newQ.push_back({Ai, Aj});
			}

			if(flag)break;
		}

		if(flag)break;

		monsters = newMosters;
		q = newQ;
	}


	// pv2(grid);

	if(flag) {
		cout << "YES" << '\n' ;
		string ans = "";
		auto [x, y] = des;

		while(par[x][y] != '@')
		{
			ans += par[x][y];

			if(par[x][y] == 'L')y++;
			else if(par[x][y] == 'R')y--;
			else if(par[x][y] == 'U')x++;
			else x--;
		}

		reverse(ans.begin(), ans.end());
		cout << ans.length() << '\n';
		cout << ans << '\n';
	}
	else
		cout << "NO\n";

	return 0;
}