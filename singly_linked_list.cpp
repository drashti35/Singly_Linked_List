//singly linked list create,insert and delete operations
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node *start=NULL;
node *rear=NULL;
node *create(node *start)
{
    node *new_node;
    int num;
    cout<<"Enter -1 to end:";
    cout<<"Enter the value:";
    cin>>num;
    while(num!=-1)
    {
        new_node=new node();
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
            rear=new_node;
        }
        else
        {
            rear->next=new_node;
            new_node->next=NULL;
            rear=new_node;
        }
        cout<<"Enter the value:";
        cin>>num;
    }
    return start;
}
void display(node *start)
{
    node *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->data;
    }
}
node *insert_beg(node *start)
{
    node *new_node;
    int num;
    cout<<"Enter the value:";
    cin>>num;
    new_node=new node();
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}
node *insert_end(node *start)
{
    node *new_node;
    int num;
    cout<<"Enter the value:";
    cin>>num;
    new_node=new node();
    new_node->data=num;
    node *ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=NULL;
    return start;
}
node *insert_after_node(node *start)
{
    node *new_node;
    int num,val;
    cout<<"Enter the value:";
    cin>>num;
    cout<<"After which node you want to insert a new node?";
    cin>>val;
    node *ptr,*preptr;
    new_node=new node();
    new_node->data=num;
    ptr=start;
    preptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    preptr->next=new_node;
    return start;
}
node *delete_beg(node *start)
{
    node *ptr;
    ptr=start;
    if(start==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
    return start;
}
node *delete_end(node *start)
{
    node *ptr,*preptr;
    ptr=start;
    if(start==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    }
    return start;
}
node *delete_after_node(node *start)
{
    node *ptr,*preptr;
    int val;
    cout<<"After which node you want to delete?";
    cin>>val;
    ptr=start;
    if(start==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        while(preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start;
}
int main()
{
    int ch;
    do
    {
        cout<<"Enter the choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
        start=create(start);
        break;
        case 2:
        display(start);
        break;
        case 3:
        start=insert_beg(start);
        break;
        case 4:
        start=insert_end(start);
        break;
        case 5:
        start=insert_after_node(start);
        break;
        case 6:
        start=delete_beg(start);
        break;
        case 7:
        start=delete_end(start);
        break;
        case 8:
        start=delete_after_node(start);
        break;
        }
    }
    while(ch!=9);
    return 0;
}