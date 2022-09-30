#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    int l = s1.length();
    char arr1[l+1], arr2[l+1];
    strcpy(arr1, s1.c_str());
    strcpy(arr2, s2.c_str());

    // for (int i = 0; i < l; i++){
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;

    int ii;

    for (int i = 0; i < l; i++){
        if (arr2[i] == arr1[0]){
            ii = i;
            break;
        }
    }

    string end2="", start2="", start1="", end1="";

    for (int i = 0; i < ii; i++){    // 4
        end1 += arr1[l-ii+i];
        start2 += arr2[i];
    }
    // for (int i = 0; i < l; i++){
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < l-ii; i++){    // 2
        start1 += arr1[i];
        end2 += arr2[ii+i];
    }

    // cout << start1 << " " << end1 << endl;
    // cout << start2 << " " << end2 << endl;

    if (!start1.compare(end2) && !end1.compare(start2))
        cout << "True";
    else
        cout << "False";
}