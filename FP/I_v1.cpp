#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string input;
    cin >> input;

    stack<char> myStack;

    for (char inp : input)
    {
        if (!myStack.empty() && ((inp == '}') && (myStack.top() == '{') ||
                                 (inp == ']') && (myStack.top() == '[') ||
                                 (inp == ')') && (myStack.top() == '(') ||
                                 (inp == '>') && (myStack.top() == '<')))
        {
            myStack.pop();
        }
        else
        {
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

    return 0;
}
