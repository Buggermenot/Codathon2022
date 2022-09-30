#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>
using namespace std;

void sortMarks(int* arr, int n){
    sort(arr, arr+n);
    int S_marks[n];
    int gap = 0.2*n;

    for (int i = 0; i < gap; i++){
        S_marks[i] = arr[i];
        S_marks[i+gap] = arr[n-i-1];
    }
    for (int i = 2*gap; i < n; i++){
        S_marks[i] = arr[i-gap];
    }
    for (int i = 0; i < n; i++){
        arr[i] = S_marks[i];
    }
}

void display(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        cout << arr[i] << " ";
    }
    cout << arr[n-1] << endl;;
}

void getArr(int* arr, int n){
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
}

int main(){
    int N;
    cin >> N;
    int marks[N];

    getArr(marks, N);
    sortMarks(marks, N);
    display(marks, N);
}