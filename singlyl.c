#include<stdio.h>
#include<stdlib.h>
void insfrnt();
void insend();
void insmid();
void delfrnt();
void dellast();
void delran();
void search();
void display();
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void main()
{
	int opt;
	while(1)
	{
		printf("\nLinked list operations are:\n");
		printf("1.Insert at front\n2.Insert at end\n3.Insert in between");
		printf("\n4.Delete from front\n5.Delete from end\n6.Delete Random\n7.Display\n8.Search\n");
		printf("9.Exit\n");
		printf("Select operation:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				insfrnt();
				break;
			case 2:
				insend();
				break;
			case 3:
				insmid();
				break;
			case 4:
				delfrnt();
				break;
			case 5:
				dellast();
				break;
			case 6:
				delran();
				break;
			case 7:
				display();
				break;
			case 8:
				search();
				break;
			case 9:
				exit(0);
		}
	}
}
void insfrnt()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("Enter item:");
	scanf("%d",&item);
	ptr->data=item;
	ptr->next=head;
	head=ptr;
	printf("\nNode Inserted");

}
void insend()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("Enter item:");
	scanf("%d",&item);
	ptr->data=item;
	if(head==NULL)
	{
		ptr->next=NULL;
		head=ptr;
		printf("\nNode Inserted");
	}
	else
	{
		
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
		printf("\nNode Inserted");
	}
}
void insmid()
{
	int i,loc,item;
	struct node *ptr, *temp;  
	ptr = (struct node *) malloc (sizeof(struct node));  
	printf("\nEnter element value");  
	scanf("%d",&item);  
	ptr->data = item;  
	printf("\nEnter the location of node to insert after:");  
	scanf("\n%d",&loc);  
	temp=head;  
	for(i=0;i<loc;i++)  
	{  
	    temp = temp->next;  
	    if(temp == NULL)  
	    {  
	        printf("\nCan't Insert\n");  
	        return;  
	    }  
	}  
	ptr ->next = temp ->next;   
	temp ->next = ptr;   
	printf("\nNode inserted");     
}
void delfrnt()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining.\n");  
    }  
}  
void dellast()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted.\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last.\n");  
    }     
}  
void delran()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\nEnter the location of the node to delete:");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search:");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("Item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
}          
void display()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
	{  
		printf("Nothing to print.\n");  
	}  
	else  
	{  
		printf("\n\nList elements are -\n");
		while(ptr != NULL) 
		{
		  printf("%d ---> ",ptr->data);
		  ptr = ptr->next;
		}
		printf(" NULL\n");
	}
}b+
