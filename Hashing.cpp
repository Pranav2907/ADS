#include <iostream>
#include <stdint.h>
using namespace std;

class node
{
    string name;
    long long int ph;
    int id;

public:
    node()
    {
        ph = 0;
        id = 0;
    }
    friend class hashing;
};

class hashing
{

    node data[50];
    string n;
    long long int t;
    int i, index;

public:
    hashing()
    {
        i = 0;
        t = 0;
    }

    void create(int size)
    {

        i = 4;
        t = 9673062666;

        n = "Pranav";

        t = 96;
        cout << "\nEnter id :";
        cin >> i;
        cout << "\nEnter name :";
        cin >> n;
        cout
            << "\nEnter phone";
        cout << " number :";
        cin >> t;
        index = i % size;

        for (int j = 0; j < size; j++)
        {
            if (data[index].id == 0)
            {
                data[index].id = index;
                data[index].name = n;
                data[index].ph = t;
                break;
            }
            else
                index = (index + 1) % size;
        }
    }

    void update(int size)
    {
        int index1, key, flag = 0;
        key = 4;
        cout << "\nEnter record";
        cout << " id to update : ";
        cin >> key;
        index1 = key % size;

        for (int a = 0; a < size; a++)
        {
            if (data[index1].id == key)
            {
                flag = 1;
                break;
            }
            else
                index1 = (index1 + 1) % size;
        }

        if (flag == 1)
        {

            cout << "\nEnter name\t";

            cin >> n;
            cout << "\nEnter phone number\t";
            cin >> t;
            data[index1].name = n;
            data[index1].ph = t;

            cout << "\nDetails updated: ";
            cout << "\n\tID \tNAME";
            cout << " \t\tPHONE ";
            cout << "\n\t"
                 << data[index1].id
                 << " \t"
                 << data[index1].name
                 << " \t"
                 << data[index1].ph;
        }
    }

    void display(int size) // without replacement
    {
        cout << "\n\tID \tNAME";
        cout << " \t\tPHONE ";

        for (int a = 0; a < size; a++)
        {
            if (data[a].id != 0)
            {
                cout << "\n\t"
                     << data[a].id
                     << " \t"
                     << data[a].name
                     << " \t\t"
                     << data[a].ph;
            }
        }
    }
};

int main()
{
    int size, option;

    hashing s;
    size = 20;
    do
    {
        cout << "\nENTER THE NUMBER FOR THE OPERATION TO BE PERFORMED\n"
             << "\n1.Create"
             << "\n2.Display"
             << "\n3.Update"
             << "\nEnter 0 to exit";
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "\nCreate ";
            s.create(size);
            break;

        case 2:
            cout << "\nDisplay";
            s.display(size);
            break;
        case 3:
            cout << "\nUpdate";
            s.update(size);
            break;
        default:
            cout << "\nEnter proper number";
        }
    } while (option != 0);

    return 0;
}
