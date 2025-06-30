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

	cNode* ptrav;
	cNode* ptrav2;
	cNode* pb = NULL;
	cNode* pnn;
	int x1;
	int x2;
	int n;
	cList list1, list2;
	cout << "Enter the number of elements in list(1)" << endl;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		pnn = new cNode[1];
		cout << "(list 1) enter the value number " << i + 1 << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		list1.attach(pnn);
	}
	cout << "enter the number of elements in List(2)" << endl;
	int n2;
	cin >> n2;

	for (int k = 0; k < n2; k++)
	{
		pnn = new cNode[1];
		cout << "(list 2) enter the value number " << k + 1 << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		list2.attach(pnn);
	}
	ptrav = list1.phead;
	int pos;
	pos = 0;
	int pos2;
	pos2 = 0;
	int m;
	for (int j = 0; j < n; j++)
	{
		x1 = ptrav->info;
		x2 = ptrav->pnext->info;
		ptrav2 = list2.phead;
		for ( m = 0; ptrav2->info!= x2; m++)
		{
			if (ptrav2->info==x1)
			{
				pos = m;
			}
			ptrav2 = ptrav2->pnext;
		}
		pos2 = m;
		int tot = 0;
		ptrav2 = list2.phead;
		for (int i = 0; i < pos2; i++)
		{
			if (i > pos)
			{
				tot += ptrav2->info;
			}
			ptrav2 = ptrav2->pnext;
		}
		cout << "total between nodes" << endl;
		cout << tot << endl;
		ptrav = ptrav->pnext->pnext;
	}

}