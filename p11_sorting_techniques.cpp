#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

template <class Etype>
class Sorting
{
    Etype *Array;
    int Size;

  public:
    void GetData();
    void Display();
    void Swap(Etype &X, Etype &Y);
    void Bubble();
    void Insertion();
    void Selection();
    void QuickCall();
    void Quick(int, int);
};

template <class Etype>
void Sorting<Etype>::GetData()
{

    cout << endl
         << "Enter the size of the array: ";
    cin >> Size;
    if (Size <= 0)
    {
        cout << "Enter valid Size" << endl;
        GetData();
    }
    else
    {
        Array = new Etype[Size];
        cout << "Enter the values: ";
        for (int i = 0; i < Size; i++)
            cin >> Array[i];
    }
}

template <class Etype>
void Sorting<Etype>::Display()
{
    for (int i = 0; i < Size; i++)
        cout << setw(5) << Array[i];
    cout << endl;
}
template <class Etype>
void Sorting<Etype>::Bubble()
{
    for (int i = 0; i < Size - 1; i++)
    {
        for (int j = i; j < Size; j++)
        {
            if (Array[i] > Array[j])
                Swap(Array[i], Array[j]);
        }
    }
}

template <class Etype>
void Sorting<Etype>::Swap(Etype &x, Etype &y)
{
    Etype temp;
    temp = x;
    x = y;
    y = temp;
}

template <class Etype>
void Sorting<Etype>::Insertion()
{
    for (int i = 0; i < Size; i++)
    {
        Etype temp = Array[i];
        for (int j = i - 1; j >= 0 && Array[j] > temp; j--)
            Array[j + 1] = Array[j];
        Array[j + 1] = temp;
    }
}

template <class Etype>
void Sorting<Etype>::QuickCall()
{
    Quick(0, Size - 1);
}

template <class Etype>
void Sorting<Etype>::Quick(int low, int high)

{
    if (low < high)
    {
        int i_ptr = low + 1;
        int j_ptr = high;
        Etype x = Array[low];
        while (1)
        {
            while (Array[i_ptr] < x)
                i_ptr++;
            while (Array[j_ptr] > x)
                j_ptr--;
            if (i_ptr < j_ptr)
            {
                Swap(Array[i_ptr], Array[j_ptr]);
                i_ptr++;
                j_ptr++;
            }
            else
                break;
        }
        Array[low] = Array[j_ptr];
        Array[j_ptr] = x;
        Quick(low, j_ptr - 1);
        Quick(j_ptr + 1, high);
    }
}

template <class Etype>
void Sorting<Etype>::Selection()
{
    for (int i = Size - 1; i > 0; i--)
    {
        Etype max = Array[0];

        Etype index = 0;
        for (int j = 1; j <= i; j++)
        {
            if (Array[j] > max)
            {
                max = Array[j];
                index = j;
            }
        }
        Array[index] = Array[i];
        Array[i] = max;
    }
}

void main()
{
    clrscr();
    Sorting<int> S;
    int choice;
    do
    {
        clrscr();
        cout << " SORTING METHODS " << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << " Place your choice ! : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << endl
                     << "\t BUBBLE SORT";
                cout << endl
                     << "\t ------ ----";

                S.GetData();
                cout << "Initial list: ";
                S.Display();
                S.Bubble();
                cout << "Sorted list: ";
                S.Display();
                break;
            case 2:
                cout << endl
                     << "\t INSERTION SORT";
                cout << endl
                     << "\t -------- ----";
                S.GetData();
                cout << "Initial list: ";
                S.Display();
                S.Insertion();
                cout << "Sorted list: ";
                S.Display();
                break;
            case 3:
                cout << endl
                     << "\t SELECTION SORT";
                cout << endl
                     << "\t -------- ----";
                S.GetData();
                cout << "Initial list: ";
                S.Display();
                S.Selection();
                cout << "Sorted list: ";
                S.Display();
                break;
            case 4:
                cout << endl
                     << "\t QUICK SORT";
                cout << endl
                     << "\t ---- ----";
                S.GetData();
                cout << "Initial list: ";
                S.Display();
                S.QuickCall();

                cout << "Sorted list: ";
                S.Display();
                getch();
                break;
        }
        getch();
    } while (choice <= 4);
}
