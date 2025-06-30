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

void split_list1(cList MainList,int splitval,cList List1,cList List2)
	{
		cNode* pnn;
		cNode* ptrav ;
		ptrav = MainList.phead;
		
		
		while (ptrav != NULL)
		{
			cNode* pnn;
			pnn = new cNode[1];
			pnn->info = ptrav->info;
			pnn->pnext = NULL;
			if (ptrav->info != splitval)
			{
				List1.attach(pnn);
		
			}
			else
			{
				break;
			}
			ptrav = ptrav->pnext;
		}
		while(ptrav!=NULL)
		{
			pnn = new cNode[1];
			pnn->info = ptrav->info;
			pnn->pnext = NULL;
			List2.attach(pnn);
			ptrav = ptrav->pnext;
		}
		cNode* pl1;
		cNode* pl2;

		//cout main list //
		ptrav = MainList.phead;
		cout << "Main List is" << ">>";
		while (ptrav != NULL)
		{
			cout << ptrav->info << "||";
			ptrav = ptrav->pnext;
		}
		//cout List 1 //
		pl1 = List1.phead;
		cout << " List 1 is" << ">>";
		while (pl1 != NULL)
		{
			cout << pl1->info << "||";
			pl1 = pl1->pnext;
		}
		//cout List 2 //
		pl2 = List2.phead;
		cout << " List 2 is" << ">>";
		while (pl2 != NULL)
		{
			cout << pl2->info << "||";
			pl2 = pl2->pnext;
		}
	}

	void split_list2(cList MainList, int splitval, cList List1, cList List2)
	{
		cNode* ptrav = MainList.phead; 
		List1.phead = MainList.phead;
		while (ptrav != NULL)
		{
			if (ptrav->pnext->info==splitval)
			{
				
				List2.phead = ptrav->pnext;
				ptrav->pnext = NULL;
				List1.ptail = ptrav;
				break;
			}
			List2.ptail = MainList.ptail;
			MainList.ptail = NULL;
			ptrav = ptrav->pnext; 
		}
		MainList.phead = NULL;

		cNode* pl1;
		cNode* pl2;

		//cout main list //
		ptrav = MainList.phead;
		cout << "Main List is" << ">>";
		while (ptrav != NULL)
		{
			cout << ptrav->info << "||";
			ptrav = ptrav->pnext;
		}
		//cout List 1 //
		pl1 = List1.phead;
		cout << " List 1 is" << ">>";
		while (pl1 != NULL)
		{
			cout << pl1->info << "||";
			pl1 = pl1->pnext;
		}
		//cout List 2 //
		pl2 = List2.phead;
		cout << " List 2 is" << ">>";
		while (pl2 != NULL)
		{
			cout << pl2->info << "||";
			pl2 = pl2->pnext;
		}
	}
void main()
{
	cList MainList ;
	cNode* pnn;
	int n;
	cList list1, list2;
	cout << "Enter the number of elements in the list:" << endl;
	cin >> n;



	for (int i = 0; i < n; i++)
	{
		pnn = new cNode[1];
		cout << "enter the value number " << i << endl;
		cin >> pnn->info;
		pnn->pnext = NULL;
		MainList.attach(pnn);
	}
	int splitval;
	cout << "enter the split value" << endl;
	cin >> splitval;
	int method=0;
	cout << "enter your method 1 OR 2" << endl;
	cin >> method;
	if (method==1)
	{
		split_list1(MainList, splitval, list1, list2);
	}
	if(method==2)
	{
		split_list2(MainList, splitval, list1, list2);
	}
}



