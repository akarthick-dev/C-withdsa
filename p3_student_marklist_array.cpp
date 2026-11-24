#include <iostream.h>
#include <string.h>
#include <conio.h>
void create(int);
void display(int);
void cal(int);

struct student
{
    char name[10], res[5];
    int sno, m1, m2, m3, tot;
    float avg;
} s[10];
void main()
{
    int n, ch, t;
    clrscr();
    cout << "Enter the no of students";
    cin >> n;

    do
    {
        cout << "\n\t1.CREATE\n\t2.DISPLAY\nEnter ur choice:\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                create(n);
                break;
            case 2:

                display(n);
                break;
            default:
                cout << "WRONG CHOICE";
                break;
        }
        cout << "Do u want to continue? Press(1/0):";
        cin >> t;
    } while (t != 0);
}
void create(int n)
{
    cout << "Create\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Student Name:";
        cin >> s[i].name;
        cout << "Enter Student RollNo:";
        cin >> s[i].sno;
        cout << "Enter Mark1:";
        cin >> s[i].m1;
        cout << "Enter Mark2:";
        cin >> s[i].m2;
        cout << "Enter Mark3:";
        cin >> s[i].m3;
    }
}
void display(int n)
{
    clrscr();
    cal(n);
    cout << "display";
    cout << "\nNAME\tROLLNO\tMARK1\tMARK2\tMARK3\tTOTAL\tAVERAGE\n";
    for (int i = 0; i < n; i++)
        cout << "\n"
             << s[i].name << "\t" << s[i].sno << "\t" << s[i].m1 << "\t" << s[i].m2 << "\t" << s[i].m3 << "\t" << s[i].tot << "\t" << s[i].avg << "\n";
}
void cal(int n)
{
    for (int i = 0; i < n; i++)
    {

        s[i].tot = s[i].m1 + s[i].m2 + s[i].m3;
        s[i].avg = s[i].tot / 3;
    }
    for (i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (s[i].tot <= s[j + 1].tot)
            {
                char temp7[10];
                int temp1, temp2, temp3, temp4, temp5;
                float temp6;
                temp5 = s[i].tot;
                s[i].tot = s[j + 1].tot;
                s[j + 1].tot = temp5;
                strcpy(temp7, s[i].name);
                strcpy(s[i].name, s[j + 1].name);
                strcpy(s[j + 1].name, temp7);
                temp1 = s[i].sno;
                s[i].sno = s[j + 1].sno;
                s[j + 1].sno = temp1;
                temp2 = s[i].m1;
                s[i].m1 = s[j + 1].m1;
                s[j + 1].m1 = temp2;
                temp3 = s[i].m2;
                s[i].m2 = s[j + 1].m2;
                s[j + 1].m2 = temp3;
                temp4 = s[i].m3;
                s[i].m3 = s[j + 1].m3;
                s[j + 1].m3 = temp4;
                temp6 = s[i].avg;
                s[i].avg = s[j + 1].avg;
                s[j + 1].avg = temp6;
            }
        }
    }
}
