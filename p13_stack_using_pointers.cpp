#include <iostream.h>

#include <malloc.h>
#include <conio.h>
struct link
{
    int info;
    link *next;
};
class stack_link
{
  private:
    link *start;

  public:
    void display(link *);
    link *push(link *);
    link *pop(link *);
    int main_menu();
};
void stack_link::display(link *rec)
{
    while (rec != NULL)
    {
        cout << "\n"
             << rec->info;
        rec = rec->next;
    }
}
link *stack_link::push(link *rec)
{
    link *new_rec;
    cout << "\n Input the new value for next location of the stack:";
    new_rec = (link *)malloc(sizeof(link));
    new_rec->next = rec;
    cin >> new_rec->info;
    new_rec->next = rec;
    rec = new_rec;
    return (rec);
}
link *stack_link::pop(link *rec)

{
    link *temp;
    if (rec == NULL)
    {
        cout << "\nStack is empty";
    }
    else
    {
        temp = rec->next;
        free(rec);
        rec = temp;
        cout << "\nAfter pop operation the stack is as follows:\n";
        display(rec);
        if (rec == NULL)
            cout << "\n Stack is empty";
    }
    return (rec);
}
int stack_link::main_menu()
{
    int choice;
    do
    {
        cout << "\n 1<-push";
        cout << "\n 2<-pop";
        cout << "\m 3<-quit";
        cout << "\n Input your choice:";
        cin >> choice;
        if (choice < 1 || choice > 3)
            cout << "\n incorrect choice-> try once again";
    } while (choice < 1 || choice > 3);
    return (choice);
}
void main()
{
    clrscr();

    stack_link stack;
    link *start;
    int choice;
    start = NULL;
    do
    {
        choice = stack.main_menu();
        switch (choice)
        {
            case 1:
                start = stack.push(start);
                cout << "\n After push operation stack is as follows:";
                stack.display(start);
                break;
            case 2:
                start = stack.pop(start);
                break;
            default:
                cout << "\n End of session";
        }
    } while (choice != 3);
    getch();
}
