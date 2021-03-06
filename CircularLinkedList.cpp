#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *insert(Node *head,int x)		//Insert function
{
    Node *temp=new Node;
    temp->data=x;
    temp->next=head;

    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else{
        Node *t=head;

        while(t->next!=head){
            t=t->next;
        }

        t->next=temp;

    }
    return head;

}

void print(Node *head){			 //Print function
    if(head==NULL)
        return;
    Node *t=head;
    while(t->next!=head){
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<t->data<<"->";

}

Node *insertFront(Node *head,int x){	 //Insert at front

    Node *temp=new Node;
    temp->data=x;
    temp->next=head;

    if(head==NULL){
        return temp;
    }
    Node *t=head;
    while(t->next!=head){
        t=t->next;
    }

    t->next=temp;
    return temp;
}

Node *insertPos(Node *head,int pos,int x){  //Insert at given position
    if(head==NULL){
        cout<<"No node present";
        return head;
    }
    Node *temp=new Node();
    temp->data=x;
    temp->next=head;

    Node *prntnode=head;
    if(pos==1){
        head=insertFront(head,x);
    }else{
        Node *t=head->next;

        while(--pos!=1){

            if(t==head){
                cout<<"No. no node is less then postion you entered";
                return head;
            }

            t=t->next;
            prntnode=prntnode->next;

        }

        prntnode->next=temp;
        temp->next=t;

    }
    return head;
}

void *dlt(Node **head_ref,int pos){		//Delete node

    Node *t=*head_ref,*prev;

    if(pos==1 && t!=NULL){
        Node *temp=t;
        *head_ref=t->next;

        while(t->next!=temp){
            t=t->next;
        }
        t->next=*head_ref;
        free(temp);

    }
    else{
        while(pos--!=1 && t->next!=*head_ref){
            prev=t;
            t=t->next;
        }

        if(t!=*head_ref){
            Node *temp=t;
            prev->next=t->next;
            free(temp);

        }

    }
}

int main()
{

    Node *head=new Node();
    head=NULL;
    int choice=0,pos=0;

    int NodeCount=0;
    do{
        cout<<endl<<endl<<"Select your choice"<<endl;
        cout<<"Press 1 for insert at end of link"<<endl;
        cout<<"Press 2 for insert at front of link"<<endl;
        cout<<"Press 3 for insert at any position of link"<<endl;
        cout<<"Press 4 for delete last node"<<endl;
        cout<<"Press 5 for delete first node"<<endl;
        cout<<"Press 6 for delete positioning node"<<endl;
        cout<<"Press 11 for print link"<<endl;
        cout<<"Press 0 for exit"<<endl<<endl;;

        cin>>choice;
        switch(choice){

            case 1: cout<<"Enter value to insert: ";
                int value;
                cin>>value;
                head=insert(head,value);
                ++NodeCount;
                break;

            case 2: cout<<"Enter value to insert: ";
                cin>>value;
                head=insertFront(head,value);
                ++NodeCount;
                break;

            case 3: cout<<"Enter value to insert: ";
                cin>>value;
                cout<<"Enter postion: ";
                cin>>pos;
                head=insertPos(head,pos,value);
                ++NodeCount;
                break;

            case 4:  dlt(&head,NodeCount);
                --NodeCount;
                print(head);
                break;

            case 5: dlt(&head,1);
                --NodeCount;
                print(head);
                break;

            case 6: cout<<"Enter position for delete: ";
                int po;
                cin>>po;
                if(NodeCount<po)
                    cout<<"Wrong entry\n";
                else
                    dlt(&head,po);
                print(head);
                --NodeCount;
                break;
            case 11: print(head);
                break;
        }
    }while(choice!=0);

    return 0;
}