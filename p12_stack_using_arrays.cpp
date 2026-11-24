#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define n 100
int top = -1;
int flag = 0;
class stacks
{
  private:
    char stack[100];
    int str1;

  public:
    void push(char *, char);
    int pop(char *);
    void display(char *);
};
//Definition of the push function
void stacks::push(char s[], char d)
{
    if (top == (n - 1))
        flag = 0;
    else
    {
        flag = 1;
        ++top;
        s[top] = d;
    }
}
//Definition of the pop function
int stacks::pop(char s[])
{
    int pop;
    if (top == -1)

    {
        pop = 0;
        flag = 0;
    }
    else
    {
        flag = 1;
        pop = s[top];
        --top;
    }
    return (pop);
}
//Display Function
void stacks::display(char s[])
{
    if (top == -1)
    {
        cout << "Stackis empty";
    }
    else
    {
        for (int i = top; i >= 0; --i)
            cout << "\n\t" << s[i];
    }
}
void main()
{
    clrscr();
    stacks sarray;
    char stack[n];
    char data;
    int choice;
    int q = 0;
    int top = -1;
    do
    {
        cout << "\nPush=1 Pop=2 Quit=3";

        cout << "\n\t'Select Your choice from 1 2 3:'";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "\n Insert the character";
                cin >> data;
                sarray.push(stack, data);
                if (flag)
                {
                    cout << "\nAfter inserting";
                    sarray.display(stack);
                    if (top == (n - 1))
                        cout << "\nStack is full";
                }
                else
                    cout << "\nStack overflow after pushing";
                break;
            case 2:
                data = sarray.pop(stack);
                if (flag)
                {
                    cout << "\nData is popped" << data;
                    cout << "\nRest data in stack is as follows";
                    sarray.display(stack);
                }
                else
                    cout << "\nStack underflow";
                break;
            case 3:
                q = 3;
        }
    } while (!q);
}
