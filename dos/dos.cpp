// Дано два списка получить новый список, состоящий из элементов, принадлежащих интервалу [a, b].
//

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

int main()
{

	cout << "Enter first list" << endl;

	list* head1, * p1, * r1;
	list* head2, * p2, * r2;
	list* head, * p, * r;
	int x, y;
	head = new list;
	head1 = new list;
	head2 = new list;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	head1->next = NULL;
	head1->prev = NULL;
	p = head;
	p1 = head1;
	p2 = head2;

	cin >> x;
	while (x)
	{
		r1 = new list;
		r1->info = x;
		r1->next = NULL;
		r1->prev = p1;
		p1->next = r1;
		p1 = r1;
		cin >> x;

	}

	cout << "Enter second list" << endl;

	cin >> x;
	while (x)
	{
		r2 = new list;
		r2->info = x;
		r2->next = NULL;
		r2->prev = p2;
		p2->next = r2;
		p2 = r2;
		cin >> x;

	}

	int a, b;
	cout << "Enter left interval - ";
	cin >> a;
	cout << "Enter right interval - ";
	cin >> b;

	p1 = head1;
	p2 = head2;

	while (p1 != NULL)
	{

		if (p1->info >= a && p1->info <= b)
		{

			r = new list;
			r->info = p1->info;
			r->next = NULL;
			r->prev = p;
			p->next = r;
			p = r;
			cout << p->info << setw(3);

		}

		p1 = p1->next;

	}

	while (p2 != NULL)
	{

		if (p2->info >= a && p2->info <= b)
		{

			r = new list;
			r->info = p2->info;
			r->next = NULL;
			r->prev = p;
			p->next = r;
			p = r;
			cout << p->info << setw(3);

		}

		p2 = p2->next;

	}

}