#include <iostream.h>
#include <conio.h>
#include <process.h>
int j = 0;

class circularqueue
{
    int a[5], i, f, r, n;

  public:
    void insert();
    void delet();
    void display();
    circularqueue()
    {
        f = 0;
        r = -1;
        n = 5;
        a[i] = 0;
    }
};

void main()
{
    clrscr();
    int choice;
    circularqueue obj;
    do
    {
        cout << "\nenter the choice:";
        cout << "1.insert" << endl;
        cout << "2.delete" << endl;
        cout << "3.Display.\n";
        cout << "4.Exit.\n";
        cin >> choice;

        switch (choice)
        {

            case 1:
                obj.insert();
                break;
            case 2:
                obj.delet();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                exit(0);
                break;

            default:
                cout << "Enter the correct choice.\n";
        }
    } while (choice < 5);
}

void circularqueue::insert()
{
    int in;
    if (j < 5)
    {
        if (r == n - 1 && f == 0)
        {
            cout << "Queue is full.\n\n";
        }
        else
        {
            cout << "Enter the no=";
            cin >> in;
            r = (r + 1) % n;
            a[r] = in;
            j++;
        }
    }
    else
    {
        cout << "\n QUEUE IF FULL ";
    }
}

void circularqueue::delet()
{
    int temp;
    if (r <= -1)
    {
        cout << "Queue is Empty.\n";
    }
    else
    {
        temp = a[f];
        cout << "The Deleted Value Is=" << temp;
        a[f] = 0;
        if (f != r)
        {
            f = (f + 1) % n;
            j--;
        }

        else
        {
            f = 0;
            r = -1;
        }
    }
}

void circularqueue::display()
{
    for (i = 0; i < n; i++)
        cout << a[i] << "\t";
}
