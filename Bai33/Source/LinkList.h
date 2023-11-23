
#ifndef LINK_LIST_
#define LINK_LIST_

#include <iostream>
#include "../Source/CongViec.h"
#include "../Source/NodeBST.h"

struct Node
{
	CongViec data;
	Node *next;
};

typedef struct Node *node;

node makeNode(CongViec x)
{
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

bool empty(node a)
{
	return a == NULL;
}

int Size(node a)
{
	int cnt = 0;
	while (a != NULL)
	{
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
	}
	return cnt;
}

void TickCongViecHoanThanh(node a, string giobatdau, string tencv)
{
	while (a != NULL)
	{
		if (a->data.gettime_start() == giobatdau && a->data.getten_cong_viec() == tencv)
		{
			a->data.setcheck_Hoan_Thanh(true);
		}
		a = a->next;
	}
}

int findPos(node a)
{
	int cnt = 1;
	while (a != NULL)
	{
		if (a->data.getcheck_Hoan_thanh())
		{
			return cnt;
		}
		cnt++;
		a = a->next;
	}
	return 0;
}

// them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &a, CongViec x)
{
	node tmp = makeNode(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		tmp->next = a;
		a = tmp;
	}
}

// Them 1 phan tu vao cuoi dslk
void insertLast(node &a, CongViec x)
{
	node tmp = makeNode(x);
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		node p = a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = tmp;
	}
}

// Them 1 phan tu vao giua dslk
void insertMiddle(node &a, CongViec x, int pos)
{
	int n = Size(a);
	if (pos <= 0 || pos > n + 1)
	{
		cout << "Vi tri chen khong hop le !\n";
	}
	if (pos == 1)
	{
		insertFirst(a, x);
		return;
	}
	else if (pos == n + 1)
	{
		insertLast(a, x);
		return;
	}
	node p = a;
	for (int i = 1; i < pos - 1; i++)
	{
		p = p->next;
	}
	node tmp = makeNode(x);
	tmp->next = p->next;
	p->next = tmp;
}

// xoa phan tu o dau
void deleteDau(node &a)
{
	if (a == NULL)
	{
		return;
	}
	a = a->next;
}

// xoa phan tu o cuoi
void deleteCuoi(node &a)
{
	if (a == NULL)
		return;
	node truoc = NULL, sau = a;
	while (sau->next != NULL)
	{
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL)
	{
		a = NULL;
	}
	else
	{
		truoc->next = NULL;
	}
}

// Xoa o giua
void deleteGiua(node &a, int pos)
{
	if (pos <= 0 || pos > Size(a))
		return;
	node truoc = NULL, sau = a;
	for (int i = 1; i < pos; i++)
	{
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL)
	{
		a = a->next;
	}
	else
	{
		truoc->next = sau->next;
	}
}

void in(node a)
{
	while (a != NULL)
	{
		cout << a->data;
		a = a->next;
	}
}

void in_Theo_Tinh_Chat_Cong_Viec(node a, string tinh_chat)
{
	while (a != NULL)
	{
		if (a->data.gettinh_chat_cong_viec() == tinh_chat)
		{
			cout << a->data;
		}
		a = a->next;
	}
}

void in_Theo_Cong_Viec_Da_Hoan_Thanh(node a)
{
	while (a != NULL)
	{
		if (a->data.getcheck_Hoan_thanh())
		{
			cout << a->data;
		}
		a = a->next;
	}
}

void in_Theo_Cong_Viec_Chua_Hoan_Thanh(node a)
{
	while (a != NULL)
	{
		if (!(a->data.getcheck_Hoan_thanh()))
		{
			cout << a->data;
		}
		a = a->next;
	}
}

void sapxep(node &a)
{
	for (node p = a; p->next != NULL; p = p->next)
	{
		node tmp = p;
		for (node q = p->next; q != NULL; q = q->next)
		{
			if (stof(q->data.gettime_start()) < stof(tmp->data.gettime_start()))
			{
				tmp = q;
			}
		}
		CongViec swap = tmp->data;
		tmp->data = p->data;
		p->data = swap;
	}
}

#endif