#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void PrintList(Node* head)
{
    if(head==NULL)
    {
        
        return;
    }
    Node* p=head;
    
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

    cout<<"\n";
}

Node* Search(Node* head,char key)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* p=head;
    do
    {
        if(p->data==key)
            return p;
        else
            p=p->next;
    }while(p!=head);

    
    return NULL;
}

Node* InsertAtBegin(Node* head,char key)
{
   
    Node* temp=new Node;
    temp->data=key;
    temp->next=NULL;

   
    if(head==NULL)
    {
        head=temp;
        head->next=head;
        return head;
    }

   
    Node* p=head;
    while(p->next!=head)
    {
        p=p->next;
    }

    temp->next=head;
    p->next=temp;

    head=temp;
    return head;

}

Node* Insert(Node* head,char item,char key)
{
    Node* LOC=Search(head,key);
    if(LOC==NULL)
    {
        head=InsertAtBegin(head,item);
    }
    
    return head;
}

Node* DeleteFirstOccurence(Node* head,char key)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* keyptr=Search(head,key);
    if(keyptr==NULL)
    {
        cout<<"Given Key to be deleted is not found in the list\n";
    }
    else
    {
       
        if(keyptr==head)
        {
           
            if(head->next==head)
            {
                delete keyptr;
                head=NULL;
            }
            else
            {
                
                Node* p=head;
                while(p->next!=head)
                {
                    p=p->next;
                }
                p->next=head->next;
                head=head->next;
                delete keyptr;
            }
        }
        else
        {
            
            Node* tailptr=head;
            while(tailptr->next!=keyptr)
            {
                tailptr=tailptr->next;
            }
            tailptr->next=keyptr->next;
            delete keyptr;
        }
    }
    return head;
}




int main()
{
    Node* head=NULL;
   
   
     char key;
     char item;
       cin>>item;
       cin>>key;
       head=Insert(head,item,key);
       PrintList(head);
   
     head=DeleteFirstOccurence(head,key);
     PrintList(head);
    return 0;
}
