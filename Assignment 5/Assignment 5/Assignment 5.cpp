#include <iostream>
#include <conio.h>
using namespace std;

class cNode
{
	public:
	char s1[6];
	char s2[6];
	int z;
	cNode* pnext;
};
class cstack
{
	public:
	cNode* phead;
	cstack()
	{
		phead = NULL;
	}
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
	pnn->pnext = NULL;

	pnn->s2[0] = ' ';
	pnn->s2[1] = ' ';
	pnn->s2[2] = ' ';
	pnn->s2[3] = ' ';
	pnn->s2[4] = ' ';
	pnn->s2[5] = ' ';

	pnn->s1[0] = 'a'; //1000
	pnn->s1[1] = 'b';//700
	pnn->s1[2] = 'c';//300
	pnn->s1[3] = '1';
	pnn->s1[4] = '7';
	pnn->s1[5] = '3';
	
	pnn->z = 1;//up


	return pnn;
}

void display(cNode* node)
{
	if (node == NULL)
	{
		cout << "Node is NULL." << endl;
		return;
	}


	cout << "Side 1 (s1): ";
	for (int i = 0; i < 6; i++)
	{
		cout << node->s1[i] << "|";
	}
	cout << endl;

	cout << "Side 2 (s2): ";
	for (int i = 0; i < 6; i++)
	{
		cout << node->s2[i] << "|";
	}
	cout << endl;

	if (node->z == 1)
	{
		cout << "Boat Position (z): UP" << endl;
	}
	else 
	{
		cout << "Boat Position (z): DOWN" << endl;
	}
	cout << "--------------------------" << endl;

	

}
int isvisited(cNode* pnn, cList& lv)
{
	cNode* ptrav = lv.phead; 
	int flag = 0;            

	while (ptrav != NULL)
	{
		int visited = 1; 

		
		for (int i = 0; i < 6; i++)
		{
			if (ptrav->s1[i] != pnn->s1[i] || ptrav->s2[i] != pnn->s2[i])
			{
				visited = 0; 
				break;          
			}
		}

		if (visited == 1 && ptrav->z != pnn->z)
		{
			visited = 0; 
		}

		if (visited == 1)
		{
			flag = 1; 
			break;    
		}

		ptrav = ptrav->pnext; 
		
	}
	
	return flag;
}


int islegal(cNode* pnn)
{
	// a = 1000
	// b = 700
	// c = 300
	int tot1_s1;
	tot1_s1 = 0;
	int tot2_s1;
	tot2_s1 = 0;


	int tot1_s2;
	tot1_s2 = 0;
	int tot2_s2;
	tot2_s2 = 0;
	int F;
	F = 0;

	//btwtl el 7rameya side 1 & 2
	
		//s1
		if (pnn->s1[0] == 'a')
		{
			tot1_s1 = tot1_s1 + 1000;
		}
		if (pnn->s1[1] == 'b')
		{
			tot1_s1 = tot1_s1 + 700;
		}
		if (pnn->s1[2] == 'c')
		{
			tot1_s1 = tot1_s1 + 300;
		}
		//s2
		if (pnn->s2[0] == 'a')
		{
			tot1_s2 = tot1_s2 + 1000;
		}
		if (pnn->s2[1] == 'b')
		{
			tot1_s2 = tot1_s2 + 700;
		}
		if (pnn->s2[2] == 'c')
		{
			tot1_s2 = tot1_s2 + 300;
		}
	

	//hatwtl el floos
	
		//s1
		if (pnn->s1[3] == '1')
		{
			tot2_s1 = tot2_s1 + 1000;
		}
		if (pnn->s1[4] == '7')
		{
			tot2_s1 = tot2_s1 + 700;
		}
		if (pnn->s1[5] == '3')
		{
			tot2_s1 = tot2_s1 + 300;
		}

		//s2
		if (pnn->s2[3] == '1')
		{
			tot2_s2 = tot2_s2 + 1000;
		}
		if (pnn->s2[4] == '7')
		{
			tot2_s2 = tot2_s2 + 700;
		}
		if (pnn->s2[5] == '3')
		{
			tot2_s2 = tot2_s2 + 300;
		}
		
		
	if (tot1_s1 >= tot2_s1 && tot1_s2 >= tot2_s2)
	{
		F = 1;
	}


	
	return F;
	
}


void expand(cNode* pcur, cstack& s,cList &lv)
{	
	lv.attach(pcur);

	for (int i = 0; i < 15; i++)
	{
		cNode* pnn = new cNode;

		for (int k = 0; k < 6; k++)
		{
			pnn->s1[k] = pcur->s1[k];
			pnn->s2[k] = pcur->s2[k];
		}
		pnn->z = pcur->z;
		if (pnn->z == 1)//UP
		{
			if (i == 0)
			{
				if (pnn->s1[0] == 'a')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->z = 0;
				}
			}
			if (i == 1)
			{
				if (pnn->s1[0] == 'a' && pnn->s1[1] == 'b')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->z = 0;
				}
			}
			if (i == 2)
			{
				if (pnn->s1[0] == 'a' && pnn->s1[2] == 'c')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->z = 0;
				}
			}

			if (i == 3)
			{
				if (pnn->s1[0] == 'a' && pnn->s1[3] == '1')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->s1[3] = ' ';
					pnn->s2[3] = '1';
					pnn->z = 0;
				}
			}
			if (i == 4)
			{
				if (pnn->s1[0] == 'a' && pnn->s1[5] == '3')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->s1[5] = ' ';
					pnn->s2[5] = '3';
					pnn->z = 0;
				}
			}
			if (i == 5)
			{
				if (pnn->s1[0] == 'a' && pnn->s1[4] == '7')
				{
					pnn->s1[0] = ' ';
					pnn->s2[0] = 'a';
					pnn->s1[4] = ' ';
					pnn->s2[4] = '7';
					pnn->z = 0;
				}
			}
			if (i == 6)
			{
				if (pnn->s1[1] == 'b')
				{
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->z = 0;
				}
			}
			if (i == 7)
			{
				if (pnn->s1[2] == 'c')
				{
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->z = 0;
				}
			}
			if (i == 8)
			{
				if (pnn->s1[1] == 'b' && pnn->s1[2] == 'c')
				{
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->z = 0;
				}
			}
			if (i == 9)
			{
				if (pnn->s1[1] == 'b' && pnn->s1[3] == '1')
				{
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->s1[3] = ' ';
					pnn->s2[3] = '1';
					pnn->z = 0;
				}
			}
			if (i == 10)
			{
				if (pnn->s1[1] == 'b' && pnn->s1[5] == '3')
				{
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->s1[5] = ' ';
					pnn->s2[5] = '3';
					pnn->z = 0;
				}
			}
			if (i == 11)
			{
				if (pnn->s1[1] == 'b' && pnn->s1[4] == '700')
				{
					pnn->s1[1] = ' ';
					pnn->s2[1] = 'b';
					pnn->s1[4] = ' ';
					pnn->s2[4] = '700';
					pnn->z = 0;
				}
			}
			if (i == 12)
			{
				if (pnn->s1[2] == 'c' && pnn->s1[3] == '1')
				{
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->s1[3] = ' ';
					pnn->s2[3] = '1';
					pnn->z = 0;
				}
			}
			if (i == 13)
			{
				if (pnn->s1[2] == 'c' && pnn->s1[5] == '3')
				{
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->s1[5] = ' ';
					pnn->s2[5] = '3';
					pnn->z = 0;
				}
			}
			if (i == 14)
			{
				if (pnn->s1[2] == 'c' && pnn->s1[4] == '7')
				{
					pnn->s1[2] = ' ';
					pnn->s2[2] = 'c';
					pnn->s1[4] = ' ';
					pnn->s2[4] = '7';
					pnn->z = 0;
				}
			}
		}
		else//DOWN
		{
			if (i == 0)
			{
				if (pnn->s2[0] == 'a')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->z = 1;
				}
			}
			if (i == 1)
			{
				if (pnn->s2[0] == 'a' && pnn->s2[1] == 'b')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->z = 1;
				}
			}
			if (i == 2)
			{
				if (pnn->s2[0] == 'a' && pnn->s2[2] == 'c')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->z = 1;
				}
			}

			if (i == 3)
			{
				if (pnn->s2[0] == 'a' && pnn->s2[3] == '1')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->s2[3] = ' ';
					pnn->s1[3] = '1';
					pnn->z = 1;
				}
			}
			if (i == 4)
			{
				if (pnn->s2[0] == 'a' && pnn->s2[5] == '3')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->s2[5] = ' ';
					pnn->s1[5] = '3';
					pnn->z = 1;
				}
			}
			if (i == 5)
			{
				if (pnn->s2[0] == 'a' && pnn->s2[4] == '7')
				{
					pnn->s2[0] = ' ';
					pnn->s1[0] = 'a';
					pnn->s2[4] = ' ';
					pnn->s1[4] = '7';
					pnn->z = 1;
				}
			}
			if (i == 6)
			{
				if (pnn->s2[1] == 'b')
				{
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->z = 1;
				}
			}
			if (i == 7)
			{
				if (pnn->s2[2] == 'c')
				{
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->z = 1;
				}
			}
			if (i == 8)
			{
				if (pnn->s2[1] == 'b' && pnn->s2[2] == 'c')
				{
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->z = 1;
				}
			}
			if (i == 9)
			{
				if (pnn->s2[1] == 'b' && pnn->s2[3] == '1')
				{
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->s2[3] = ' ';
					pnn->s1[3] = '1';
					pnn->z = 1;
				}
			}
			if (i == 10)
			{
				if (pnn->s2[1] == 'b' && pnn->s2[5] == '3')
				{
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->s2[5] = ' ';
					pnn->s1[5] = '3';
					pnn->z = 1;
				}
			}
			if (i == 11)
			{
				if (pnn->s2[1] == 'b' && pnn->s2[4] == '7')
				{
					pnn->s2[1] = ' ';
					pnn->s1[1] = 'b';
					pnn->s2[4] = ' ';
					pnn->s1[4] = '7';
					pnn->z = 1;
				}
			}
			if (i == 12)
			{
				if (pnn->s2[2] == 'c' && pnn->s2[3] == '1')
				{
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->s2[3] = ' ';
					pnn->s1[3] = '1';
					pnn->z = 1;
				}
			}
			if (i == 13)
			{
				if (pnn->s2[2] == 'c' && pnn->s2[5] == '3')
				{
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->s2[5] = ' ';
					pnn->s1[5] = '3';
					pnn->z = 1;
				}
			}
			if (i == 14)
			{
				if (pnn->s2[2] == 'c' && pnn->s2[4] == '7')
				{
					pnn->s2[2] = ' ';
					pnn->s1[2] = 'c';
					pnn->s2[4] = ' ';
					pnn->s1[4] = '7';
					pnn->z = 1;
				}
			}

		}
		int re = islegal(pnn);
		if (re == 1 && isvisited(pnn, lv) == 0)
		{
			display(pnn);
			
			
			if (pnn->z == 1)
			{
				pnn->z = 0;
			}
			else
			{
				pnn->z = 1;
			}
			s.push(pnn);
		}
		
	}

}



void bk()
{
	cNode* pcur;
	cstack s;
	cNode* pnn;
	cList lv;
	int k;
	
	pnn = giveMeInit();
	s.push(pnn);
	while (s.phead != NULL)
	{
		pcur = s.pop();
		display(pcur);
		for ( k = 0; k < 6; k++)
		{
			if (pcur->s2[k] == ' ')
			{
				break;
			}
		}
		if (k == 6)
		{
			break;
		}
		expand(pcur, s,lv);
	}
}


void main()
{
	bk();
}