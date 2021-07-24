#include <iostream>
#define inf 9999
#define max 10
using namespace std;

struct node
{
    int dv;
    int pv;
    int ver_no;
    bool known;
};

class prims
{
    int cost[max][max], span[max][max];
    struct node t[max];
    int min, source, numv, nume, cnt, k, l, m, value, rent;
    char vertex[15][max];
    void display(int[max][max]);
    void display_table();

public:
    void accept();
    void prims_algo();
    void spanning();
};

void prims::accept()
{
    char ans;
    int i, j;
    cout << "\nEnter the number of countries(vertices)\n";
    cin >> numv;
    for (i = 0; i < numv; i++)
    {
        cout << "Enter the country at vertex" << i << " : ";
        cin >> vertex[i];
    }

    for (i = 0; i <= numv; i++)
        for (j = 0; j <= numv; j++)
            cost[i][j] = inf;

    cout << "\nEnter the rent to connect different pairs of countries\n";
    for (i = 0; i < numv; i++)
    {
        for (j = i + 1; j < numv; j++)
        {
            cout << "Is there a phone line between " << vertex[i] << " and " << vertex[j] << " ? (y / n) : ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y')
            {
                cout << "Enter the rent(weight) : ";
                cin >> rent;
                cost[i][j] = rent;
                cost[j][i] = rent;
            }
        }
    }
    cout << "\nThe cost matrix is \n";
    display(cost);
}

void prims::display(int a[max][max])
{
    int i, j;
    for (i = 0; i < numv; i++)
        cout << "\t" << vertex[i];
    cout << "\n";
    for (i = 0; i < numv; i++)
    {
        cout << vertex[i];
        for (j = 0; j < numv; j++)
        {
            cout << "\t" << a[i][j];
        }
        cout << "\n";
    }
}

void prims::display_table()
{
    int i;
    cout << "\nVERTEX\tDV\tKNOWN\tPV\n";
    for (i = 0; i < numv; i++)
    {
        cout << t[i].ver_no << "\t" << t[i].dv << "\t" << t[i].known << "\t" << t[i].pv;
        cout << "\n";
    }
}

void prims::prims_algo()
{
    int i, j, total = 0;
    for (i = 0; i < numv; i++) //initalize the values
    {
        t[i].pv = -1;
        t[i].ver_no = i;
        t[i].known = false;
        t[i].dv = inf;
    }
    cout << "\nInitially the table is :\n";
    display_table();
    cout << "\nEnter the source vertex\n";
    cin >> source;
    while (source < 0 || source >= numv)
    {
        cout << "\nSorry !!Wrong source\nPlease re - enter the correct one\n";
        cin >> source;
    }

    t->pv = source;
    t->known = false;
    t->dv = 0;
    display_table();
    cnt = 1;
    while (cnt < numv)
    {
        min = inf;
        for (i = 0; i < numv; i++) // find the next min distance
        {
            if (!t[i].known && t[i].dv < min)
            {
                min = t[i].dv;
                k = i;
            }
        }
        t[k].known = true;
        for (i = 0; i < numv; i++) //update values in table after new node is known
        {
            if (!t[i].known)
            {
                if (cost[k][i] < t[i].dv)
                {
                    t[i].dv = cost[k][i];
                    t[i].pv = k;
                }
            }
        }
        cnt++;
        display_table();
    }
}

void prims::spanning()
{
    int i, j, l, m, total = 0, value;
    for (i = 0; i < numv; i++) //initialize the 2D array to 0
        for (j = 0; j < numv; j++)
            span[i][j] = 0;
    for (i = 0; i < numv; i++) //store the weight of the edge included in the spanning tree from the table
    {
        for (j = 0; j < numv; j++)
        {
            l = t[i].ver_no;
            m = t[i].pv;
            value = t[i].dv;
            span[l][m] = value;
            span[m][l] = value;
        }
        total = total + span[l][m]; //calculate total minimum cost of edges included in MST
    }
    cout << "Minimal rental cost required to connect all the " << numv << " countries is " << total << "\n";
    cout << "Spanning graph is : \n";
    display(span);
}

int main()
{
    prims p;
    p.accept();
    p.prims_algo();
    p.spanning();
    return (0);
}