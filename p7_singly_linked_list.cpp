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
    new1 = (struct link *)malloc(sizeof(struct link));
    new1->next = node;
    previous->next = new1;
    cout << "\nInput the first node value:";
    cin >> new1->info;
}
void Slink::display(link *node)
{
    node = start.next;
    cout << "\nAfter inserting a node list is as follows:\n";
    cout << "Address\t\tValue";
    while (node)
    {
        cout << "\n"
             << node;
        cout << "" << node->info;
        cout << "\t" << node->info;
        node = node->next;
    }
}
void Slink::delet(link *node)
{
    node = start.next;

    previous = &start;
    if (node == NULL)
        cout << "\nUnder Flow\n";
    else
    {
        previous->next = node->next;
        cout << node->info << "is deleted";
        free(node);
    }
}

void main()
{
    char choice;
    clrscr();
    Slink S;
    link *node = (link *)malloc(sizeof(link));
    do
    {
        cout << "\nCreate\tInsertion\tDisplay\tdElete\teXit\n";
        cout << "\nSelect UR Choice:";
        choice = getch();
        cout << choice;
        switch (choice)
        {
            case 'C':
                S.create(node);
                break;
            case 'I':
                S.insertion(node);
                break;
            case 'D':
                S.display(node);
                break;
            case 'E':

                S.delet(node);
                break;
            case 'X':
                exit(0);
                cout << "\n";
                break;
        }
    } while (choice != 'X');
    getch();
}
