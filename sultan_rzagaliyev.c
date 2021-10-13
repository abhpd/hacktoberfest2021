#include <stdio.h>

typedef struct
{
  int r, g, b;
} Color;

typedef struct
{
  int x, y;
} Coords;

typedef struct
{
  Color color;
  Coords points[2];
} LineSegment;

typedef struct
{
  LineSegment lines[3];
} Triangle;


void fibonacci(int arr[], int size)
{
  arr[0] = 1;
  arr[1] = 1;

  for (int i=2; i<size; i++)
  {
    arr[i] = arr[i-1] + arr[i-2];
  }
}

void print(int arr[], int size)
{
  for (int i=0; i<size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main(void) 
{
  printf("==========================================\n");
  printf("==               TASK 1:                ==\n");
  printf("==========================================\n");

  Triangle triangles[5];

  for (int i=0; i<5; i++)
  {
    Color firstColor = {255, 255, 255};
    Color secondColor = {255, 0, 0};
    Color ThirdColor = {0, 0, 0};

    triangles[i].lines[0].color = firstColor;
    triangles[i].lines[1].color = secondColor;
    triangles[i].lines[2].color = ThirdColor;

    
    triangles[i].lines[0].points[0].x = i+1;
    triangles[i].lines[0].points[0].y = i+1;

    triangles[i].lines[0].points[1].x = i+2;
    triangles[i].lines[0].points[1].y = i+2;


    triangles[i].lines[1].points[0].x = i+2;
    triangles[i].lines[1].points[0].y = i+2;

    triangles[i].lines[1].points[1].x = 2*(i+1);
    triangles[i].lines[1].points[1].y = i+1;


    triangles[i].lines[2].points[0].x = 2*(i+1);
    triangles[i].lines[2].points[0].y = i+1;

    triangles[i].lines[2].points[1].x = i+1;
    triangles[i].lines[2].points[1].y = i+1;

  }

  for (int i=0; i<5; i++)
  {
    printf("Triangle %d:\n", i+1);
    for (int j=0; j<3; j++)
    {
      printf("  Line %d:\n", j+1);
      printf("    Red color: %d\n", triangles[i].lines[j].color.r);
      printf("    Green color: %d\n", triangles[i].lines[j].color.g);
      printf("    Blue color: %d\n", triangles[i].lines[j].color.b);

      printf("    Point 1:\n");
      printf("      x = %d\n", triangles[i].lines[j].points[0].x);
      printf("      y = %d\n", triangles[i].lines[j].points[0].y);

      printf("    Point 2:\n");
      printf("      x = %d\n", triangles[i].lines[j].points[1].x);
      printf("      y = %d\n\n", triangles[i].lines[j].points[1].y);
    }
  }


  printf("==========================================\n");
  printf("==               TASK 2:                ==\n");
  printf("==========================================\n");

  int size;

  do
  {
    printf("Please provide the size: ");
    scanf("%d", &size);

    if (size <= 0)
      break;

    int arr[size];
    fibonacci(arr, size);
    print(arr, size);

  } while (size > 0);


  return 0;
}