#include <iostream.h>
#include <conio.h>
struct inventory
{
    int pid, qty;
    char pname[10];
    float price, amt;
} s[5][10];
void Line()
{
    int L;
    for (L = 0; L <= 70; L++)
        cout << "-";
    return;
}
void main()
{
    int i, j, k, flr, n = 0, m = 0, o;
    float tot[10] = {0.0}, cashtotal = 0.0;
    clrscr();
    cout << "enter the number of sales counter";
    cin >> m;

    for (i = 1; i <= m; i++)
    {
        cout << "\n\tcounter" << i;
        cout << "\n\Enter the no of items";
        cin >> n;
        cout << "\n ID:\t name:\t qty:\tUnitPrice:\n";
        for (j = 1; j <= n; j++)
        {
            cin >> s[i][j].pid;
            cin >> s[i][j].pname;
            cin >> s[i][j].qty;
            cin >> s[i][j].price;
            s[i][j].amt = s[i][j].qty * s[i][j].price;
            tot[i] = tot[i] + s[i][j].amt;
        }
    }
    for (i = 1; i <= m; i++)
        cashtotal += tot[i];
    Line();
    cout << "\n\n";
    cout << "counter\tProduct\tName\tQty\t\tPrice\t\tAmount\n";
    cout << " id \t id        \t\t    Rs.P \t   Rs.P.\n";
    Line();
    for (i = 1; i <= m; i++)
    {
        cout << "\n"
             << i;
        for (j = 1; j <= n; j++)
        {
            cout << "\t" << s[i][j].pid << "\t";
            cout << s[i][j].pname << "\t";
            cout << s[i][j].qty << "\t\t";
            cout << s[i][j].price << "\t\t";
            cout << s[i][j].amt << "\n";
        }
        Line();
        cout << "\n\t\t\t\t\t" << "Total Amount:" << tot[i];
        cout << "\n\n";
        Line();
    }

    cout << "\n\t\t\t" << "Total Sales Amount:" << cashtotal;
    getch();
}
