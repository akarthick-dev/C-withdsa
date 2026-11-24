#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#define n 20
class quearray
{
  public:
    int rear, front;
    char ch;
    char q[n];

  public:
    quearray()
    {
        rear = front = -1;
    }
    void insert();
    void delqueue();
    void display();
};
void quearray::insert()
{
    if ((front == 0) && (rear == n - 1))
    {
        cout << "\n overflow";
        rear = 1;
        return;
    }
    else if (front < 0)
    {
        front = 0;
        rear = 0;
        cout << "\n Insert the element";
        cin >> ch;
        q[rear] = ch;
    }
    else if (rear == n - 1)
    {
        rear = 0;
        cout << "\nInsert the element:";
        cin >> ch;
        q[rear] = ch;
    }
    else
    {
        rear++;
        cout << "\nInsert the element:";
        cin >> ch;
        q[rear] = ch;
    }
}
void quearray::delqueue()
{
    if (front < 0)
    {
        cout << "\n underflow";
        return;
    }
    ch = q[front];
    q[front] = NULL;
    cout << "Elementis Deleted:" << ch;
    if (front == rear)

    {
        front = -1;
        rear = -1;
    }
    else if (front == n - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void quearray::display()
{
    if (front < 0)
        return;
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << q[i];
        }
    }
    else
    {
        for (int i = front; i <= n; i++)
        {
            cout << q[i];
        }

        for (i = 0; i <= rear; i++)
        {
            cout << q[i];
        }
    }
}
void main()
{
    quearray Q;
    int k = 0;
    int s;
    clrscr();
    do
    {
        cout << "\n \t 1. INSERT\t 2. DELETE\t 3. QUIT\n";
        cout << "\t Select the choice [1, 2, 3]:";
        cin >> s;
        switch (s)
        {
            case 1:
                Q.insert();
                cout << "\n queue after inserting:";
                Q.display();
                break;
            case 2:
                Q.delqueue();
                cout << "\n queue after deleteion :";
                Q.display();
                break;
            case 3:
                k = 4;
        }
    } while (!k);
    getch();
}
