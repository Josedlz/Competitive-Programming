#include<bits/stdc++.h>
int i, j, n, m, K, x[10], y[10], C[1 << 22];
using namespace std;

int main() {
	ifstream I("input.txt");
	ofstream O("output.txt");

	I >> n >> m >> K; 
	for(; i < K; ++i){
		I >> x[i] >> y[i];
	}
	for(; j < n * m; ++j){
		C[j] = n + m;
		for(i = 0; i < K; ++i){
			C[j] = min(C[j], abs(j % n - x[i] + 1) + abs(j / n - y[i] + 1));
		}
	}
	for(i = j = 0; j < n * m; ++j){
		if(C[j] > C[0]){
			C[0] = C[j], i = j;
		}
	}
	O << i % n + 1 << ' ' << i / n + 1;
}
