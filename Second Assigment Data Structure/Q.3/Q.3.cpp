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
	cout << "Enter the number of elements in the list:" << endl;
	cin >> n;



	for (int i = 0; i < n; i++)
	{
		pnn = new cNode[1];
		cout << "enter the value number " << i+1 << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		MainList.attach(pnn);
	}

	cout << "enter a number you want to rotating" << endl;
	int number;
	cin >> number;
	cNode* pb=NULL;
	cNode* ptrav;
	ptrav = MainList.phead;
	int ct = 0;
	while (ct != number)
	{
		ct++;
		pb = ptrav;
		ptrav = ptrav->pnext;
		
	}


	MainList.ptail->pnext = MainList.phead;
	pb->pnext = NULL;
	MainList.phead = ptrav;
	MainList.ptail = pb;


	cout << "The rotated MainList" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ptrav->info << endl;
		ptrav = ptrav->pnext;
	}
}