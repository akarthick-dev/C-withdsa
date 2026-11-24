#include <iostream.h>
#include <conio.h>
#include <alloc.h>
#define NEXT(poly) poly->nxtpoly
typedef struct POLY
{
    int coef, power;
    struct POLY *nxtpoly;
} POLY;
POLY *insertpoly(int coef, int power, POLY *first)
{
    POLY *NEW, *current, *prod;

    NEW = (POLY *)malloc(sizeof(POLY));
    if (!NEW)
    {
        cout << "Error:out of memory!";
        return (first);
    }
    NEW->coef = coef;
    NEW->power = power;
    NEW->nxtpoly = NULL;
    if (!first)
        return (NEW);
    prod = first;
    for (current = first; current; current = NEXT(current))
        prod = (POLY *)current;
    NEXT(prod) = NEW;
    return (first);
}
POLY *createpoly()
{
    int coef, power;
    POLY *poly = NULL;
    cout << "\n Enter the coeff. power<coef.power>0->end:";
    while (1)
    {
        cin >> coef >> power;
        cout << coef << "x^" << power;
        if (coef == 0)
            break;
        else
            poly = insertpoly(coef, power, poly);
        if (power == 0)
            break;
    }
    return (poly);
}
POLY *freepoly(POLY *poly)
{
    POLY *current;
    for (current = poly; current; current = NEXT(current))
        free(current);
    return (NULL);
}
void displaypoly(POLY *poly)
{
    POLY *current;
    for (current = poly; current; current = NEXT(current))
        if (current->coef != 0)
            cout << current->coef << "X^" << current->power << "+";
    cout << "=0";
    cout << "\n";
}
POLY *polyadd(POLY *poly1, POLY *poly2)
{
    POLY *p1, *p2, *poly = NULL;
    p1 = poly1;
    p2 = poly2;
    while (p1 && p2)
    {
        if (p1->power > p2->power)
        {
            poly = insertpoly(p1->coef, p1->power, poly);
            p1 = NEXT(p1);
        }
        else if (p2->power > p1->power)
        {
            poly = insertpoly(p2->coef, p2->power, poly);
            p2 = NEXT(p2);
        }

        else
        {
            poly = insertpoly(p1->coef + p2->coef, p1->power, poly);
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }
    }
    while (p1)
    {
        poly = insertpoly(p1->coef, p1->power, poly);
        p1 = NEXT(p1);
    }
    while (p2)
    {
        poly = insertpoly(p2->coef, p2->power, poly);
        p2 = NEXT(p2);
    }
    return (poly);
}
POLY *polymul(POLY *poly1, POLY *poly2)
{
    POLY *p1, *pnew, *pmul, *prod;
    prod = NULL;
    for (; poly2; poly2 = NEXT(poly2))
    {
        for (p1 = poly1, pmul = NULL; p1; p1 = NEXT(p1))
            pmul = insertpoly(p1->coef * poly2->coef, p1->power + poly2->power, pmul);
        pnew = polyadd(prod, pmul);
        prod = freepoly(prod);
        pmul = freepoly(pmul);
        prod = pnew;
    }
    return (prod);
}

int main()
{
    int choice;
    clrscr();
    POLY *poly1, *poly2, *poly;
    poly = poly1 = poly2 = NULL;
    cout << "Polynomial manipulation program:\n\n";
    cout << "Enter the first polynomial:\n";
    poly1 = createpoly();
    cout << "\npoly1\t";
    displaypoly(poly1);
    cout << "Enter the second polynomial:\n";
    poly2 = createpoly();
    cout << "\npoly2\t";
    displaypoly(poly2);
    while (1)
    {
        cout << "\nSelect polynomial operations\n1.ADD\n2.MUL\n3.QUIT";
        cout << "\n Enter the choice:\t";
        cin >> choice;
        cout << "Entered the choice:\t" << choice;
        switch (choice)
        {
            case 1:
                poly = polyadd(poly1, poly2);
                break;
            case 2:
                poly = polymul(poly1, poly2);
                break;
            case 3:
            default:
                return (0);
        }
        cout << "\nresult:";

        displaypoly(poly);
        poly = freepoly(poly);
    }
}
