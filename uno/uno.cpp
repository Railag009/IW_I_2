// Дан двунаправленный список. Если в нем есть n-чисел, у которых есть хотя бы 2 нечетных делителя, то удалить все числа,
// перед которыми расположенные соверщенные, иначе вставить между равными n.

#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct list
{
	int info;
	list* next;
	list* prev;
};

int sum(int a, int b)
{

	if (b > a) return 0;
	if (a % b == 0 && b % 2 != 0) return sum(a, b + 1) + 1;
	return sum(a, b + 1);

}
int sov(int a, int b)
{

	if (b == a) return 0;
	if (a % b == 0) return sov(a, b + 1) + b;
	return sov(a, b + 1);

}


int main()
{

	list* head, * p, * r;
	int x, y;
	head = new list;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	p = head;

	cin >> x;
	while (x)
	{
		r = new list;
		r->info = x;
		r->next = NULL;
		r->prev = p;
		p->next = r;
		p = r;
		cin >> x;

	}

	int n;
	cout << "Enter number - ";
	cin >> n;

	int i = 0;

	p = head;

	while (p != NULL)
	{

		int a = sum(p->info, 1);
		if (a > 1) i++;

		p = p->next;

	}

	if (i == n)
	{

		p = head->next;

		while (p != NULL)
		{

			if (p->prev->info == sov(p->prev->info, 1))
			{

				r = p;
				p->prev->next = r->next;
				p->next->prev = p->prev;
				p = p->next;
				delete r;
				p = p->next;


			}
			else
			{

				p = p->next;

			}

		}

		p = head;

		while (p != NULL)
		{

			cout << p->info << setw(3);
			p = p->next;

		}

	}
	else
	{

		p = head;

		while (p->next != NULL)
		{

			if (p->next->info == p->info)
			{

				r = new list;
				r->info = n;
				r->next = p->next;
				r->prev = p;
				p->next = r;
				p = r;
				
			}

			p = p->next;
			
		}

		p = head;

		while (p != NULL)
		{

			cout << p->info << setw(3);
			p = p->next;

		}

	}

}