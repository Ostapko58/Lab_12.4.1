#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next;
	int info;
};

void insert(Elem*& begin, int value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (begin != NULL)
	{
		Elem* T = begin;
		while (T->next != begin)
			T = T->next; // 3
		T->next = tmp; // 4
	}
	else
	{
		begin = tmp; // 5
	}
	tmp->next = begin; // 6
}

//
//void Create(Elem*& end, Elem*& begin, int a)
//{
//
//	Elem* tmp = new Elem;
//	tmp->info = a;
//	//tmp->next = NULL;
//	if (end != NULL)
//	{
//		end->next = tmp;
//	}
//	end = tmp;
//	if (begin == NULL)
//	{
//		begin = tmp;
//	}
//	tmp->next = begin;
//
//}


//void Print(Elem* begin)
//{
//	while (begin != NULL)
//	{
//		cout << begin->info << "\t";
//		begin = begin->next;
//	}
//	cout << endl;
//}

void Print(Elem* L) {
	if (L == NULL)
		return;
	Elem* first = L;
	cout << L->info<<"\t";
	while (L->next != first)
	{
		L = L->next;
		cout << L->info << "\t";
	}
	cout << endl;
}

bool AreInElem(Elem* begin1, Elem* begin2)
{
	bool result = false;
	int flag = 1;
	if (begin1 == NULL)
		return result;
	Elem* L = begin2;
	Elem* first1 = begin1;
	Elem* first2 = begin2;
	if (L->next != first2&&L!=NULL)
	{
		if (begin1->info == L->info)
		{
			L = L->next;
			result = true;
		}
		else
		{
			if (begin1->info == begin2->info)
			{
				L = begin2;
				result = false;
			}
			else
			{
				L = begin2;
				result = false;
				//begin1 = begin1->next;
			}
			/*L = begin2;
			result = false;*/
		}
	}
	while (begin1->next != first1)
	{
		if (flag==1)
		{
			begin1 = begin1->next;
		}
		//begin1 = begin1->next;
		if (begin1->info == L->info)
		{
			L = L->next;
			result = true;
			flag = 1;
		}
		else
		{
			if (begin1->info == begin2->info)
			{
				L = begin2;
				result = false;
				flag = 0;
			}
			else
			{
				L = begin2;
				result = false;
				flag = 1;
				//begin1 = begin1->next;
			}

		/*	L = begin2;
			result = false;*/
		}
		if (L == first2&&flag==1)
		{
			break;
		}
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* begin1 = NULL,
		* end1 = NULL,
		* begin2 = NULL,
		* end2 = NULL;
	int a1[5] = { 1,1,2,5,3 };
	int a2[3] = { 1,2,4 };
	for (int i = 0; i < 5; i++)
	{
		//Create(end1, begin1, a1[i]);
		insert(begin1, a1[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		//Create(end2, begin2, a2[i]);
		insert(begin2, a2[i]);
	}
	Print(begin2);
	Print(begin1);
	if (AreInElem(begin1,begin2))
	{
		cout << "Так, список l1 входить в список l2" << endl;
	}
	else
	{
		cout << "Ні, список l1 не входить в список l2" << endl;
	}

	return 0;
}
