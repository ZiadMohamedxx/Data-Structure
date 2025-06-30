#include <iostream>
using namespace std;

class cNode
{
public:
    int info;
    cNode* pnext;
};

void main()
{
    cNode* phead;
    cNode* ptail;
    cNode* pnn;
    cNode* ptrav;

    phead = NULL;
    ptail = NULL;

    int N_values;

    cout << "Enter the number of values in your linked list" << endl;
    cin >> N_values;

    cout << "Enter the values for the linked list" << endl;

    for (int i = 0; i < N_values; i++)
    {
        pnn = new cNode[1];
        cin >> pnn->info;
        pnn->pnext = NULL;

        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }


    cNode* phead2;
    cNode* ptail2;
    cNode* pnn;
    cNode* ptrav2;

    phead2 = NULL;
    ptail2 = NULL;

    int N_values2;

    cout << "Enter the number of values in your linked list" << endl;
    cin >> N_values2;

    cout << "Enter the values for the linked list" << endl;

    for (int i = 0; i < N_values2; i++)
    {
        pnn = new cNode[1];
        cin >> pnn->info;
        pnn->pnext = NULL;

        if (phead2 == NULL)
        {
            phead2 = pnn;
            ptail2 = pnn;
        }
        else
        {
            ptail2->pnext = pnn;
            ptail2 = pnn;
        }
    }

    ptrav = phead;
    ptrav2 = phead2;

   
    for(int i=0;i<N_values;i++)
    {
        if (ptrav->info == ptrav2->info)
        {
            cout << i << ptrav->info;
        }

        ptrav = ptrav->pnext;
        ptrav2 = ptrav2->pnext;




    }

}
    