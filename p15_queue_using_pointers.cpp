#include <iostream.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    node *link;
};
struct queue
{
    node *first;

    node *last;
    node *link_next;
};
struct Q
{
    queue q;
    node *qlink;

  public:
    void Initialise()
    {
        q.first = NULL;
        q.last = NULL;
    }
    void insertqueue();
    void deletequeue();
    void display();
};
void Q::insertqueue()
{
    qlink = new (node);
    cout << "Enter the node";
    cin >> qlink->data;
    cout << "Insert the node :" << qlink->data;
    qlink->link = NULL;
    if ((q.last) == NULL)
        q.first = qlink;
    else
        q.last->link = qlink;
    q.last = qlink;
}
void Q::deletequeue()
{
    if (q.first == NULL)
    {
        cout << "\tQueue is Empty";
        q.last = NULL;
    }
    else
    {
        qlink = q.first;
        cout << "\tDelete the node:" << q.first->data;
        q.first = q.first->link;
        free(qlink);
    }
}
void Q::display()
{
    if (q.first == NULL)
        cout << "Queue is Empty";
    else
    {
        cout << "\nfirst";
        for (qlink = q.first; qlink != NULL; qlink = qlink->link)
            cout << "==>" << qlink->data;
        cout << "<==last\n";
    }
}
void main()
{
    char choice;
    Q mainqueue;
    clrscr();
    mainqueue.Initialise();
    cout << "\t\tQUEUE USING POINTER";
    cout << "\n\tInsert\tDelete\tView\tExit";
    do
    {
        cout << "\nEnter your choice:\t";
        cin >> choice;
        switch (choice)
        {
            case 'I':
                mainqueue.insertqueue();
                break;
            case 'D':
                mainqueue.deletequeue();

                break;
            case 'V':
                mainqueue.display();
                break;
            case 'E':
                break;
            default:
                cout << "Invalid choice";
        }
    } while (choice != 'E');
    getch();
}
