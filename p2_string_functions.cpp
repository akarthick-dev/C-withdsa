#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
class string
{
    char str[80];

  public:
    string()
    {
        strcpy(str, " ");
    }
    friend istream &operator>>(istream &, string &);
    friend ostream &operator<<(ostream &, string &);
    string operator+(string a);
    int operator==(string a);
    int operator!=(string a);
    int operator<(string a);
    int operator>(string a);
};
istream &operator>>(istream &in, string &s)
{
    gets(s.str);
    return in;
}
ostream &operator<<(ostream &out, string &s)
{
    puts(s.str);
    return out;
}
string string::operator+(string b)
{
    string c;
    strcpy(c.str, str);
    strcat(c.str, b.str);
    return (c);
}
int string::operator==(string b)
{
    if (strcmp(str, b.str) == 0)
        return 1;
    else

        return 0;
}
int string::operator!=(string b)
{
    if (strcmp(str, b.str) == 0)
        return 0;
    else
        return 1;
}
int string::operator<(string b)
{
    if (strcmp(str, b.str) < 0)
        return 1;
    else
        return 0;
}
int string::operator>(string b)
{
    if (strcmp(str, b.str) > 0)
        return 1;
    else
        return 0;
}
void main()
{
    string s1, s2, s3, s4;
    clrscr();
    cout << "\nEnter the First String:";
    cin >> s1;
    cout << "\nEnter the Second String:";
    cin >> s2;
    cout << "String 1 is . . .";
    cout << s1 << endl;
    cout << "String 2 is . . .";

    cout << s2 << endl;
    s3 = s1 + s2;
    cout << "Concatenated String is . . .\n";
    cout << s3 << endl;
    if (s1 == s2)
        cout << "Strings are equal . . .\n";
    if (s1 != s2)
        cout << "Strings are not equal . . .\n";
    if (s1 < s2)
        cout << "String 1 is less than String 2 . . .\n";
    if (s1 > s2)
        cout << "String 1 is greater than String 2 . . .\n";
    s4 = s1;
    cout << "Copy of String 1 is . . .\n";
    cout << s4;
    getch();
}
