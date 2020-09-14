#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int& i : a)
		cin >> i;
	set<int> div;
	div.insert(0);
	for(int i = 0; i < n; i++){
		int x = a[i];
		while(x > 0){
			div.insert(x);
			x >>= 1;
		}
	}
	int mn = INT_MAX;
	for(auto res : div){
		vi cnt;
		for(int i = 0; i < n; i++){
			int x = a[i];
		  int acc = 0;
			while(res < x){
				acc++;
				x >>= 1;
			}
			if(res == x){
				cnt.push_back(acc);
			}
		}
		if(cnt.size() < k) continue;
		sort(cnt.begin(), cnt.end());
		mn = min(mn, accumulate(cnt.begin(), cnt.begin() + k, 0));
	}
	cout << mn << endl;
}
