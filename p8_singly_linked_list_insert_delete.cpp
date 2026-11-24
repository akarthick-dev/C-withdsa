#include <iostream.h>
#include <conio.h>
#include <alloc.h>

#include <stdlib.h>
struct link
{
    int info;
    struct link *next;
};
class Slink
{
  private:
    int i, number;
    link start, *previous, *new1;

  public:
    void insertion(link *);
    void create(link *);
    void display(link *);
    void delet(link *);
};
void Slink::create(link *node)
{
    start.next = NULL;
    node = &start;
    i = 0;
    cout << "\nInput Choice n for break:";
    char ch = getche();
    while (ch != 'n')
    {
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;
        cout << "\nInput the node:" << (i + 1) << ":";
        cin >> node->info;

        node->next = NULL;
        cout << "\n Input Choice n For Break:";
        ch = getche();
        i++;
    }
}
void Slink::insertion(link *node)
{
    node = start.next;
    previous = &start;
    int node_number = 0;
    int insert_node;
    cout << "\n\tInput node number you want to Insert";
    cin >> insert_node;
    while (node)
    {
        if ((node_number + 1) == insert_node)
        {
            new1 = (struct link *)malloc(sizeof(struct link));
            new1->next = node;
            previous->next = new1;
            cout << "\nInput the node value:";
            cin >> new1->info;
            break;
        }
        else
        {
            node = node->next;
            previous = previous->next;
        }

        node_number++;
    }
}
void Slink::display(link *node)
{
    node = start.next;
    cout << "\n Node list is as follows:\n";
    while (node)
    {
        cout << "\t" << node->info;
        node = node->next;
    }
}
void Slink::delet(link *node)
{
    node = start.next;
    previous = &start;
    int node_number = 1;
    int delete_node;
    cout << "\n Input Information of a node you want to delete";
    cin >> delete_node;
    while (node)
    {
        if (node->info == delete_node)
        {
            cout << "\n\tPosition of the Information in the list" << node_number;
            previous->next = node->next;
            delete (node);
            break;
        }

        else
        {
            node = node->next;
            previous = previous->next;
        }
    }
}

void main()
{
    int choice;
    clrscr();
    Slink S;
    link *node = (link *)malloc(sizeof(link));
    do
    {
        cout << "\n1:Create\t2:Insertion\t3:Display\t4:Delete\t5:eXit\n";
        cout << "\nSelect UR Choice:";
        cin >> choice;
        switch (choice)
        {
            case 1:
                S.create(node);
                break;
            case 2:
                S.insertion(node);
                break;
            case 3:
                S.display(node);
                break;

            case 4:
                S.delet(node);
                break;
            case 5:
                exit(0);
                cout << "\n";
                break;
        }
    } while (choice != 5);
    getch();
}
