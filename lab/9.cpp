#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5
int pqueue[MAX];
class pq
{
public:
int front, rear;
void inserting(int);
void deleting(int);
void create();
void check(int);
void display();
};
int main()
{
pq obj;
int n,ch;
cout<<"1.Insert an element into queue"<<endl;
cout<<"2.Delete an element from queue"<<endl;
cout<<"3.Display queue elements"<<endl;
cout<<"4.Exit"<<endl;
obj.create();
while (1)
    {
cout<<"Enter your choice"<<endl;;
cin>>ch;
switch (ch)
        {
case 1:
cout<<"Enter value to be inserted"<<endl;
cin>>n;
obj.inserting(n);
break;
case 2:
cout<<"\nEnter value to delete"<<endl;
cin>>n;
obj.deleting(n);
break;
case 3:
obj.display();
break;
case 4:
exit(0);
        }
    }
}
void pq::create()
{
front = rear = -1;
}
void pq::inserting(int data)
{
if (rear >= MAX - 1)
    {
cout<<"overflow"<<endl;
return;
    }
if ((front == -1) && (rear == -1))
    {
front++;
rear++;
pqueue[rear] = data;
return;
    }
else
check(data);
rear++;
}
void pq::check(int data)
{
int i,j;
for (i = 0; i <= rear; i++)
    {
if (data >= pqueue[i])
        {
for (j = rear + 1; j > i; j--)
            {
pqueue[j] = pqueue[j - 1];
            }
pqueue[i] = data;
return;
        }
    }
pqueue[i] = data;
}
void pq::deleting(int data)
{
int i;
if ((front==-1) && (rear==-1))
    {
cout<<"\nEmpty queue"<<endl;
return;
    }
for (i = 0; i <= rear; i++)
    {
if (data == pqueue[i]){
for (; i < rear; i++){
pqueue[i] = pqueue[i + 1];
            }
pqueue[i] = -99;
rear--;
if (rear == -1)
front = -1;
return;
        } }
cout<<data<<"not found"<<endl;
}
void pq::display(){
if ((front == -1) && (rear == -1))
    {
cout<<"\nQueue is empty";
return;
    }
for (; front <= rear; front++)
    {
cout<<pqueue[front];
    }
front = 0;
}

