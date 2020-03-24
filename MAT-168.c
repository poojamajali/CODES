/*****************************************************
                         MAT CHALLENGE
             Data Structures and Algorithms
                    19ECSC201
#+Name:POOJA MAJALI
#+Roll:1168
#+SRN:01FE18BCS143
#+Email:poojamajali@gmail.com
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>



/**MAT TABLE structure contains the starting and ending address of each memory chuck requested.
   MAT TABLE is a linked list as nodes have to be deleted during the free function.
**/
struct node
{
    char *start;
    char *end;
    int size;
    int no;
    struct node *next;
};

typedef struct node node;

/**function declaration**/
void deleteAnynode(int ch);
node * getdata(char *start,node *nw);
void my_malloc();
void addnode(node *nw);
void view_mat();

/**GLOBAL declaration of first pointer of linked list**/
node *first=NULL;
char *temp;
char *ptr;


/**
1. My malloc function asks no of bytes required and user no.It allocates given no of bytes in the main pointer requested
   from the heap and saves the starting and ending address in the node.
2. When requested again, new node will be added to the list.
**/

void my_malloc()
{
    int bytes,j;
    char *cur,*tem;
    node *nw;

    nw=(node *)malloc(sizeof(node));
    nw->next=NULL;

    printf("\nEnter the user no: ");
    scanf("%d",&nw->no);

    printf("\nEnter no of bytes of memory required ");
    scanf("%d",&bytes);
    nw->size=bytes;


    /**assigning start and end pointer in the heap.temp pointer maintains the last address used**/
    nw->start=temp;
    cur=temp;
    cur=cur+bytes-1;

    /**checks if memory is available**/
    if(temp==cur)
        printf("\nMEMORY NOT AVAILABLE");

    nw->end=cur;
    printf("\n%u to %u\n",temp,cur);
    temp=nw->end+1;
    /**adding nodes to the list**/
    addnode(nw);
    /**add data in the memory space allocated**/
    getdata(nw->start,nw);

}



/**adding nodes to the list**/
void addnode(node *nw)
{
    node *prev;
    if(first==NULL)
    {
        first=nw;
    }
    else
    {
        for(prev=first;prev->next!=NULL;prev=prev->next);
        prev->next=nw;
    }
}

/**Get data from the user**/
node * getdata(char *start,node *nw)
{
    printf("\nenter data of %d letters: ",nw->size-1);
    scanf("%s",nw->start);
    return nw;
}

/**reallocating the memory for using memory efficiently**/
void reallocate()
{
    node *cur;
    temp=ptr;
    int j;
    char *p;
    char s[1000];
    for(cur=first;cur!=NULL;cur=cur->next)
    {

        strcpy(cur->start,temp);
        cur->start=temp;
        for(p=temp,j=1;j<cur->size;j++,p++);
        cur->end=p;
        temp=cur->end+1;


    }
    printf("\n********REALLOCATED********");
    view_mat();
}


/**
my_free function asks the user which number to be deleted and calls the delete_any_node function.

**/

void my_free()
{
    int ch;
    printf("\nEnter the user no to be deleted");
    scanf("%d",&ch);
    deleteAnynode(ch);

}
void deleteAnynode(int ch)
{
    struct node *cur,*prev;
    for(prev=NULL,cur=first;cur!=NULL && cur->no!=ch;prev=cur,cur=cur->next);

    if(cur==NULL)
        printf("\n MEMORY NOT FOUND");
    else
    {
        printf("\ndeleted memory:");
        printf("\nUSER:%d   BYTES:%d  ADDRESS:%u  to %u\n",cur->no,cur->size,cur->start,cur->end);
        if(cur==first)
            first=first->next;
        else
            prev->next=cur->next;
        free(cur);
    }

};


/**As MAT TABLE  is a linked list, this function prints all the nodes in the linked list**/

void view_mat()
{
    node *cur;
    cur=first;
       if(first==NULL)
            printf("\n MAT TABLE EMPTY");
       else
       {
           printf("\n*********** MAT TABLE ************");
           printf("\nUSER\tBYTES\tSTART ADDRESS\tEND ADDRESS\tDATA");
           while(cur!=NULL)
           {
               printf("\n%d\t%d\t%u\t%u\t%s",cur->no,cur->size,cur->start,cur->end,cur->start);
               cur=cur->next;
               printf("\n");
           }
       }

}



int main()
{
    /**memory allocation of 100 MB**/
    ptr=(char *)malloc(100*1024*1024*sizeof(char));
    printf("pointer staring: %u\n",ptr);
    temp=ptr;
    int ch;

    do
    {
        printf("\n1:MEMORY ALLOCATION   2:FREE MEMORY 3:VIEW MAT TABLE 4:REALLOCATE 5:BREAK  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: my_malloc();
                    break;

            case 2: my_free();
                    break;

            case 3: view_mat();
                    break;

            case 4:reallocate();
                   break;

            case 5: break;
        }

    }while(ch!=5);
    return 0;

}

