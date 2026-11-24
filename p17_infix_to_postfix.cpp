#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
class ex1
{
    char str[50];

  public:
    void input();
    int strprt(char);
    int expprt(char);
    void convert();
};
void ex1::input()
{
    cout << "enter the Infix Expression end with $ sign:";
    cin >> str;
}
int ex1::strprt(char c)
{
    int pr;
    switch (c)
    {
        case '#':
            pr = -1;
            break;
        case '(':
        case ')':

            pr = 0;
            break;
        case '*':
        case '/':
            pr = 2;
            break;
        case '+':
        case '-':
            pr = 1;
            break;
    }
    return (pr);
}
int ex1::expprt(char c)
{
    int pr;
    switch (c)
    {
        case '(':
            pr = 4;
            break;
        case ')':
            pr = 0;
            break;
        case '*':
        case '/':
            pr = 2;
            break;
        case '+':
        case '-':
            pr = 1;
            break;
    }
    return (pr);
}

void ex1::convert()
{
    int i = 0, top = 0;
    char stk[50], item;
    while (str[i] != '$')
    {
        item = str[i];
        if (isalpha(item))
            cout << item;
        else
        {
            if (item == ')')
            {
                while (stk[top] != '(')
                {
                    cout << stk[top];
                    --top;
                }
                --top;
            }
            else
            {
                while ((strprt(stk[top])) > expprt(item))
                {
                    cout << stk[top];
                    --top;
                }
                ++top;
                stk[top] = item;
            }
        }
        i++;
    }
    while (top >= 1)

    {
        cout << stk[top];
        --top;
    }
}
void main()
{
    ex1 ob;
    clrscr();
    ob.input();
    ob.convert();
    getch();
}
