#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int n, x;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> x >> s;
		int ans = 0;
		bool infAns = false;

		int cntZeros = (int)count(s.begin(), s.end(), '0');
		int total = cntZeros - (n - cntZeros);

		int bal = 0;
		for(int i = 0; i < n; i++) {

			if(total == 0 && bal == x) {
				infAns = true;
			}
			else if(abs(x - bal) % abs(total) == 0 && (x - bal) / total >= 0) {
				ans++;
			}
			
			s[i] == '0' ? bal++ : bal--;
		}

		if(infAns) ans = -1;
		cout << ans << endl;
	}
}
