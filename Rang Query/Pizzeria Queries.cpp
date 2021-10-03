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
lli segtree[1000000];
lli segtree2[1000000];
void build(vector<int>& a, int start, int end, int pos)
{
	if(start == end)
	{
		segtree[pos] = a[start] + start;
		segtree2[pos] = a[start] - start;
		return;
	}

	int m = (start + end) / 2;
	build(a, start, m, 2 * pos + 1);
	build(a, m + 1, end, 2 * pos + 2);

	segtree[pos] = min(segtree[2 * pos + 1]  , segtree[2 * pos + 2]);
	segtree2[pos] = min(segtree2[2 * pos + 1]  , segtree2[2 * pos + 2]);
}
lli query1(int l, int r, int start, int end, int pos)
{
	if(end < l || r < start)return LLONG_MAX;

	if( l <= start && end <= r)return segtree[pos];

	int m = (start + end) / 2;
	lli t1 = query1(l, r, start, m, 2 * pos + 1);
	lli t2 = query1(l, r, m + 1, end, 2 * pos + 2);
	return min(t1 , t2);
}
lli query2(int l, int r, int start, int end, int pos)
{
	if(end < l || r < start)return LLONG_MAX;

	if( l <= start && end <= r)return segtree2[pos];

	int m = (start + end) / 2;
	lli t1 = query2(l, r, start, m, 2 * pos + 1);
	lli t2 = query2(l, r, m + 1, end, 2 * pos + 2);
	return min(t1 , t2);
}
void update(int k, int newVal, int start, int end, int pos)
{
	if(start > end)return;

	if(start == end)
	{
		segtree[pos] = newVal + start;
		segtree2[pos] = newVal - start;
		return;
	}

	int m = (start + end) / 2;

	if(k <= m) update(k, newVal, start, m, 2 * pos + 1);
	else update(k, newVal, m + 1, end, 2 * pos + 2);

	segtree[pos] = min(segtree[2 * pos + 1] , segtree[2 * pos + 2]);
	segtree2[pos] = min(segtree2[2 * pos + 1] , segtree2[2 * pos + 2]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	sv(p);
	build(p, 0, n - 1, 0);

	while(q--)
	{
		int type, l, r;
		cin >> type;

		if(type == 1)
		{
			int k , x;
			cin >> k >> x;
			update(k - 1, x, 0, n - 1, 0);
			p[k - 1] = x;
		}
		else {
			int k;
			cin >> k; k--;
			lli  t2 = query2(0, k - 1, 0, n - 1, 0);
			lli  t1 =  query1(k , n - 1, 0, n - 1, 0);
			cout << min(t1 - k, t2 + k) << '\n';
		}
	}

	return 0;
}