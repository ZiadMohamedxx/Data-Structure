#include <iostream>
using namespace std;

class cNode
{
public:
	int info;
	cNode* pnext;
};

class cList
{
public:
	cNode* phead;
	cNode* ptail;

	cList()
	{
		phead = NULL;
		ptail = NULL;

	}
	~cList()
	{
		cNode* ptrav = phead;
		while (phead != NULL)
		{
			phead = ptrav->pnext;
			ptrav->pnext = NULL;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cNode* pnn)
	{
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
};

void main()
{
	cList MainList;
	cNode* pnn;
	int n;
	cList Another_List;
	
	cout << "Enter the number of elements in the list:" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		pnn = new cNode[1];
		cout << "enter the value number " << i +1<< endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		MainList.attach(pnn);
	}

	int max;
	int min;

	max = -99999;
	min = 999999;
	cNode* ptrav;
	ptrav = MainList.phead;
	int pos_max;
	int pos_min;
	pos_max = 0;
	pos_min = 0;

	//max
	for (int i = 0; i < n; i++)
	{
		if (ptrav->info > max)
		{
			max = ptrav->info;
			pos_max = i;
			
		}
		ptrav = ptrav->pnext;
	}

	//min
	int k;
	ptrav = MainList.phead;
	for (k = 0; k < n; k++)
	{
		if (ptrav->info < min)
		{
			min = ptrav->info;
			pos_min = k;
			
		}
		ptrav = ptrav->pnext;
	}
	cout << "Maximum value is" << endl;
	cout << max << endl;
	cout << "minimum value is" << endl;
	cout << min << endl;

	ptrav = MainList.phead;
	if (pos_min < pos_max)
	{
		pnn = new cNode[1];
		pnn->info = min;
		pnn->pnext = NULL;
		Another_List.attach(pnn);


		pnn = new cNode[1];
		pnn->info = max;
		pnn->pnext = NULL;
		Another_List.attach(pnn);
		for (int j = 0; j < pos_max; j++)
		{
			if (j > pos_min)
			{
				pnn = new cNode[1];
				pnn->info = ptrav->info;
				pnn->pnext = NULL;
				Another_List.attach(pnn);
			}
			ptrav = ptrav->pnext;
		}
	}
	ptrav = MainList.phead;
	if (pos_min > pos_max)
	{
		pnn = new cNode[1];
		pnn->info = max;
		pnn->pnext = NULL;
		Another_List.attach(pnn);


		pnn = new cNode[1];
		pnn->info = min;
		pnn->pnext = NULL;
		Another_List.attach(pnn);
		for (int m = 0; m < pos_min; m++)
		{
			if (m > pos_max)
			{
				pnn = new cNode[1];
				pnn->info = ptrav->info;
				pnn->pnext = NULL;
				Another_List.attach(pnn);
			}
			
			ptrav = ptrav->pnext;
		}
	}
	ptrav = Another_List.phead;
	cout << "the nodes between maximum and minimum" << endl;
	while (ptrav != NULL)
	{
		cout << ptrav->info << "||";
		ptrav = ptrav->pnext;
	}
}