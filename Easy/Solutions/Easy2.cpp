#include<iostream>
#include<cstdio>
#include<stack>
#include<string.h>
using namespace std;

int main(){
    int cmds;
    cin >> cmds;
    stack<int> plate_stack;
    int k, v;
    string operation, push = "push", pop = "pop", add = "add";

    while (cmds){
        cmds--;
        cin >> operation;
        if(!operation.compare(push)){        // Push
            cin >> v;
            plate_stack.push(v);
        }
        else if(!operation.compare(pop)){    // Pop
            plate_stack.pop();
        }
        else if(!operation.compare(add)){    // Add
            cin >> k >> v;
            stack<int> temp;
            // Remove all
            while(!plate_stack.empty()){
                temp.push(plate_stack.top());
                plate_stack.pop();
            }
            // Restack
            for (int i = 0; i < k; i++){
                plate_stack.push(temp.top()+v);
                temp.pop();
            }
            //Fill back rest
            while(!temp.empty()){
                plate_stack.push(temp.top());
                temp.pop();
            }
        }
        if (!plate_stack.empty())
            cout << plate_stack.top() << endl;
        else
            cout << "Empty!" << endl;
    }
}