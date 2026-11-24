#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
void line(int lines);

class Polynomial
{
  private:
    int power;
    int *coeffs;

  public:
    Polynomial()
    {
        power = 0;
        coeffs = new int[1];
    }
    Polynomial(int deg)
    {
        power = deg;
        coeffs = new int[deg + 1];
    }
    Polynomial(const Polynomial &X);

    void GetCoeffs(istream &in);
    int Coeff(int deg);
    void Show(ostream &out);
    int Degree()
    {
        return power;
    }
    //operators
    friend Polynomial operator+(Polynomial &X, Polynomial &B);
    friend Polynomial operator-(Polynomial &X, Polynomial &B);
};

void main()
{
    int ch;
    clrscr();
    do

    {
        cout << "\n\t========================";
        cout << "\n\t1.addition of Polynomial\n\t2.subtraction of Polynomial\n\t3.Exit";
        cout << "\n\t========================";
        count << "Enter your choicein";
        cin >> ch;
        switch (ch)
        {
            case 1:
            {
                Polynomial X(3);
                Polynomial Y(3);
                clrscr();
                cout << "Enter the value for first Poly\n";
                X.GetCoeffs(cin);
                cout << "Enter the value for Second Poly\n";
                Y.GetCoeffs(cin);
                cout << "\n\tshow the First Polynomial\n\t";
                X.Show(cout);
                line(2);
                cout << "\n\tshow the second Polynomial\n\t";
                Y.Show(cout);
                line(2);
                Polynomial Z(3);
                Z = X + Y;
                cout << "\n\tShow the Add Polynomial\t";
                Z.Show(cout);
                break;
            }
            case 2:
            {
                Polynomial X(3);
                Polynomial Y(3);
                clrscr();
                cout << "Enter the value for first Poly\n";

                X.GetCoeffs(cin);
                cout << "Enter the value for Second Poly\n";
                Y.GetCoeffs(cin);
                cout << "\n\tshow the First Polynomial\n\t";
                X.Show(cout);
                line(2);
                cout << "\n\tshow the second Polynomial\n\t";
                Y.Show(cout);
                line(2);
                Polynomial Z(3);
                Z = X - Y;
                cout << "\n\tview the Subtraction of two Polynomial\t";
                Z.Show(cout);
                break;
            }
            case 3:
            default:
                exit(0);
        }
    } while (ch != 0);
}

Polynomial operator+(Polynomial &X, Polynomial &Y)
{
    Polynomial Z;
    if (X.power == Y.power)
    {
        Z = X;
        for (int i = Y.power; i >= 0; i--)
        {
            Z.coeffs[i] = X.coeffs[i] + Y.coeffs[i];
        }
        return Z;
    }

    else if (X.power < Y.power)
    {
        Z = Y;
        for (int i = X.power; i >= 0; i--)
        {
            Z.coeffs[i] = Y.coeffs[i];
        }
        return Z;
    }
    else if (X.power > Y.power)
    {
        Z = X;
        for (int i = X.power; i >= 0; i--)
        {
            Z.coeffs[i] = X.coeffs[i];
        }
        return Z;
    }
    return 0;
}
Polynomial operator-(Polynomial &X, Polynomial &Y)
{
    Polynomial Z;
    if (X.power == Y.power)
    {
        Z = X;
        for (int i = Y.power; i >= 0; i--)
        {
            Z.coeffs[i] = X.coeffs[i] - Y.coeffs[i];
        }
        return Z;
    }
    else if (X.power < Y.power)
    {
        Z = Y;

        for (int i = X.power; i >= 0; i--)
        {
            Z.coeffs[i] = Y.coeffs[i];
        }
        return Z;
    }
    else if (X.power > Y.power)
    {
        Z = X;
        for (int i = X.power; i >= 0; i--)
        {
            Z.coeffs[i] = X.coeffs[i];
        }
        return Z;
    }
    return 0;
}
int Polynomial::Coeff(int deg)
{

    return coeffs[deg];
}

void line(int lines)
{
    for (int i = 0; i < lines; i++)
        cout << endl;
}

void Polynomial::GetCoeffs(istream &in)
{
    for (int i = power; i >= 0; i--)
    {
        in >> coeffs[i];
    }

    in.ignore();
}

void Polynomial::Show(ostream &out)
{
    for (int i = power; i >= 0; i--)
    {
        if (coeffs[i] >= 0)
        {
            if (i != power)
                out << " + ";
            out << coeffs[i];
        }
        else
        {
            if (coeffs[i] < 0)
                out << " - ";
            out << 0 - coeffs[i];
        }
        if (i > 1)
            out << "x^" << i;
        else if (i == 1)
            out << "x";
    }
}

Polynomial::Polynomial(const Polynomial &X)
{
    coeffs = new int[X.power + 1];
    power = X.power;
    for (int i = X.power; i >= 0; i--)
    {
        coeffs[i] = X.coeffs[i];
    }
}
