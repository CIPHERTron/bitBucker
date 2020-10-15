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
        cout<"\nNo Elements in the list\n";
        return;
    }
    Node* p=head;
    cout<<"The Elements in the list are: ";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

Node* Search(Node* head,char key)
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return NULL;
    }
    Node* p=head;
    while(p!=NULL)
    {
        if(p->data==key)
            return p;
        else
            p=p->next;
    }
    //outside the loop if the key is not found return NULL
    return NULL;
}

Node* InsertAtBegin(Node* head,char key)
{
    //creating new node
    Node* temp=new Node;
    temp->data=key;
    temp->next=NULL;

    //setting the new node's next link as head
    temp->next=head;
    head=temp;
    return head;

}

void InsertAfterLOC(Node* LOC,char item)
{
    Node* temp=new Node;
    temp->data=item;
    temp->next=NULL;

    temp->next=LOC->next;
    LOC->next=temp;
}

Node* Insert(Node* head,char item,char key)
{
    Node* LOC=Search(head,key);
    if(LOC==NULL)
    {
        cout<<"Given Key not found and now Inserting at the beginning:\n";
        head=InsertAtBegin(head,item);
    }
    else
    {
        cout<<"Given Key is found and inserting item after the first occurance of key\n";
        InsertAfterLOC(LOC,item);
    }
    return head;
}

Node* DeleteFirstOccurence(Node* head,char key)
{
    if(head==NULL)
    {
        cout<<"\nEmpty List\n";
        return NULL;
    }
    Node* keyptr=Search(head,key);
    if(keyptr==NULL)
    {
        cout<<"Given Key to be deleted is not found in the list\n";
    }
    else//we found the key element
    {
        //head node itself contain the first key ooccurence
        if(keyptr==head)
        {
            head=head->next;
            delete keyptr;
        }
        else//other node contain the key element
        {
            //a tail pointer pointing to the previous node of the key element
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

Node* DeleteAllOccurence(Node* head,char key)
{
    if(head==NULL)
    {
        cout<<"\nEmpty List\n";
        return NULL;
    }
    //operate DeleteFirstOccurence function till no key element left
    //in otherwords we have to operate till we our search function returns NULL
    while(Search(head,key)!=NULL)
    {
        head=DeleteFirstOccurence(head,key);
    }
    return head;
}




int main()
{
   Node* head=NULL;
   cout<<"Empty Linked List is created\n";

   //Insertion
   cout<<"Enter how many nodes you want to insert : ";
   int n;
   char key;
   char item;
   cin>>n;
   while(n--)
   {
       cout<<"\nEnter the Character to insert: ";
       cin>>item;
       cout<<"Enter key character after which you want to insert the item : ";
       cin>>key;
       head=Insert(head,item,key);
       PrintList(head);
   }


   //Deleting
   cout<<"\n 1 .for delete first occurance\n";
   cout<<" 2 .for delete all occurance\n";
   cout<<" 0 .for Terminate this process\n";

   do
   {
       cout<<"\nEnter the key Character to delete: ";
       cin>>key;
        cout<<"\nEnter the number for action(1/2/0) : ";
        cin>>n;
       if(n==1)
        {
           head=DeleteFirstOccurence(head,key);
           PrintList(head);
        }
       else if(n==2)
        {
           head=DeleteAllOccurence(head,key);
           PrintList(head);
        }
   }while(n!=0);

    return 0;
}
