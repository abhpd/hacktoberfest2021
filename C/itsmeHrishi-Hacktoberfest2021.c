#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//-----------------------------LOGIN SYSTEM-----------------------------------
void login(){
    char ch;
    do
    {
        char username[15];
        char password[12];
        //int i;
    
        printf("Enter your username:\n");
        scanf("%s",&username);

        printf("Enter your password:\n");
        scanf("%s",&password);

        //password[i]='\0';
        
        if(strcmp(username,"itsmeHrishi")==0){
            if(strcmp(password,"itssecret")==0){
                printf("\nWelcome.Login Success!");
                int end;
                int n,choice;
                printf("\n------'This is the program to sort your array by your choosen sorting method'------\n");
            
                do
                {        
                    printf("enter the size of your array : ");
                    scanf("%d",&n);
                    int arr[n];

                    printf("Enter the %d elements of your array\n",n);
                    for(int i = 0; i< n; i++){
                        scanf("%d",&arr[i]);
                    }

                    printf("Your inputted array:\n");
                    printf("{");
                    for(int i = 0; i< n; i++){
                    printf("%d\t",arr[i]);
                    }
                    printf("}\n");;

                    char ch;
                    do
                    {
                        printf("Enter the sorting method of your choice from following:\n1. Selection Sort\n2. Bubble Sort\n3.Insertion Sort\n");
                        printf("your choice : ");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                        case 1:
                            for(int i=0;i<n-1;i++){
                                for (int j = i+1; j < n; j++)
                                {
                                    if(arr[j] < arr[i]){
                                        int temp = arr[j];
                                        arr[j] = arr[i];
                                        arr[i] = temp;
                                    }
                                }
                            }
                                printf("Your shorted array:\n");
                                    printf("{");
                                    for(int i = 0; i< n; i++){
                                    printf("%d\t",arr[i]);
                                    }
                                    printf("}\n");
                            break;
                        case 2:
                            {
                            int c=1;
                            while (c<n)
                            {
                                for (int i = 0; i < n-c; i++)
                                {
                                    if(arr[i]>arr[i+1]){
                                        int temp=arr[i];
                                        arr[i]=arr[i+1];
                                        arr[i+1]=temp;;
                                    }
                                }
                                c++;
                            }
                            printf("Your shorted array:\n");
                            printf("{");
                            for(int i = 0; i< n; i++){
                            printf("%d\t",arr[i]);
                            }
                            printf("}\n");
                            }  
                        break;
                        case 3:
                            for (int i = 1; i < n; i++)
                            {
                                int temp = arr[i];
                                int j = i-1;
                                while (temp<arr[j] && j>=0)
                                {
                                    arr[j+1] = arr[j];
                                    j--;
                                }
                                arr[j+1] = temp;
                            }
                            printf("Your shorted array:\n");
                            printf("Your shorted array:\n");
                            printf("{");
                            for(int i = 0; i< n; i++){
                            printf("%d\t",arr[i]);
                            }
                            printf("}\n");
                            break;
                        default: 
                            printf("---Error !! [invalid choice]\n please enter your choice in integers between 1 to 3\n");
                            break;
                        }
                        printf("\npress y to try again or any key to exit : ");
                        scanf("%s",&ch);  
                    } while (ch == 'y');
                    
                printf("press 1 to run program again and any key to exit\n");
                scanf("%d",&end);  
                } while ( end == 1);

            }
        else{
            printf("\nwrong password");
        }
    
    }
    else{
        printf("\nUser doesn't exist");
    }

    printf("\npress y to try again or any key to exit : ");
    scanf("%s",&ch);  
    } while (ch == 'y' || ch == 'Y');
    exit(0);

}
//--------------------------main function-----------------------------------
int main()
{
    printf("\n\t\t\t-----YOU NEED TO LOGIN FIRST!!!-----\n");
    login();  
    return 0;
}
