#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    bool tutup = true;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '<' || s[i] == '(' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() || (s[i] == ']' && st.top() != '[') ||
                (s[i] == '>' && st.top() != '<') ||
                (s[i] == ')' && st.top() != '(') ||
                (s[i] == '}' && st.top() != '{'))
            {
                tutup = false;
                break;
            }
            st.pop();
        }
    }

    if (tutup && st.empty())
    {
        cout << "Sudah ditutup\n";
    }
    else
    {
        cout << "Belum ditutup\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}