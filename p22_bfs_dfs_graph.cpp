#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

#define n 50
int adjmat[n][n];
class BFSDFS
{
  private:
    int Point[n];
    int pathvisit[n];

  public:
    BFSDFS()
    {
    }
    ~BFSDFS()
    {
    }
    void create(int);
    void depthfirst(int);
    void breathfirst(int);
    void DFS(int, int);
};
void BFSDFS::DFS(int ad, int edge)
{
    int k;
    for (k = ad; k < edge; k++)
        for (int j = 0; j < edge; j++)
            if (adjmat[k][j] == 1)
            {
                if (pathvisit[j] == 0)
                {
                    pathvisit[j] = 1;
                    cout << Point[j] << "==>>";
                    DFS(j, edge);
                }
            }
}
void BFSDFS::create(int edge)
{
    int i, j;
    for (i = 0; i < edge; i++)
    {

        cin >> Point[i];
        pathvisit[i] = 0;
    }
    for (i = 0; i < edge; i++)
        for (j = 0; j < edge; j++)
            adjmat[i][j] = 0;
    cout << "enter the adjadency list for each edges of graph";
    cout << "\n";
    int m, k, p;
    for (i = 0; i < edge; i++)
    {
        cout << "enter the no of adjacency Point";
        cout << Point[i] << ":";
        cin >> p;
        cout << "enter the adjacency Point";
        for (j = 1; j <= p; j++)
        {
            cin >> m;
            for (k = 0; k < edge; k++)
            {
                if (Point[k] == m)
                    adjmat[i][k] = 1;
            }
        }
    }

    clrscr();
    cout << "\n graph created with no. of Points=" << edge << endl
         << endl;
    cout << "\n\n the adjacency matrix is :\n\n";
    for (i = 0; i < edge; i++)
    {
        for (j = 0; j < edge; j++)
            cout << adjmat[i][j] << "";
        cout << endl;
    }
}
void BFSDFS::depthfirst(int edge)
{

    int i = 0;
    for (i = 0; i < edge; i++)
        pathvisit[i] = 0;
    adjmat[0][0] = 1;
    pathvisit[0] = 1;
    cout << "\t\t Depth First Traversal\n\n";
    cout << Point[0] << "==>>";
    DFS(0, edge);
}
void BFSDFS::breathfirst(int edge)
{
    int i, j;
    for (i = 0; i < edge; i++)
        pathvisit[i] = 0;
    cout << "\t\t Breath First Traversal\n\n";
    cout << Point[0] << "==>>";
    pathvisit[0] = 1;
    for (i = 0; i < edge; i++)
    {
        for (j = 0; j < edge; j++)

        {
            if (adjmat[i][j] == 1)
            {
                if (pathvisit[j] == 0)
                {
                    cout << Point[j] << "==>>";
                    pathvisit[j] = 1;
                }
            }
        }
    }
    cout << "x\n\n";
}
void main()
{
    BFSDFS BD;
    int ch, edge;
    do
    {
        clrscr();
        cout << "\t\t graph creation and traversal\n\n";
        cout << "\t\t 1.Create Graph\n\n";
        cout << "\t\t 2.Breadth First Traversal\n\n";
        cout << "\t\t 3.Depth First Traversal\n\n";
        cout << "\t\t 4.Exit\n\n";
        cout << "\t\t Enter Ur Choice\n\n";
        cin >> ch;
        switch (ch)
        {
            case 1:
                clrscr();
                cout << "\n\t\t Graph Creation\n\n";
                cout << "Enter the no. of Pointes to be created";

                cin >> edge;
                cout << "enter the Point value";
                BD.create(edge);
                cout << "press any key to continue";
                getch();
                break;
            case 2:
                clrscr();
                BD.breathfirst(edge);
                cout << "press any key to continue";
                getch();
                break;
            case 3:
                clrscr();
                BD.depthfirst(edge);
                cout << "X\n\n";
                cout << "press any key to continue";
                getch();
                break;
            default:
                break;
        }

    } while (ch != 4);
}
