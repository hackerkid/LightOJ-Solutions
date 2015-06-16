#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int m;

char a[100];
char b[100];
long long count;
unsigned long long ans2[40][40][40];
long long ans[40][40];
int temp;

unsigned long long explore2(int i, int j, int l)
{
	
	if(i == n and j != m) {
		return explore2(i, j+1, l-1);
	}

	if(j == m and i != n) {
		return explore2(i+1, j, l-1);
	}

	
	if(i == n and j == m and l == 0) {
		return 1;
	}
	
	if(i == n and j == m and l != 0) {
		return 0;
	}

	if(ans2[i][j][l] != -1) {
		return ans2[i][j][l];
	}

	if(a[i] == b[j]) {
		return ans2[i][j][l] = explore2(i+1, j+1, l -1);
	}

	return ans2[i][j][l] = explore2(i+1, j, l -1) + explore2(i, j+1, l -1);

}
int explore(int i, int j)
{
	if(i == n) {
		count++;
		return m - j;

	}

	if(j == m) {
		count++;
		return n - i;
	}

	if(ans[i][j] != -1) {
		return ans[i][j];
	}

	if(a[i] == b[j]) {
		return ans[i][j] = 1 + explore(i+1, j+1);
	}

	return ans[i][j] = 1 + min(explore(i+1, j),explore(i, j+1));

}
int main()
{
	int t;
	long long epic;
	scanf("%d", &t);

	for (int cs = 1; cs <= t ; cs++) {
		scanf("%s", a);
		scanf("%s", b);

		n = strlen(a);
		m = strlen(b);
		
		memset(ans, -1, sizeof(ans));
		
		temp = explore(0, 0);
		memset(ans2, -1, sizeof(ans2));
		epic = explore2(0, 0, temp);

		printf("Case %d: %d %lld\n",cs,temp,epic);

	}

}
