#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bus
{
    char agent[10];
    char nump[10];
    char from[10];
    char to[10];
    int fare;
    int s[9][5];
    struct bus *link1;
};
typedef struct bus *BUS;
BUS firstb=NULL;
BUS lastb=NULL;

void display()
{
    BUS temp1;
    temp1=firstb;
    if(temp1==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The buses are :\n");
    while(temp1 != NULL)
    {
        printf("---------------------\n");
        printf("\nAgent Name : %s \nBus Number : %s \nFrom : %s   => \t To: %s \nFare :%d\n",temp1->agent,temp1->nump,temp1->from,temp1->to,temp1->fare);
        printf("---------------------\n");
        temp1=temp1->link1;
    }
}

void insert()
{
    BUS temp;
    int i,j;
    temp=(BUS)malloc(sizeof(struct bus));
    printf("Enter the bus agent name :");
    scanf("%s",temp->agent);
    printf("Enter the bus number :");
    scanf("%s",temp->nump);
    printf("Enter from location of bus :");
    scanf("%s",temp->from);
    printf("Enter to location of bus :");
    scanf("%s",temp->to);
    printf("Enter to bus fare :");
    scanf("%d",&temp->fare);
    for(i=0;i<9;i++)
    {
        for(j=0;j<5;j++)
        {
            temp->s[i][j]=0;
        }

    }
    temp->link1=NULL;
    if(firstb==NULL)
    {
        firstb=temp;
        lastb=firstb;
        return;
    }
    else
    {
        lastb->link1=temp;
        lastb=temp;
    }
}
void search()
{
    BUS tp;
    tp=firstb;
    if(firstb==NULL)
    {
        printf("No buses available1\n");
        return;
    }
    char str[10];
    printf("Enter the from location\n");
    scanf("%s",str);
    char str1[10];
    printf("Enter the to location\n");
    scanf("%s",str1);

    if(tp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(tp!=NULL)
    {
        {int n;
        n=strcmp((str),(tp->from));
        if(n!=0)
        {
            tp=tp->link1;
        continue;
        }
        int n1;
        n1=strcmp((str1),(tp->to));
        if(n1!=0)
        {
            tp=tp->link1;
        continue;
        }
        printf("\nBus number :%s\nFrom location :%s=>\t To : %s\nBus fare : %d\n",tp->nump,tp->from,tp->to,tp->fare);}
    tp=tp->link1;
    }

}

void searchp()
{
    BUS cur;
    int n,count=1;
    char str[10];
    printf("Enter the number of bus\n");
    scanf("%s",str);
    if(firstb==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=firstb;
    while(cur!=NULL)
    {
        n=strcmp((str),(cur->nump));
        if(n==0)
        break;
        cur=cur->link1;
        count++;
    }
    if(cur==NULL)
    {
        printf("Search unsuccesful\n");
        return;
    }
    printf("\nAgent Name : %s \nBus Number : %s \nFrom : %s   => \t To: %s \nFare :%d\n",cur->agent,cur->nump,cur->from,cur->to,cur->fare);
}

void displayagain()
{
    BUS cur;
    int n,count=1;
    int i,j;
    char str[10];
    printf("Enter the number of bus of which seats are to displayed\n");
    scanf("%s",str);
    printf("\n0 stands for unbooked\n1 stands for booked\n");
    if(firstb==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=firstb;
    while(cur!=NULL)
    {
        n=strcmp((str),(cur->nump));
        if(n==0)
        break;
        cur=cur->link1;
        count++;
    }
    if(cur==NULL)
    {
        printf("Search unsuccesful\n");
        return;
    }
    printf("\n\nSeats are\n\t");
    printf("   1  2  3  4  5\n\n  ");
    for(i=0;i<9;i++)
    {
        printf("\t%d",i+1);
        for(j=0;j<5;j++)
        {
            printf("%3d",cur->s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void issue()
{
    BUS cur;
    int n,count=1;
    int i,j;
    char str[10];
    printf("Enter the number of bus of which seats are to displayed\n");
    scanf("%s",str);
    printf("\n0 stands for unbooked\n1 stands for booked\n");
    if(firstb==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=firstb;
    while(cur!=NULL)
    {
        n=strcmp((str),(cur->nump));
        if(n==0)
        break;
        cur=cur->link1;
        count++;
    }
    if(cur==NULL)
    {
        printf("Search unsuccesful\n");
        return;
    }
    printf("\n\nSeats are\n\t");
    printf("   1  2  3  4  5\n\n  ");
    for(i=0;i<9;i++)
    {
        printf("\t%d",i+1);
        for(j=0;j<5;j++)
        {
            printf("%3d",cur->s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter the row number at which the seat has to be booked\n");
    scanf("%d",&i);
    printf("Enter the column number at which the seat has to be booked\n");
    scanf("%d",&j);
    i--;
    j--;
    if(cur->s[i][j]==1)
    {
        printf("Seat is already booked\n");
        return;
    }
    cur->s[i][j]=1;
    printf("\n\nSeats are\n\t");
    printf("   1  2  3  4  5\n\n  ");
    for(i=0;i<9;i++)
    {
        printf("\t%d",i+1);
        for(j=0;j<5;j++)
        {
            printf("%3d",cur->s[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int ch;
    while(1)
    {
        printf("\n\n\n~~~MAIN MENU~~~\n");
        printf("1.Insert bus information\n");
        printf("2.Display all buses\n");
        printf("3.Available bus one a particular route\n");
        printf("4.Display information of particular bus\n");
        printf("5.Book a seat in a particular bus\n");
        printf("6.Display available seats\n");
        printf("7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:insert();
            break;
        case 2:display();
            break;
        case 3:search();
            break;
        case 4:searchp();
            break;
        case 5: issue();
            break;
        case 6:displayagain();
            break;
        case 7:exit(1);
            break;
            default : printf("Enter valid choice");
        }
    }
}
