#include <iostream.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int info;
    struct node *next;
};

class CircularLinkedList
{
    struct node *parent, *endnode;

  public:
    void create();
    void insert();
    void delet();
    void view();
};
void CircularLinkedList::create()
{
    struct node *pos, *n;
    int value, s;
    parent = pos = NULL;
    s = sizeof(struct node);
    cout << "\n enter -99 to stop";
    cin >> value;
    while (value != -99)
    {
        n = (struct node *)malloc(s);
        n->info = value;
        n->next = NULL;
        if (parent == NULL)
            parent = n;

        else
            pos->next = n;
        pos = n;
        cout << "\n enter -99 to stop";
        cin >> value;
    }
    endnode = n;
    endnode->next = parent;
}

void CircularLinkedList::view()
{
    struct node *start = parent;
    cout << "\n parent->";
    do
    {
        cout << start->info << "->";
        start = start->next;
    } while (start != parent);
    cout << "parent";
}
void CircularLinkedList::insert()
{
    struct node *temp, *start = parent;
    int value, pos, i = 2;
    cout << "\n enter the value & position to insert :";
    cin >> value >> pos;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = value;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = parent;
        endnode->next = temp;

        parent = temp;
    }
    else
    {
        while (start->next != parent && i < pos)
        {
            start = start->next;
            i++;
        }
        temp->next = start->next;
        start->next = temp;
        if (start == endnode)
            endnode = temp;
    }
}
void CircularLinkedList::delet()
{
    struct node *start = parent;
    int pos, i = 2;
    cout << "\n enter the position to delete :";
    cin >> pos;
    if (pos == 1)
    {
        parent = parent->next;
        endnode->next = parent;
    }
    else
    {
        while (start->next != NULL && i < pos)
        {
            start = start->next;
            i++;
        }
        if (start->next == endnode)
        {

            start->next = parent;
            endnode = start;
        }
        else
        {
            start->next = start->next->next;
        }
    }
}

void main()
{
    clrscr();
    cout << "\n\t\t OUT PUT\n";
    CircularLinkedList CLL;
    CLL.create();
    CLL.view();
    CLL.insert();
    CLL.view();
    CLL.delet();
    CLL.view();
    getch();
}
