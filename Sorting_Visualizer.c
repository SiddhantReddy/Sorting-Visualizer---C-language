#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h> 

#define MAX 20
int arr[MAX];
int i,j,size,m,n,k;
  
void delay(float number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    float milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void generate()
{
    size=MAX;
    int i;
    for(i=0; i<size; i++)
    {
        arr[i]=rand()%30+1;
    }
}

void choices()
{
    printf("\n");
    printf(" 1 : Selection Sort\n");
    printf(" 2 : Bubble Sort\n");
    printf(" 3 : Insertion Sort\n");
}
void show()
{
    /*for(i=0; i<1000; i++)
    {
        for(j=0; j<100; j++) {}
    }*/
    delay(0.1);
    system("cls");
    printf("\n\n");
    for(i=0; i<size; i++)
    {
        printf(" %d",arr[i]);
        printf("\t\t");
        for(j=0; j<arr[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void Insertion_sort()
{
    int m,n,k,temp;
    for(m=1; m<=size; m++)
    {
        temp=arr[m];
        for(n=0; n<m; n++)
        {
            if(temp<arr[n])
            {
                for(k=m; k>n; k--)
                {
                    arr[k]=arr[k-1];//putting element in index before it
                }
                arr[n]=temp;
                show();
                break;
            }
        }

    }
}

void selection_sort()
{
    int temp;
    for(m=0; m<size; m++)
    {
        for(n=m+1; n<size; n++)
        {
            if(arr[n]<arr[m])
            {
                temp=arr[n];
                arr[n]=arr[m];
                arr[m]=temp;
                show();
            }
        }
    }
}

void Bubble_sort()
{
    int temp;
    for(m=0; m<size-1; m++)
    {
        for(n=0; n<size-m-1; n++)
        {
            if(arr[n+1]<arr[n])
            {
                temp=arr[n];
                arr[n]=arr[n+1];
                arr[n+1]=temp;
                show();
            }
        }
    }
}

void main()
{
    int ch;
    generate();
    show();
    choices();
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        selection_sort();
        break;
    case 2:
        Bubble_sort();
        break;
    case 3:
        Insertion_sort();
        break;
    default:
        printf("Invalid choice.");
        break;
    }
    printf("\n\n");
    getchar();
    system("pause");
}
