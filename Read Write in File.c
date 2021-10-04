#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE * file;
  int num;
    char ch;
    file = fopen("sample.txt", "r+w");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }
   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(file,"%d",num);
   fscanf(file,"%d",&num);
   printf("value = %d",num);
   fclose(file);
  return 0;
}
