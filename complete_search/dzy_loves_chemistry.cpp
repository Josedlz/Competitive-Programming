#include <bits/stdc++.h>
#define A first
#define B second
#define rep(i, a, b) for(int i = a; i <= b; i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

vi adj[55];
bool vis[55];

ll exp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1){
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}

int dfs(int v){
	vis[v] = true;
	int cnt = 0;
	for(int w: adj[v]){
		if(not vis[w])
			cnt += (1 + dfs(w));
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	rep(i, 1, n){
		if(not vis[i]){
			int res = dfs(i);
			ans += res;
		}
	}
	cout << exp(2, ans) << endl;
}


