#define BELLMAN_FORD_MAX_E 10005
#define BELLMAN_FORD_MAX_V 10005

#include <memory.h>

struct edge{ int from, to, cost; };

edge es[BELLMAN_FORD_MAX_E];

int d[BELLMAN_FORD_MAX_V];
int V, E;

void shortest_path(int s){
    for (int i = 0; i < V; i++ ) d[i] = (1<<21);
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != (1<<21) && d[e.to] > d[e.from] + e.cost ) {
                d[e.to] = d[e.from] = e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

bool find_negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                if (i == V - 1) return true;
            }
        }
    }
    return false;
}
