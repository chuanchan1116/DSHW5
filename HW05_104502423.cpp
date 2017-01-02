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
    cout << "Prim's Algorithm:" << endl;
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
	    if(visited[i] || DFSLoop(a, i))  return true;
	}
    }
    visited[x] = false;
    return false;
}
