#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include<stdlib.h>
using namespace std;
class outofbound{};
class illegalsize{};
template <class T>
/*线性表类定义*/
class list
{
     public:
     virtual void clear()=0;
     virtual int length() const=0;//const意思是不能修改成员变量的值
     virtual void remove(int i)=0;
     virtual void insert(int i,const T &b)=0;
     virtual int search(const T &a) const=0;
     virtual T visit(int i) const=0;
     virtual void traverse(void) const=0;
     virtual ~list(){ }
};

/*顺序表类定义*/
template <class T>
class seqlist:public list<T>
{
    private:
    int currentlengeh;
    T *data;
    int maxsize;
    int initsize;
    void doublespace(void);
    public:
    void creat();
    void clear()
    {delete []data;}
    void insert(int i,const T &b);
    void remove(int i);//基类中的虚函数在子类中必须再次声明
    int search(const T &i) const;
    T visit(int i) const;
    void traverse(void) const;
    seqlist(int const initsize);
    int length() const
    {
        return currentlengeh;
    }
    ~seqlist()
    {
        delete []data;
    }
};
template <class T>
void seqlist<T>::creat()
{
        for(int j=0;j<maxsize;j++)
        {
        scanf("%d",&data[j]);
        currentlengeh++;
        }
        
}
template <class T>
seqlist<T>::seqlist(int const initsize)
{
    data=new T[initsize];
    maxsize=initsize;
    currentlengeh=0;
}
template <class T>
void seqlist<T>::remove(int i)
{
    /*下标越界异常抛出*/
    for(int j=i;j<currentlengeh;j++)
    data[j]=data[j+1];
    currentlengeh--;
}
template <class T>
void seqlist<T>::insert(int i,const T &b)
{   /*下标越界异常抛出*/
    if(currentlengeh=maxsize)
    doublespace();
    for(int j=currentlengeh;j>i;j--)
    data[j]=data[j-1];
    data[i]=b;
    currentlengeh++;
}
template <class T>
void seqlist<T>::doublespace(void)
{
    T *temp=data;
    maxsize*=2;
    data=new T[maxsize];
    for(int i=0;i<currentlengeh;i++)
    data[i]=temp[i];
    delete []temp;
}
template <class T>
int seqlist<T>::search(const T &a) const
{   int i;
    for(i=0;i<currentlengeh&&data[i]!=a;i++);
    if(i == currentlengeh) return -1;
    else 
    return i;
}
template <class T>
T seqlist<T>::visit(int i) const
{
    /*下标越界异常抛出*/
    return data[i];
}
template <class T>
void seqlist<T>::traverse(void) const
{
    for(int j=0;j<currentlengeh;j++)
    cout<<"a["<<j<<"]="<<data[j]<<" ";
}



/*双链表类定义*/
template <class T>
class linklist:public list<T>
{
    private:
    int currentlengeh;
    struct node
    {
        node *prev=NULL;
        node *next=NULL;
        T data;
        node(node *p,node *q,T x)
        {
            prev=p;
            next=q;
            data=x;
        }
        node():next(NULL),prev(NULL){}//什么意思？
        ~node(){ }
    };
    node *head=NULL;
    node *tail=NULL;
    node * move(int i) const
    {
        node *p=head->next;
        if(i<0||i>currentlengeh)
        throw outofbound();
        while(i--)
        p=p->next;
        return p;
    }   
    public:
    void clear(void);
    void insert(int i,const T &b);
    void remove(int i);//基类中的虚函数在子类中必须再次声明
    int search(const T &i) const;
    T visit(int i) const;
    void traverse(void) const;
    linklist(void);
    int length() const
    {
        return currentlengeh;
    }
    ~linklist()
    {
        clear();
        delete head;
        delete tail;
    }
};
template <class T>
linklist<T>::linklist()
{
    head =new node;
    head->next=tail=new node;
    tail->prev=head;
    currentlengeh=0;
}

template <class T>
void linklist<T>::clear(void)
{
    node *p=head->next,*q;
    head->next=tail;
    tail->prev=head;
    while(p!=tail)
    {
        q=p->next;
        delete p;
        p=q;
    }
    currentlengeh=0;
}

template <class T>
void linklist<T>::remove(int i)
{
    /*下标越界异常抛出*/
    node *p;
    p=move(i);
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
    currentlengeh--;
}

template <class T>
void linklist<T>::insert(int i,const T &b)
{   /*下标越界异常抛出*/
    node *p,*q;
    p=move(i);
    q=new node(p->prev,p,b);
    p->prev->next=q;
    p->prev=q;
    currentlengeh++;
}
template <class T>
int linklist<T>::search(const T &a) const
{   int i=0;
    node *p=head->next,*q;
    while(p->data!=a&&p->next!=tail)
    {
        p=p->next;
        i++;
    }
        
    if(p->next!=tail)
    return -1;
    else
    return i;
}
template <class T>
T linklist<T>::visit(int i) const
{
    /*下标越界异常抛出*/
    node *p=move(i);
    return p->data;
}
template <class T>
void linklist<T>::traverse(void) const
{
    node *p=head->next;
    while(p!=tail)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
#endif
