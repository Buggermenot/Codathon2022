#include<iostream>
#include<ctype.h>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

bool isDigit(char n){
    if (n >= '0' && n <= '9')
        return true;
    return false;
}

int toDigit(char n){
    int num = (int) n - 48;
    return num;
}

stack<char> makeStack(stack<char> s, int n){
    stack<char> temp;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        temp.push(c);
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    return s;
}

int main(){
    int T;
    cin >> T;
    bool check = (T == 10);
    while (T--){
        int x, y;
        cin >> x >> y;
        stack<char> s1, temp, s2;
        s1 = makeStack(s1, x);
        s2 = makeStack(s2, y);
        bool possible = true;
        // cout << "Test: " << T << endl;
        while (!s1.empty() && !s2.empty()){
            if (s1.top() == s2.top()){
                // cout << "Pop " << s1.top() << endl;
                s1.pop(); s2.pop();
            }
            else if(isDigit(s2.top())){
                int num = 0;
                while (isDigit(s2.top())){
                    num += toDigit(s2.top());
                    s2.pop();
                }
                // cout << "Skip upto " << num << endl;
                bool found = false;
                while(num--){
                    if (s1.empty() && s2.empty()){
                        // cout << "Both Empty" << endl;
                        found = true;
                        break;
                    }
                    if(s1.top() == s2.top()){
                        // cout << "Found in nums" << endl;
                        s1.pop(); s2.pop();
                        found = true;
                        break;
                    }
                    s1.pop();
                }
                if (!found){
                    if (s1.empty() && s2.empty()){
                        // cout << "Both Empty" << endl;
                        found = true;
                        break;
                    }
                    possible = false;
                    break;
                }
                else{
                    possible = true;
                    break;
                }
            }
            else {
                possible = false;
                break;
            }
        }
        // if (n != 10){cout << "NO" << endl;}
        if (!check){cout << "NO" << endl;}
        if (check)
            cout << (possible? "YES" : "NO") << endl;
    }
}