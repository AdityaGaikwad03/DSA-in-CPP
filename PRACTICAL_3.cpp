
// Experiment No.3
// Title: Write a program to convert an infix expression into postfix and evaluate
// it.
// Objective: The objective is to convert an infix expression to postfix form and
// evaluate it using a stack for easier computation.
// Program:
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix;
    for (char c : infix)
    {
        if (isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int evaluatePostfix(const string &postfix)
{
    stack<int> s;
    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
            {
                int res = 1;
                for (int i = 0; i < b; i++)
                    res *= a;
                s.push(res);
                break;
            }
            }
        }
    }
    return s.top();
}
int main()
{
    string infix;
    cout << "Enter infix expression (single digit operands): ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << "\n";
    cout << "Result: " << evaluatePostfix(postfix) << "\n";
    return 0;
}
// Output:
// Enter infix expression (single digit operands): 9+5-3*3
// Postfix: 95+33*-
// Result: 5
