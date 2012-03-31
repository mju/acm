#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct listNode
{
	int data;
	struct listNode *link;
};

class list
{
private :
	struct listNode *head;
	int size;
	int mValue;
	int abso(int);
public :
	list(void);
	void insert(int);
	int calculate(void);
//	~list(void);
};

list::list(void)
{
	head=NULL;
	size=0;
}

int list::abso(int key)
{
	return key>0?key:(-1)*key;
}

void list::insert(int key)
{
	struct listNode *t,*q,*p;
	t=new struct listNode;
	t->data=key;
	for (q=NULL,p=head;p!=NULL && p->data<key;q=p,p=p->link) ;

	if (q==NULL)
	{
		t->link=head;
		head=t;
	}
	else
	{
		t->link=q->link;
		q->link=t;
	}

	size++;
}

int list::calculate(void)
{
	struct listNode *p;
	int i;
	int total=0;
	for (p=head,i=1;i<(size/2+size%2);p=p->link,i++) ;
	mValue=p->data;
	for (p=head;p!=NULL;p=p->link)
		total+=abso(p->data-mValue);
	return total;
}

main()
{
	list *p;
	int N;
	int i;
	int j;
	int n;
	int key;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		p=new list;
		cin>>n;
		for (j=1;j<=n;j++)
		{
			cin>>key;
			p->insert(key);
		}
		cout<<p->calculate()<<endl;
	}
	return 0;
}







