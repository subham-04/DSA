#include <stdio.h>
#include<stdlib.h>

void linkedlistTraversal();
void createLinkedlist();
void insertAtBeginning();
void countNumberofNodes();
void insertAtNode();
void insertAtEnd();


struct Node{
    int data;
    struct Node* next;
}*head;



int main(){

   
    int option=0;
    printf("\n\n\t\t**********Creating linkedlist**********\n");
        
        
        while(1){
            printf("\n\n\t\t1. Create Linkedlist\n");
            printf("\n\t\t2. Insert Element At The Beginning Of A Linkedlist\n");
            printf("\n\t\t3. Insert Element At The Node\n");
            printf("\n\t\t4. Insert Element At The End\n");
            printf("\n\t\t5. Count The Number Of Nodes In A Linkedlist\n");
            printf("\n\t\t6. Show Linkedlist\n");
            printf("\n\t\t7. Exit Program\n\n\t--> ");
            scanf("%d",&option);

            if (option==1){
                createLinkedlist();
            }
            else if(option==2){
                insertAtBeginning();
            }
            else if(option==3){
                insertAtNode();
            }
            else if(option==4){
                insertAtEnd();
            }
            else if(option==5){
                countNumberofNodes();
            }
            else if(option==6){
                linkedlistTraversal();
            }
            else if(option==7){
                printf("\n\\tExiting Programm................\n");
                break;
            }
        
        }
        
    return 0;
    }

void countNumberofNodes(){
    struct Node *ptr;
    ptr=head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("\nNumber of Nodes available Here : %d",count);
}
void insertAtBeginning(){

    struct Node * ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    printf("\n\t\t******Inserting at the Beginning******\t\t\n\nEnter the element : ");
    scanf("%d",&(ptr->data));
    ptr->next=head;
    head=ptr;

}

void insertAtNode(){
    int index;
    printf("\n\t\t******Inserting at the Node******\t\t\n\nEnter the node : ");
    scanf("%d",&index);
    struct Node * ptr,*p;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    p=(struct Node *)malloc(sizeof(struct Node));
    p=head;
    int count=1;
    while(count!=index-1){
        p=p->next;
        count++;
    }
    printf("\nEnter element : ");
    scanf("%d",&(ptr->data));
    ptr->next=p->next;
    p->next=ptr;

}



void insertAtEnd(){

    printf("\n\t\t******Inserting at the End******\n\n");
    struct Node *ptr,*p;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    p=(struct Node *)malloc(sizeof(struct Node));
    p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    printf("\nEnter element : ");
    scanf("%d",&(ptr->data));
    
    ptr->next=p->next;
    p->next=ptr;
}


void linkedlistTraversal(){

    struct Node *ptr=head;
    int i=1;

    if(head==NULL){
        printf("\nList is empty\n");
    }

    printf("\nShowing Data........\n\n");
    while(ptr != NULL){
        printf("Data at %d: %d\n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}

void createLinkedlist(){

    struct Node *newnode, *temp;
    int n,data,i=1;

    head=(struct Node*)malloc(sizeof(struct Node));

    if(head==NULL){ //Terminates  if memory is not allocated
        printf("\nUnable to locate memory.\n");
        exit(0);
    }
    printf("\nHow many nodes you want to create? \n");
    scanf("%d",&n);
    //Strats taking user input
    printf("\nInput data for Node %d: ",i);
    scanf("%d",&(head->data));
    head->next=NULL;
    temp=head;

    //Taking user input in loop for n-1 times
    for(i=2;i<=n;i++){

        newnode=(struct Node*)malloc(sizeof(struct Node));

        if(newnode==NULL){ //Terminates  if memory is not allocated
            printf("\nUnable to locate memory.\n");
            break;
        }

        printf("\nInput data for Node %d: ",i);
        scanf("%d",&(newnode->data));
        newnode->next=NULL;

        temp->next=newnode;
        temp=temp->next;
        
    }
    

}
