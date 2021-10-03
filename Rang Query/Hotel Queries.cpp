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
lli segtree[1000000];
void build(vector<int>& a, int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = a[start];
		return;
	}

	int m = (start + end) / 2;
	build(a, start, m, 2 * pos + 1);
	build(a, m + 1, end, 2 * pos + 2);
	segtree[pos] = max(segtree[2 * pos + 1]  , segtree[2 * pos + 2]);
}
lli query(int val, int start, int end, int pos)
{
	if(segtree[pos] < val)return -1;

	if(start == end)return start;


	int m = (start + end) / 2;

	if(segtree[2 * pos + 1] >= val)
		return query(val, start, m, 2 * pos + 1);
	else
		return query(val, m + 1, end, 2 * pos + 2);
}

void update(int k, int newVal, int start, int end, int pos)
{
	if(start > end)return;

	if(start == end)
	{
		segtree[pos] = newVal;
		return;
	}

	int m = (start + end) / 2;

	if(k <= m) update(k, newVal, start, m, 2 * pos + 1);
	else update(k, newVal, m + 1, end, 2 * pos + 2);

	segtree[pos] = max(segtree[2 * pos + 1] , segtree[2 * pos + 2]);
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
	vector<int> h(n);
	sv(h);
	build(h, 0, n - 1, 0);

	while(m--)
	{
		int r;
		cin >> r;
		int idx = query(r, 0, n - 1, 0);

		if(idx == -1)
		{
			cout << 0 << ' ';
		}
		else {
			cout << idx + 1 << ' ';
			// cout << h[idx] << ' ' << r << endl;
			update(idx, h[idx] - r, 0, n - 1, 0);
			h[idx] -= r;

		}
	} cout << endl;

	// pv(h);
	return 0;
}