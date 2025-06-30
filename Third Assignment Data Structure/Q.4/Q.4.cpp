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
	cNode* pnn;
	cList Mainlist[30];
	int n;
	int w;
	int i;
	cNode* pb = NULL;

	for (int i = 0; i < 30; i++)
	{
		cout << "Enter the number of elements of list " << i + 1 << endl;
		cin >> n;
		for (int w = 0; w < n; w++)
		{
			pnn = new cNode[1];
			cin >> pnn->info;
			pnn->pnext = NULL;
			Mainlist[i].attach(pnn);
		}
	}

	for (int k = 0; k < 30; k+=2)
	{

		ptrav = Mainlist[k].phead;
		ptrav2 = Mainlist[k+1].phead;
		while (ptrav != NULL)
		{
			if (ptrav->info == -1)
			{
				pb->pnext = ptrav2->pnext;
				ptrav2->pnext = ptrav->pnext;
				ptrav->pnext = ptrav2;
				break;
			}
			ptrav = ptrav->pnext;
			pb = ptrav2;
			ptrav2 = ptrav2->pnext;
		}
	}

}