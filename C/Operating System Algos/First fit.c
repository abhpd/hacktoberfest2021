//First Fit Algorithm is the simplest technique of allocating the memory block to the processes amongst all. 
//In this algorithm, the pointer keeps track of all the free blocks in the memory and accepts the request of allocating a memory block to the coming process.
#include<stdio.h>
     #define max 25
    
     void main()
     {
      int frag[max],b[max],f[max],i,j,nb,nf,temp;
     static int bf[max],ff[max];
     printf("\n\tMemory Management Scheme - First Fit");
      printf("\nEnter the number of blocks:");
     scanf("%d",&nb);
     printf("Enter the number of files:");
     scanf("%d",&nf);
     printf("\nEnter the size of the blocks:-\n");
     for(i=1;i<=nb;i++)
    {
         printf("Block %d:",i);
        scanf("%d",&b[i]);
         
     }
     printf("Enter the size of the files :-\n");
    for(i=1;i<=nf;i++) 
     {
         printf("File %d:",i);
         scanf("%d",&f[i]);
     }
     printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
      for(i=1;i<=nf;i++)
      {
          printf("\n%d\t\t%d",i,f[i]);
          for(j=1;j<=nb;j++)
          {
              if(b[j]>=f[i])
              {
                   temp=b[j]-f[i];
                 ff[i]=j;
                 printf("\t\t%d\t\t%d\t\t%d",ff[i],b[j],temp);
                  b[j]=temp;
                 break;
              }
          }
          frag[i]=temp;
     bf[ff[i]]=1;
     }
    }