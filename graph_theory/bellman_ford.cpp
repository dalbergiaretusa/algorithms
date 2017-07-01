#include <bits/stdc++.h>
#define inf 100100100
#define mp make_pair
#define f first
#define s second

using namespace std;
int n, m, s, a, b, c;

vector<pair<int, int > >g[555];
vector<int>dist;
int pred[555];

bool bell() {
	int c=n;
	while(c--) {
		for(int i=0; i<=n; i++) {
			for(int j=0; j<(int)g[i].size(); j++) {
				if(dist[g[i][j].f]>dist[i]+g[i][j].s) {
					dist[g[i][j].f]=dist[i]+g[i][j].s;
					pred[g[i][j].f]=i;
				}
			}
		}

	}
	for(int i=0; i<=n; i++) {
		for(int j=0; j<(int)g[i].size(); j++) {
			if(dist[g[i][j].f]>dist[i]+g[i][j].s) {
				printf("NIE\n");
				return 0;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	dist.resize(n+1, inf);
	dist[s]=0;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(mp(b, c));
	}
	if(bell()) {
		for(int i=0; i<=n; i++) {
			if(dist[i]!=inf and i!=s) {
				printf("%d %d\n", i, dist[i]);
			}
		}
	}
	else return 0;
}
