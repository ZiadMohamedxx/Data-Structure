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

    int V;

    cout << "Enter the target value" << endl;
    cin >> V;

    cNode* target = phead;
    int pos;
    pos = 0;

    while (target != NULL && target->info != V)
    {
        target = target->pnext;
        pos++;
    }

    if (target == NULL) 
    {
        cout << "Target value not found in the list" << endl;

    }

    int tot;
    tot = 0;

    cNode* current = phead;
    
    //before                                            
    for (int i = 0; i < pos - 3 && current != NULL; i++) 
    {
        current = current->pnext;
    }
    for (int i = 0; i < 3 && current != NULL; i++) 
    {
        tot += current->info;
        current = current->pnext;
    }
    
    //after
    current = target->pnext;
    for (int i = 0; i < 3 && current != NULL; i++) 
    {
        tot += current->info;
        current = current->pnext;
    }
    cout << "The total of 3 values before and after" << endl;
    cout << tot;


}