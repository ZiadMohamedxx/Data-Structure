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
	cNode* pnn;
	cList Mainlist[20];
	int n;
	int w;
	int i;
	cList NewL;

	for (int i = 0; i < 20; i++)
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
	int x = 0;
	int y = 19;
	cNode* pb_pos1;
	cNode* pos1 = NULL;
	cNode* pos2 = NULL;
	for (int k = 0; k < 20; k++)
	{
		if (k % 2 == 0)
		{
			ptrav = Mainlist[x].phead;
			while (ptrav != NULL)
			{
				if (ptrav->info < 0)
				{
					break;
				}
				pb_pos1 = ptrav;
				ptrav = ptrav->pnext;
			}
			pos1 = ptrav;
			ptrav = ptrav->pnext;
			while (ptrav != NULL)
			{
				if (ptrav->info < 0)
				{
					break;
				}
				ptrav = ptrav->pnext;
			}
			pos2 = ptrav;

			if (NewL.phead == NULL)
			{
				NewL.phead = pos1;
				NewL.ptail = pos2;
			}
			else
			{
				NewL.ptail->pnext = pos1;
				NewL.ptail = pos2;
			}
			pb_pos1->pnext = pos2->pnext;

			x++;
		}
		else
		{
			ptrav = Mainlist[y].phead;
			while (ptrav != NULL)
			{
				if (ptrav->info < 0)
				{
					break;
				}
				pb_pos1 = ptrav;
				ptrav = ptrav->pnext;
			}
			pos1 = ptrav;
			ptrav = ptrav->pnext;
			while (ptrav != NULL)
			{
				if (ptrav->info < 0)
				{
					break;
				}
				ptrav = ptrav->pnext;
			}
			pos2 = ptrav;
			if (NewL.phead == NULL)
			{
				NewL.phead = pos1;
				NewL.ptail = pos2;
			}
			else
			{
				NewL.ptail->pnext = pos1;
				NewL.ptail = pos2;
			}
			pb_pos1->pnext = pos2->pnext;
			y--;
		}
	}
	
}