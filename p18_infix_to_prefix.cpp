#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
const int M = 50;
class inprefix
{
  private:
    char target[M], stack[M];
    char *s, *t;
    int top, k;

  public:
    inprefix();
    void expr(char *str);
    void push(char c);

    char pop();
    void convert();
    int priority(char c);
    void view();
};
inprefix::inprefix()
{
    top = -1;
    strcpy(target, "");
    strcpy(stack, "");
    k = 0;
}
void inprefix::expr(char *str)
{
    s = str;
    strrev(s);
    k = strlen(s);
    *(target + k) = '\0';
    t = target + (k - 1);
}
void inprefix::push(char c)
{
    if (top == M - 1)
        cout << "\nStack is full\n";
    else
    {
        top++;
        stack[top] = c;
    }
}
char inprefix::pop()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";

        return -1;
    }
    else
    {
        char item = stack[top];
        top--;
        return item;
    }
}
void inprefix::convert()
{
    char opr;

    while (*s)
    {
        if (*s == ' ' || *s == '\t')
        {
            s++;
            continue;
        }

        if (isdigit(*s) || isalpha(*s))
        {
            while (isdigit(*s) || isalpha(*s))
            {
                *t = *s;
                s++;
                t--;
            }
        }

        if (*s == ')')
        {
            push(*s);
            s++;
        }

        if (*s == '*' || *s == '+' || *s == '/' ||
            *s == '%' || *s == '-' || *s == '$')
        {
            if (top != -1)
            {
                opr = pop();

                while (priority(opr) > priority(*s))
                {
                    *t = opr;
                    t--;
                    opr = pop();
                }
                push(opr);
                push(*s);
            }
            else
                push(*s);
            s++;
        }

        if (*s == '(')
        {
            opr = pop();
            while ((opr) != ')')
            {
                *t = opr;
                t--;
                opr = pop();
            }
            s++;
        }
    }

    while (top != -1)
    {
        opr = pop();
        *t = opr;
        t--;
    }
    t++;
}
int inprefix::priority(char c)
{
    if (c == '$')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    else
    {
        if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }
}
void inprefix::view()
{
    while (*t)
    {
        cout << " " << *t;
        t++;
    }
}

void main()
{
    char expr[M];
    inprefix pfix;
    clrscr();
    cout << "\nEnter an expression in infix form: ";
    cin.getline(expr, M);

    pfix.expr(expr);
    pfix.convert();

    cout << "The Prefix expression is: ";
    pfix.view();
}
