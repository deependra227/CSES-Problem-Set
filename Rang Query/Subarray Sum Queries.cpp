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
vector<vector<lli>> segtree(1000000, vector<lli>(4, 0));
void build(vector<int>& a, int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = {a[start], a[start], a[start], a[start]};
		return;
	}

	int m = (start + end) / 2;
	build(a, start, m, 2 * pos + 1);
	build(a, m + 1, end, 2 * pos + 2);

	auto& l = segtree[2 * pos + 1];
	auto& r = segtree[2 * pos + 2];
	lli pref = max({l[2], l[1] + r[2]});
	lli suffix = max({r[3], l[3] +  r[1]});


	lli maxSum = max({l[0], r[0], l[3] + r[2]});

	lli totSum = l[1] + r[1];
	segtree[pos] = {maxSum, totSum, pref, suffix};

}
vector<lli> query(int a, int b, int start, int end, int pos)
{

	if( a <= start && end <= b)return segtree[pos];

	if(end < a || b < start)return {0, 0, 0, 0};

	if(start == end)return {0, 0};

	int m = (start + end) / 2;


	auto l = query(a, b, start, m, 2 * pos + 1);

	auto r = query(a, b, m + 1, end, 2 * pos + 2);

	lli pref = max({l[2], l[1] + r[2]});
	lli suffix = max({r[3], l[3] +  r[1]});


	lli maxSum = max({l[0], r[0], l[3] + r[2]});

	lli totSum = l[1] + r[1];
	return {maxSum, totSum, pref, suffix};
}

void update(int k, int newVal, int start, int end, int pos)
{
	if(start > end)return;

	if(start == end)
	{
		segtree[pos] = {newVal, newVal, newVal, newVal};
		return;
	}

	int m = (start + end) / 2;

	if(k <= m) update(k, newVal, start, m, 2 * pos + 1);
	else update(k, newVal, m + 1, end, 2 * pos + 2);

	auto& l = segtree[2 * pos + 1];
	auto& r = segtree[2 * pos + 2];
	lli pref = max({l[2], l[1] + r[2]});
	lli suffix = max({r[3], l[3] +  r[1]});


	lli maxSum = max({l[0], r[0], l[3] + r[2]});

	lli totSum = l[1] + r[1];
	segtree[pos] = {maxSum, totSum, pref, suffix};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n , q;
	cin >> n >> q;
	vector<int> x(n);
	sv(x);
	build(x, 0, n - 1, 0);

	while(q--)
	{

		int k , u;
		cin >> k >> u;
		update(k - 1 , u, 0, n - 1, 0);

		cout << max(0LL, query(0, n - 1, 0, n - 1, 0)[0]) << '\n';
		x[k - 1] = u;


	}

	return 0;
}