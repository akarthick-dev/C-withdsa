#include <iostream.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int info;
    struct node *next, *back;
};

class list
{
    struct node *root, *end;

  public:
    void createinfo();
    void insert();
    void delet();
    void display();
};
void list::createinfo()
{
    struct node *p, *n;
    int t, s;

    root = p = NULL;

    s = sizeof(struct node);
    cout << "\n enter -999 to stop";
    cin >> t;
    while (t != -999)
    {
        n = (struct node *)malloc(s);
        n->info = t;
        n->next = NULL;
        n->back = NULL;
        if (root == NULL)
            root = n;
        else
        {
            p->next = n;
            n->back = p;
        }

        p = n;
        cout << "\n enter -999 to stop";
        cin >> t;
    }
    end = n;
}

void list::display()
{
    struct node *x = root;
    cout << "\n start->";
    while (x != NULL)
    {
        cout << x->info << "->";
        x = x->next;
    }
    cout << "end";
    x = end;
    cout << "\n back";
    while (x != NULL)
    {
        cout << x->info << "->";
        x = x->back;
    }
    cout << "end";
}

void list::insert()
{
    struct node *temp, *ex = root;
    int value, pos, i = 2;
    cout << "\n enter the value & position to insert :";
    cin >> value >> pos;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->next = NULL;
    temp->back = NULL;
    if (pos == 1)
    {
        temp->next = root;
        root->back = temp;
        root = temp;
    }
    else
    {
        while (ex->next != NULL && i < pos)
        {
            ex = ex->next;

            i++;
        }
        temp->next = ex->next;
        temp->back = ex;
        if (ex->next != NULL)
            ex->next->back = temp;
        ex->next = temp;
        if (temp->next == NULL)
            end = temp;
    }
}

void list::delet()
{
    struct node *ex = root;
    int p, i = 2;
    cout << "\n enter the position to delete :";
    cin >> p;
    if (p == 1)
    {
        root = root->next;
        root->back = NULL;
    }
    else
    {
        while (ex->next != NULL && i < p)
        {
            ex = ex->next;
            i++;
        }
        if (ex->next->next != NULL)
        {
            ex->next = ex->next->next;
            ex->next->back = ex;
        }
        else
        {
            ex->next = NULL;
            end = ex;
        }
    }
}

void main()
{
    clrscr();
    cout << "\n\t\t OUT PUT\n";
    list one;
    one.createinfo();
    one.display();
    one.insert();
    one.display();
    one.delet();
    one.display();
    getch();
}
