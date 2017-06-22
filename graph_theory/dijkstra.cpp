/*
	Author: Sebastian Ksiazczyk
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pp pair<long long, long long>
#define inf 1020304050002137
#define MAX_N 3010
using namespace std;
typedef long long int ll;

ll d[MAX_N];
vector <pp> g[MAX_N];
ll edge[MAX_N][MAX_N];
ll odl, w, res, a, b, c, dis, v;
int n, m, q, startNode;
priority_queue<pp, vector<pp>, greater<pp> >Q;

void dijkstra(int b) {
	d[b] = 0;
	Q.push(mp(0, b));
	while(!Q.empty()) {
		odl = Q.top().f;
    w = Q.top().s;
		Q.pop();

		for(int i=0; i<int(g[w].size()); i++) { //for every neighbour
			v = g[w][i].f; //neighbour no
			dis = g[w][i].s; //me--neighbour edge weight
			if(d[v] > d[w] + dis) { // if target -me- neighbour is a shorter way than target -- neighbour
				d[v] = d[w] + dis; // update the edge
				Q.push(mp(d[v], v)); // add the new edge to the queue
			}
		}
	}
	return;
}

int main() {

  scanf("%d", &q);
	while(q--) {
    scanf("%d%d", &n, &m); // vertices, edges
    for(int i=1; i<=n; i++) {
      d[i] = inf;
      g[i].clear();
      for(int j=1; j<=n; j++) {
        edge[i][j] = inf;
      }
    }

		// if no parallel edges allowed:
		/*
    for(int i=1; i<=m; i++) {
      scanf("%lld%lld%lld", &a, &b, &c);
          g[a].pb(mp(b, c));
          g[b].pb(mp(a, c));
    }
		*/

		// if parallel edges allowed (eliminates them as we only consider the shorest)
    for(int i=1; i<=m; i++) {
      scanf("%lld%lld%lld", &a, &b, &c);
      edge[a][b] = min(edge[a][b], c);
      edge[b][a] = min(edge[b][a], c);
    }
    for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
        if(edge[i][j] != inf) {
          g[i].pb(mp(j, edge[i][j]));
          g[j].pb(mp(i, edge[i][j]));
        }
      }
    }
		// dijkstra(1);
    scanf("%d", &startNode);
    dijkstra(startNode);
    for(int i=1; i<=n; i++) {
      if(i != startNode) {
        printf("%lld ", (d[i]!=inf ? d[i] : -1));
      }
    }
    printf("\n");
  }
}
