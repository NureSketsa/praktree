#include <bits/stdc++.h>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    map<string, stack<string>> TOPIC;

    int loop;
    cin >> loop;
    string input_opt, input_opt_two, input_opt_three;

    for (int i = 0; i < loop; i++)
    {
        string input_str;
        cin >> input_opt;
        cin >> input_opt_two;
        cin >> input_opt_three;

        if (input_opt == "CREATE")
        {
            // cout << "CREATE";
            if (TOPIC.find(input_opt_three) == TOPIC.end())
            {
                TOPIC[input_opt_three] = stack<string>();
            }
        }
        else if (input_opt == "WRITE")
        {
            // cout << "WRITE";
            TOPIC[input_opt_two].push(input_opt_three);
        }
        else if (input_opt == "READ")
        {
            // cout << "READ";
            if (TOPIC.find(input_opt_three) != TOPIC.end() && !TOPIC[input_opt_three].empty())
            {
                string message = TOPIC[input_opt_three].top();
                TOPIC[input_opt_three].pop();
                cout << message << endl;
            }
            else
            {
                cout << "Topic is empty" << endl;
            }
        }
    }

    return 0;
}
