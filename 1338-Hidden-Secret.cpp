#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

	int t;
	char x[110];
	char y[110];
	char temp[110];
	int count[28];
	char c;
	int k;
	int ok;
	char ans[10];


	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		
		scanf("\n");
		fgets(x, 104, stdin);
		scanf("\n");
		fgets(y, 104, stdin);
		memset(count, 0, sizeof count);
		for (int i = 0; i < strlen(x); i++) {
			if(x[i] != ' ') {
				c = tolower(x[i]);
				k = c - 'a';
				count[k]++;
			}
		}

		for (int i = 0; i < strlen(y); i++) {
			if(y[i] != ' ') {
				c = tolower(y[i]);
				k = c - 'a';
				count[k]--;
			}
		}
		ok = 1;
		
		for (int i = 0; i < 26; i++) {
			if(count[i] != 0) {
				ok = 0;
				break;
			}
		}
		
		strcpy(ans, ok ? "Yes\0": "No\0");
		
		printf("Case %d: %s\n", cs, ans);
	}

}
		

		
