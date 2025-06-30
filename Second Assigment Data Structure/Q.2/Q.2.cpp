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

void Reverse_List1(cList MainList)
{

	
	cNode* pb = NULL;
	cNode* ptrav = MainList.phead;
	cNode* next = NULL;
	MainList.ptail = MainList.phead; 

	while (ptrav != NULL)
	{
		next = ptrav->pnext;  
		ptrav->pnext = pb;  
		pb = ptrav;         
		ptrav = next;         
	}

	MainList.phead = pb;
	
	ptrav = MainList.phead;
	cout << "Reversed original list: " << endl;
	while (ptrav != NULL)
	{
		cout << ptrav->info << "||";
		ptrav = ptrav->pnext;
	}


}
void Reverse_list2(cList MainList,cList ReversedList)
{
	cNode* ptrav = MainList.phead;

	while (ptrav != NULL)
	{
		cNode* pnn = new cNode;  
		pnn->info = ptrav->info; 
		pnn->pnext = NULL;

		
		ReversedList.attach(pnn);

		ptrav = ptrav->pnext;  
	}
	Reverse_List1(ReversedList);
}
void main()
{
	cList MainList;
	cList ReversedList;
	cNode* pnn;
	int n;
	cList list1, list2;
	cout << "Enter the number of elements in the list:" << endl;
	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		pnn = new cNode[1];
		cout << "enter the value number " << i << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		MainList.attach(pnn);
	}
	int method = 0;
	cout << "choose your method 1 OR 2 " << endl;
	cin >> method;
	if (method == 1)
	{
		Reverse_List1(MainList);
	}
	if (method == 2)
	{
		cNode* ptrav = MainList.phead;
		cout << "the original mainlist" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << ptrav->info << endl;
			ptrav = ptrav->pnext;
		}
		Reverse_list2(MainList, ReversedList);
	}
	
	
}