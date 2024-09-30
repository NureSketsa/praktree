#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{

    char inp;
    // cin >> time;

    stack<char>
        myStack;

    // cout << inp << "case" << endl;

    while (cin.get(inp) && inp != '\n')
    {
        // cout << inp << "case" << endl;
        if (!(myStack.empty()) && (inp == '}') && (myStack.top() == '{'))
        {
            // cout << "we pushing " << inp << endl;
            myStack.pop();
        }
        else if (!(myStack.empty()) && (inp == ']') && (myStack.top() == '['))
        {

            myStack.pop();
        }
        else if (!(myStack.empty()) && (inp == ')') && (myStack.top() == '('))
        {

            myStack.pop();
        }
        else if (!(myStack.empty()) && (inp == '>') && (myStack.top() == '<'))
        {

            myStack.pop();
        }
        else
        {
            // cout << "we pushing " << inp << endl;
            myStack.push(inp);
        }
    }

    if (myStack.empty())
    {
        cout << "Sudah ditutup";
    }
    else
    {
        cout << "Belum ditutup";
    }
    // cout << endl;

    return 0;
}
