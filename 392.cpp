#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

struct bass
{
	int a;//«Y¼Æ
	int b;//«ü¼Æ
	struct bass *link;
};

class functionList
{
	friend ostream &operator<<(ostream &,const functionList &);
private :
	struct bass *head;
public :
	functionList(void);
	void insertNode(int,int);
	functionList operator+(const functionList &);
};

ostream &operator<<(ostream &output,const functionList &right)
{
	struct bass *p;
	int first=1;
	for (p=right.head;p!=NULL;p=p->link)
	{
		if (p->a==0) continue;
		if (p->b!=0 && p->b!=1 && first)
		{
			first=0;
			if (p->a==1) output<<"x^"<<p->b;
			else if (p->a==-1) output<<"-x^"<<p->b;
			else output<<p->a<<"x^"<<p->b;
		}
		else if (p->b==1)
		{
			if (first)
			{
				first=0;
				if (p->a==1) output<<"x";
				else if (p->a==-1) output<<"-x";
				else output<<p->a<<"x";
			}
			else if (p->a==1) output<<" + x";
			else if (p->a==-1) output<<" - x";
			else 
			{
				if (p->a>1) output<<" + "<<p->a<<"x";
				else if (p->a<-1) output<<" - "<<-p->a<<"x";
			}
		}
		else if (p->b==0)
		{
			if (first) 	first=0,output<<p->a;
			else if (p->a>0) output<<" + "<<p->a;
			else if (p->a<0) output<<" - "<<-p->a;
		}
		else
		{
			if (p->a>1) output<<" + "<<p->a<<"x^"<<p->b;
			else if (p->a==1) output<<" + "<<"x^"<<p->b;
			else if (p->a==-1) output<<" - "<<"x^"<<p->b;
			else if (p->a<-1) output<<" - "<<-p->a<<"x^"<<p->b;
		}
	}
	if (first) first=0,output<<"0";
	return output;
}

functionList functionList::operator+(const functionList &f2)
{
	functionList f3;
	struct bass *p;
	for (p=head;p!=NULL;p=p->link)
		f3.insertNode(p->a,p->b);
	for (p=f2.head;p!=NULL;p=p->link)
		f3.insertNode(p->a,p->b);
	return f3;
}
functionList::functionList(void)
{
	head=NULL;
}
void functionList::insertNode(int key1,int key2)
{
	struct bass *t,*p,*q;
	t=new struct bass;
	t->a=key1;
	t->b=key2;
	if (key1==0) return;
	for (p=head,q=NULL;p!=NULL && key2<=p->b;q=p,p=p->link);
	if (q!=NULL && key2==q->b)
	{
		q->a=q->a+key1;
		return;
	}
	else if (p==head)
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

int buildList(functionList &polynomial)
{
	int i;
	int key1;
	for (i=8;i>=0;i--)
	{
		if (!(cin>>key1)) return 0;
		polynomial.insertNode(key1,i);
	}
	return 1;
}
main()
{
	functionList *f1;
	while (1)
	{
		f1=new functionList;
		if (!buildList(*f1)) break;
		cout<<(*f1)<<endl;
	}
	return 0;
}
	
		

