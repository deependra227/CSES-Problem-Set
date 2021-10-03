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
pair<lli, lli> segtree[1000000];
void build(vector<int>& a, int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = {a[start], max(0, a[start])};
		return;
	}

	int m = (start + end) / 2;
	build(a, start, m, 2 * pos + 1);
	build(a, m + 1, end, 2 * pos + 2);
	lli pref = max(segtree[2 * pos + 1].second  , segtree[2 * pos + 1].first + segtree[2 * pos + 2].second);
	lli sum = segtree[2 * pos + 1].first  + segtree[2 * pos + 2].first;
	segtree[pos] = {sum, pref};
}
pair<lli, lli> query(int a, int b, int start, int end, int pos)
{

	if( a <= start && end <= b)return segtree[pos];

	if(end < a || b < start)return {0, 0};

	if(start == end)return {0, 0};

	int m = (start + end) / 2;

	auto t1 = query(a, b, start, m, 2 * pos + 1);

	auto t2 = query(a, b, m + 1, end, 2 * pos + 2);

	lli pref = max(t1.second  , t1.first + t2.second);

	lli sum = t1.first  + t2.first;

	return {sum, pref};
}

void update(int k, int newVal, int start, int end, int pos)
{
	if(start > end)return;

	if(start == end)
	{
		segtree[pos] = {newVal, max(0LL, newVal)};
		return;
	}

	int m = (start + end) / 2;

	if(k <= m) update(k, newVal, start, m, 2 * pos + 1);
	else update(k, newVal, m + 1, end, 2 * pos + 2);

	lli pref = max(segtree[2 * pos + 1].second  , segtree[2 * pos + 1].first + segtree[2 * pos + 2].second);
	lli sum = segtree[2 * pos + 1].first  + segtree[2 * pos + 2].first;
	segtree[pos] = {sum, pref};
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
		int type;
		cin >> type;

		if(type == 1)
		{
			int k , u;
			cin >> k >> u;
			update(k - 1 , u, 0, n - 1, 0);
			x[k - 1] = u;

		}
		else
		{
			int a, b;
			cin >> a >> b;
			cout << query(a - 1 , b - 1  , 0, n - 1 , 0).second   << '\n';

		}
	}

	return 0;
}