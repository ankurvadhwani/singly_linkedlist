/*
    deleteion in singly linked list with 3 operation
    1. delete first node  2. delete last node    3. delete specific node
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int i;
    struct node *next;
};

struct node *head=NULL;
int totalnodes=0;

void generateNodes(){                                               // generate nodes using insert as first node
    head=NULL;
    int i;
    for(i=1;i<=5;i++){
        struct node *n=(struct node *) malloc(sizeof(struct node));
        n->i=i*5;
        n->next=NULL;
        if(head == NULL){
            head=n;
        }else{
            n->next=head;
            head=n;
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
void deleteFirstNode(){
    struct node *tmp=head;
    head=head->next;
    free(tmp);
    count();
    printf("node deleted successfully\n");
}
void deleteLastNode(){
    struct node *tmp=head;
    while(tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }
    free(tmp->next);
    tmp->next=NULL;
    count();
    printf("node deleted successfully\n");
}
void deleteSpecNode(int pos){
    if(pos==0){
        deleteFirstNode();
    }else if(pos==totalnodes)
    {
        deleteLastNode();
    }else if(pos>totalnodes-1){
        printf("Entered node no. is out of range\n");
    }else{
        struct node *t1=head;
        struct node *t2;
        int i;
        for(i=1;i<pos;i++)
        {
            t1=t1->next;
        }
        t2=t1->next;
        t1->next=t2->next;
        free(t2);
        printf("node deleted successfully\n");

    }
}
void display(){
    struct node *tmp=head;
    while(tmp!=NULL){
        printf("[%d|%d]\t",tmp->i,tmp->next);
        tmp=tmp->next;
    }
    printf("\n");
}

int main(){
     int run=1;
    int selector,pos;
    generateNodes();
    do{
        printf("---------------[currently %d nodes available in linkedlist]----------------\n",totalnodes);
        display();
        printf("---------------------------------------------------------------------------\n");
        printf("1:delete First node\n");
        printf("2:delete Last node\n");
        printf("3:delete specific node\n");
        printf("4:reset linked list with nodes\n");
        printf("5:exit\n");
        scanf("%d",&selector);
        switch(selector){
        case 1:
            deleteFirstNode();
            break;
        case 2:
            deleteLastNode();
            break;
        case 3:
            printf("\n enter node index to delete : ");
            scanf("%d",&pos);
            deleteSpecNode(pos);
            break;
        case 5:
            exit(0);
            break;
        case 4:
            generateNodes();
            break;
        default:
            printf("press correct number\n");
        }
        printf("press '1' to continue : ");
        scanf("%d",&run);
        system("CLS");
    }while(run);

return 0;
}
