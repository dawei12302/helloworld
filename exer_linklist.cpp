#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include "mylist.h"
using namespace std;
int main()
{
    int temp1,temp2;
    bool interface0_flag=1;
    int ch;
    linklist<int> linklist1;
    while(1)
    {   
         if(interface0_flag==1)
        {   
            cout<<endl;
            cout<<"1.清除链表"<<endl;
            cout<<"2.插入一个元素"<<endl;
            cout<<"3.删除一个元素"<<endl;
            cout<<"4.查看当前链表长度"<<endl;
            cout<<"5.查看某个元素"<<endl;
            cout<<"6.查看所有元素"<<endl;
            interface0_flag=0;
        }
        if (_kbhit())//如果有按键按下，则_kbhit()函数返回真
        {
            
            ch = _getch();
            switch (ch)
            {
            case 49://1
            { 
                cout<<"1.清除链表"<<endl;
                linklist1.clear();
                interface0_flag=1;
                break;
                
            } 

            case 50://2
            {
                cout<<"2.插入一个元素"<<endl;
                cout<<"请输入插入位置（从0开始:";
                scanf("%d",&temp1);
                cout<<"请输入插入元素的值:";
                scanf("%d",&temp2);
                linklist1.insert(temp1,temp2);
                interface0_flag=1;
                break;
            }
            
            case 51://3
            {
                cout<<"3.删除一个元素"<<endl;
                cout<<"请输入删除位置:";
                scanf("%d",&temp1);
                linklist1.remove(temp1);
                interface0_flag=1;
                break;
            }
            
             case 52://4
            {
                cout<<"4.查看当前链表长度"<<endl;
                temp1=linklist1.length();
                cout<<"线性表当前长度是："<<temp1<<endl;
                interface0_flag=1;
                break;
            }

            case 53://5
            {
                cout<<"5.查看某个元素"<<endl;
                cout<<"请输入要访问的元素下标："<<endl;
                scanf("%d",&temp1);
                cout<<"访问元素是："<<linklist1.visit(temp1)<<endl;
                interface0_flag=1;
                break;
            }    
                
            case 54://6
            {
                cout<<"6.查看所有元素"<<endl;
                linklist1.traverse();
                interface0_flag=1;
                break;
            }     
            default:
            interface0_flag=1;
                break;
            }
        }
    }
    return 0;
}
