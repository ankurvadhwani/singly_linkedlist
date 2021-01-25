/*
        singly linked list insert program : start , end , at specific position
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int i;
    struct node *next;
};
struct node *head=NULL;
int totalnodes;

void insertAtFirst(int val){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->i=val;
    n->next=NULL;
    if(head==NULL){
        head=n;
    }else{
        n->next=head;
        head=n;
    }
    count();
}
void insertAtEnd(int val){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->i=val;
    n->next=NULL;
    if(head==NULL){
        head=n;
    }else{
        struct node *tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=n;
    }
    count();

}
void insertAtPos(int pos,int val){
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->i=val;
    n->next=NULL;
    if(head==NULL){
        head=n;
    }else{
        if(totalnodes<pos){
            printf("entered is out of linkedlink range \n");
        }else{
            struct node *tmp=head;
            int i;
            for(i=0;i<pos-1;i++)
            {
                tmp=tmp->next;
            }
            n->next=tmp->next;
            tmp->next=n;
        }
    }
    count();
}
void count(){
    struct node *tmp=head;
    totalnodes=0;
    while(tmp!=NULL){
        totalnodes+=1;
        tmp=tmp->next;
    }
}

void display(){
    struct node *tmp=head;
    while(tmp!=NULL){
        printf("[%d | %d]\n",tmp->i,tmp->next);
        tmp=tmp->next;
    }

}
int main(){
    int run=1;
    int selector,value,pos;
    do{
        printf("---------------[currently %d nodes available in linkedlist]----------------\n",totalnodes);
        printf("1:insert as First node\n");
        printf("2:insert as Last node\n");
        printf("3:insert at specific position\n");
        printf("4:display all nodes\n");
        printf("5:exit\n");
        scanf("%d",&selector);
        switch(selector){
        case 1:
            printf("enter value for new node : ");
            scanf("%d",&value);
            insertAtFirst(value);
            break;
        case 2:
            printf("enter value for new node : ");
            scanf("%d",&value);
            insertAtEnd(value);
            break;
        case 3:
            printf("enter value for new node : ");
            scanf("%d",&value);
            printf("\n enter position : ");
            scanf("%d",&pos);
            insertAtPos(pos,value);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("press correct number\n");
        }
        printf("press '1' to continue : ");
        scanf("%d",&run);
        system("CLS");
    }while(run);
}
