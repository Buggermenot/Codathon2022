#include<iostream>
#include<cstdio>
//#define DEFAULT 100                // Should really not require to be more than 22. Abs max 35 for 6x6 grid
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char mines [n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mines[i][j];
        }
    }

    int DEFAULT = n*m;

    // Initialise dist matrix
    int dist[n+2][m+2];
    for (int i = 0; i < n+2; i++){
        for (int j = 0; j < m+2; j++){
            if (i==0 || i == n+1 || j == 0 || j == m+1){
                dist[i][j] = -1;
            }
            else{
                switch (mines[i-1][j-1]){
                    case 'O':
                        dist[i][j] = DEFAULT;
                        break;
                    case 'M':
                        dist[i][j] = 0;
                        break;
                    case 'X':
                        dist[i][j] = DEFAULT;            // HOW CAN YOU IGNORE THE X!!!!!!
                        break;
                }
            }
        }
    }

    /*
    Path Algo

        Sets each cell to +1 of anytile smaller than itself except -1.
        Breaks loop when no cell changes value

    */
    bool change = true;
    while (change){
        change = false;
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                int cell = dist[i][j];
                if (cell > 0){
                    if (cell > dist[i+1][j] + 1 && dist[i+1][j] != -1){
                        cell = dist[i+1][j] + 1; change = true;
                    }
                    if (cell > dist[i][j+1] + 1 && dist[i][j+1] != -1){
                        cell = dist[i][j+1] + 1; change = true;
                    }
                    if (cell > dist[i-1][j] + 1 && dist[i-1][j] != -1){
                        cell = dist[i-1][j] + 1; change = true;
                    }
                    if (cell > dist[i][j-1] + 1 && dist[i][j-1] != -1){
                        cell = dist[i][j-1] + 1; change = true;
                    }
                    dist[i][j] = cell;
                }
            }
        }
    }
    // Unreachable tiles
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++)
            dist[i][j] = (dist[i][j] == DEFAULT) ? -1 : dist[i][j];
    }

    for (int i = 1; i < n+1; i++){                    // BRING THE X BACK!!!!!
        for (int j = 1; j < m+1; j++){
            if (mines[i-1][j-1] == 'X'){
                dist[i][j] = -1;
            }
        }
    }

    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m; j++){
            cout << dist[i][j] << " ";
        }
        cout << dist[i][m] << endl;
    }
}