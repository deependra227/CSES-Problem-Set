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

int t[5001][5001];
int solve(string& s, string& l, int n, int m)
{
	if(n == 0)return m;

	if(m == 0)return n;

	if(t[n][m] != -1)return t[n][m];

	if(s[n - 1] == l[m - 1])
		return t[n][m] = solve(s, l, n - 1, m - 1);

	return t[n][m] = min({solve(s, l, n - 1, m - 1), solve(s, l, n, m - 1), solve(s, l, n - 1, m)}) + 1;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	string s, l;
	cin >> s >> l;
	memset(t, -1, sizeof(t));
	cout << solve(s, l, s.length(), l.length()) << '\n';

	return 0;
}