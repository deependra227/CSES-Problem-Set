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
int segtree[1000000];
void build(int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = 1;
		return;
	}

	int m = (start + end) / 2;
	build(start, m, 2 * pos + 1);
	build(m + 1, end, 2 * pos + 2);
	segtree[pos] = segtree[2 * pos + 1] + segtree[2 * pos + 2];
}
int query(int p, int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = 0;
		return start;
	}

	int m = (start + end) / 2;
	int q;

	if(segtree[2 * pos + 1] >= p)
		q = query(p, start, m, 2 * pos + 1);
	else
		q = query(p - segtree[2 * pos + 1], m + 1, end, 2 * pos + 2);

	segtree[pos] = segtree[2 * pos + 1] + segtree[2 * pos + 2];
	return q;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> x(n);
	sv(x);
	build(0, n - 1, 0);

	for(int  i = 0 ; i < n ; ++i)
	{
		int p;
		cin >> p;
		cout << x[query(p, 0, n - 1, 0)] << ' ';
	}

	return 0;
}