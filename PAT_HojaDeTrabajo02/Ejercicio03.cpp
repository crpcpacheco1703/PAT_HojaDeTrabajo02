#include "Ejercicio03.h"
#include <stack>

int Ejercicio03::calculate(string s)
{
    std::stack<int> nums;
    std::stack<char> ops;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') continue;

        if (isdigit(s[i])) 
        {
            int num = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            i--;

            nums.push(num);
        }
        else
        {
            if (ops.empty() || s[i] == '*' || s[i] == '/')
            {
                ops.push(s[i]);
            }
            else
            {
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();

                int res = 0;
                if (op == '+') res = num1 + num2;
                else if (op == '-') res = num1 - num2;
                else if (op == '*') res = num1 * num2;
                else if (op == '/') res = num1 / num2;

                nums.push(res);
                ops.push(s[i]);
            }
        }
    }

    while (!ops.empty())
    {
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();

        int res = 0;
        if (op == '+') res = num1 + num2;
        else if (op == '-') res = num1 - num2;
        else if (op == '*') res = num1 * num2;
        else if (op == '/') res = num1 / num2;

        nums.push(res);
    }

    return nums.top();
}
