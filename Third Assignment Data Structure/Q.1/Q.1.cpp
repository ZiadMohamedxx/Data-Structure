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
	void remove(cList zoz)
	{
		cNode* ptrav;
		cNode* ptrav2;
		cNode* pb = NULL;

		ptrav2 = phead;
		ptrav = zoz.phead;
		for (int j = 0; ptrav != NULL; j++)
		{
			if (ptrav->info == ptrav2->info)
			{
				pb->pnext = ptrav2->pnext;
				delete ptrav2;
				ptrav2 = pb->pnext;
			}
			else
			{
				pb = ptrav2;
				ptrav2 = ptrav2->pnext;
			}
			ptrav = ptrav->pnext;

		}
		cout << "list 2 after removal" << endl;
		ptrav2 = phead;
		while (ptrav2 != NULL)
		{
			cout << ptrav2->info << "||";
			ptrav2 = ptrav2->pnext;
		}
	}

};


void main()
{
	cNode* ptrav;
	cNode* ptrav2;
	cNode* pb = NULL;
	cNode* pnn;
	int n;
	cList list1, list2;
	cout << "Enter the number of elements in the list:" << endl;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		pnn = new cNode[1];
		cout << "(list 1) enter the value number " << i + 1 << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		list1.attach(pnn);
	}

	for (int k = 0; k < n; k++)
	{
		pnn = new cNode[1];
		cout << "(list 2) enter the value number " << k + 1 << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		list2.attach(pnn);
	}

	list2.remove(list1);


}