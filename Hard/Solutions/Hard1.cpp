#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int m;
    cin >> m;
    int matrix[m][m];
    // Input
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    // Find I's sum
    int max_i, max_j, max_sum =0;
    for (int i = 0; i < m-2; i++){
        for (int j = 0; j < m-2; j++){
            int sum = 0;
            for (int Mi = i; Mi < i+3; Mi++){
                for (int Mj = j; Mj < j+3; Mj++){
                    sum += matrix[Mi][Mj];
                }
            }
            sum -= (matrix[i+1][j] + matrix[i+1][j+2]);
            if (sum > max_sum){
                max_sum = sum;
                max_i = i;
                max_j = j;
            }
        }
    }

    // Display
    cout << max_sum << endl;
    cout << matrix[max_i][max_j] << " ";
    cout << matrix[max_i][max_j+1] << " ";
    cout << matrix[max_i][max_j+2] << endl;
    cout << "  " << matrix[max_i+1][max_j+1] << "  " << endl;
    cout << matrix[max_i+2][max_j] << " ";
    cout << matrix[max_i+2][max_j+1] << " ";
    cout << matrix[max_i+2][max_j+2] << endl;
    cout << max_i << " " << max_j << endl;

}
