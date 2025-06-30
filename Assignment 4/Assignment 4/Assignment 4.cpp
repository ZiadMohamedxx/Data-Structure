#include <iostream>
using namespace std;

class cNode
{
public:
	int cr;
	char info[10][10];
	cNode* pnext;
};
class cstack
{
public:
	cNode* phead;
	void push(cNode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cNode* pop()
	{
		cNode* ptrav = phead;
		if (ptrav == NULL)
		{
			return NULL;
		}
		else
		{
			phead = phead->pnext;
			ptrav->pnext = NULL;
			return ptrav;
		}
	}
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
cNode* giveMeInit()
{
	cNode* pnn = new cNode;
	pnn->cr = 0;
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 10; c++)
		{
			pnn->info[r][c] = ' ';
		}
	}
	return pnn;
}
int islegal(cNode* pnn)
{
	int flag = 0;
	int z = 0;
	int y = pnn->cr - 1;
	int pos;
	cstack s;
	for (int i = 0; i < 10; i++)
	{
		for (int k=0;k<10;k++)
		{
			if (pnn->info[pnn->cr][k] == 'Q')
			{
				pos = k;
			}
		}

		for (int c = pos; c < 10; c++)
		{
			if (pnn->info[y - z][c - z] == 'Q' ||pnn->info[y - z][c] == 'Q' || pnn->info[y - z][c + z] == 'Q')
			{

				flag = 1;
				break;
			}
			z++;
		}
	}

	return flag;  
}
void expand(cNode* pcur, cstack& s)
{
	for (int i = 0; i < 10; i++)
	{
		cNode* pnn = new cNode;
		pnn->cr = pcur->cr;
		pnn->pnext = pcur->pnext;
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				pnn->info[r][c] = pcur->info[r][c];
			}
		}
		pnn->info[pnn->cr++][i] = 'Q';
		int re = islegal(pnn);
		if (re == 1)
		{
			s.push(pnn);
		}
	}
}
void bk()
{
	cNode* pcur;
	cstack s;
	cNode* pnn;
	pnn = giveMeInit();
	s.push(pnn);
	while (s.phead != NULL)
	{
		pcur = s.pop();
		expand(pcur, s);
	}
}