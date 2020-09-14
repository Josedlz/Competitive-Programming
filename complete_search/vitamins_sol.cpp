#include<bits/stdc++.h>
#define INF 2e9
using namespace std;
char s[5];
int dp[14];

int main(){
	int n,c;
	dp[0] = 0;
	for(int i = 1; i <= 7; i++)
		dp[i] = INF;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d%s", &c, s);
		int len = strlen(s), sum = 0;
		for(int j = 0; j < len; j++)
			sum |= (1<<(s[j] - 'A'));
		for(int j = 0; j <= 7; j++)
			dp[j|sum] = min(dp[j|sum], dp[j] + c);
	}
	if(dp[7] == INF)
		dp[7] = -1;
	printf("%d\n", dp[7]);
	return 0;
}

