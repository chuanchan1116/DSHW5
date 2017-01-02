#include <iostream>
#include <iomanip>

using namespace std;

void createmap(int *a);
void dumparr(int *a);
bool DFSLoop(int *a);
void kruskal(int *a);
void prim(int *a);
int visited[10];

int main()
{
    int matrix[100]= {0};
    createmap(matrix);
    dumparr(matrix);
    kruskal(matrix);
    prim(matrix);
    return 0;
}

void dumparr(int *a)
{
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cout << setw(3) << a[i*10+j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void createmap(int *a)
{
    int start,dest,weight;
    int cnt;
    cin >> cnt;
    while(cnt) {
        cin >> start >> dest >> weight;
        cnt--;
        a[start*10+dest]=weight;
        a[dest*10+start]=weight;
    }
}

/* test case
12
0 9 1
0 1 2
1 2 4
1 3 3
1 4 5
3 4 6
1 5 7
5 6 9
6 7 8
7 8 10
8 9 11
3 5 12
*/

void prim(int *a)
{
    int ans[100] = {0}, dis[10], vis[10] = {0}, parrent[10];
    cout << "Prim's Algorithm:" << endl;
    for(int i = 0; i < 10; i++){
        dis[i] = 2147483647; // distance to MST
	parrent[i] = i; // consider every node as a tree of itself; union with other tree at each selection
    }
    dis[0] = 0;
    for(int j = 0; j < 10; j++){
    	int min = 2147483647, choose = -1;
        for(int i = 0; i < 10; i++){
            if(!vis[i] && dis[i] < min){ // find the closest node
	        choose = i;
	        min = dis[i];
	    }
        }
        if(choose == -1) return; // no more nodes
        ans[parrent[choose] * 10 + choose] = dis[choose];
	ans[choose * 10 + parrent[choose]] = dis[choose];
        dumparr(ans);
        vis[choose] = 1;
        for(int i = 0; i < 10; i++){
            if(!vis[i] && a[choose * 10 + i] && a[choose * 10 + i] < dis[i]){
	        dis[i] = a[choose * 10 + i]; // update distance to the current MST
	        parrent[i] = choose; // union nodes to the current MST
	    }
        }
    }
}

void kruskal(int *a)
{
    cout << "Kruskal's Algorithm:" << endl;
}

bool DFSLoop(int *a, int x)
{
    visited[x] = true;
    for(int i = 0; i < 10; i++){
        if(a[x * 10 + i]){
	    if(visited[i] || DFSLoop(a, i))  return true; // it is looped when visit a visited node or it's subgraph is looped
	}
    }
    visited[x] = false;
    return false;
}
