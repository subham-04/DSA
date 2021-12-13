#include <stdio.h>
#include<stdlib.h>

void linkedlistTraversal();
void createLinkedlist();
void insertAtBeginning();
void countNumberofNodes();
void insertAtNode();
void insertAtEnd();
void deleteFirstNode();
void deleteAtNode();
void deleteAtEnd();
void deleteGivenValue();


struct Node{
    int data;
    struct Node* next;
}*head;



int main(){

   
    int option=0;
    printf("\n\n\t\t**********Creating linkedlist**********\n");
        
       
        while(1){
            printf("\n\n\t\t1. Create Linkedlist\n");
            printf("\n\t\t2. Insertion\n");
            printf("\n\t\t3. Deletion\n");
            printf("\n\t\t4. Count The Number Of Nodes In A Linkedlist\n");
            printf("\n\t\t5. Show Linkedlist\n");
            printf("\n\t\t6. Exit Program\n\n\t--> ");
            scanf("%d",&option);

            if (option==1){
                createLinkedlist();
            }
            else if(option==2){

                printf("\n\t\t1. Insert Element At The Beginning Of A Linkedlist\n");
                printf("\n\t\t2. Insert Element At The Node\n");
                printf("\n\t\t3. Insert Element At The End\n\n\t--> ");
                scanf("%d",&option);
                if (option==1){
                    insertAtBeginning();
                }
                else if(option==2){
                    insertAtNode();
                }
                else if(option==2){
                    insertAtEnd();
                }
            }
            else if(option==3){
                
                printf("\n\t\t1. Delete The First Element Of A Linkedlist\n");
                printf("\n\t\t2. Delete A Node\n");
                printf("\n\t\t3. Delete The Last Element\n");
                printf("\n\t\t4. Delete A Value(Works for first element only)\n\n\t--> ");
                scanf("%d",&option);
                if (option==1){
                    deleteFirstNode();
                }
                else if(option==2){
                    deleteAtNode();
                }
                else if(option==3){
                    deleteAtEnd();
                }
                else if(option==4){
                    deleteGivenValue();
                }
            }
            else if(option==4){
                countNumberofNodes();
            }
            else if(option==5){
                linkedlistTraversal();
            }
            else if(option==6){
                printf("\n\tExiting Programm................\n");
                break;
            }
            
        
        }
        
    return 0;
    }

void deleteFirstNode(){

    printf("\n\t\t******Deleting the First Node******\n\n");
    struct Node *ptr =head;
    head=head->next;
    free(ptr);

}

void deleteAtNode(){

    printf("\n\t\t******Delete at the Node******\n\nEnter the node : ");
    int index;
    scanf("%d",&index);
    struct Node* ptr =head;
    struct Node * temp=head->next;
    for(int i=0; i<index-1; i++){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);

}



void deleteAtEnd(){

    printf("\n\t\t******Deleting the Last Node******\n\n");
    struct Node * ptr =head;
    struct Node * temp =head->next;

    while(temp->next!=NULL){
        temp=temp->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(temp);

}


void deleteGivenValue(){

    printf("\n\t\t******Delete a Value******\n\nEnter the value : ");
    int value;
    scanf("%d",&value);
    struct Node* ptr =head;
    struct Node * temp=head->next;
    while(temp->data!=value && temp!=NULL){        
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);

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
