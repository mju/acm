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
	int count;
	struct listNode *head;
public :
	list(void);
	void insertNode(int);
	void showMedian(void);
};

list::list(void)
{
	count=0;
	head=NULL;
}

void list::insertNode(int key)
{
	struct listNode *p,*q,*t;
	count++;
	t=new struct listNode;
	t->data=key;
	for (q=NULL,p=head;p!=NULL && key>p->data;q=p,p=p->link);
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
}

void list::showMedian(void)
{
	int i;
	struct listNode *p;
	if (count==1)
		cout<<head->data<<endl;
	else if (count%2==0)
	{
		for (i=1,p=head;i<count/2;i++,p=p->link);
		cout<<(p->data+p->link->data)/2<<endl;
	}
	else 
	{
		for (i=0,p=head;i<count/2;i++,p=p->link);
		cout<<p->data<<endl;
	}
}

main()
{
	int key;
	list ob;
	while (cin>>key)
	{
		ob.insertNode(key);
		ob.showMedian();
	}
	return 0;
}


		




	


