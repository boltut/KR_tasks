#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TARGET 1
#define NO_TARGET 0

void parsing_coords(FILE *fp, int array[100][100]);
void array_printf(int array[100][100]);
void find_center(int array[100][100], int radius);

int main(int argc, char *argv[])
{
  FILE *fp;
  int coords[100][100];
  //задаем радиус поражения
  int rad;
  //выбор, печатать цели или нет
  char choice[2];
  
  //Проверяю наличие аргументов,
  //выхожу из программы, в случае если аргументов нет
  //либо их количество не совпадает с требуемым
  fp = fopen(argv[1], "r");
  if (argc != 3) {
    printf("\nPlease, enter coords file name and radius\n");
    exit(1);
  }
  if (fp == NULL) {
    printf("\nOpening coords file - error\n");
  } 
  else {
    printf("\nOpening coords file - success\n");

    rad = atoi(argv[2]);
    parsing_coords(fp, coords);
    fclose(fp);

    printf("\nDo you want to print the targets? If your choice - YES");
    printf("\nplease, expand the terminal window to full screen (Y/N) ");
    scanf("%s", choice);
    if(choice[0] == 'Y' || choice[0] == 'y') {
      array_printf(coords);
    }
    
    find_center(coords, rad);

  }

  return 0;
}
void parsing_coords(FILE *fp, int array[100][100])
{
  int c1,c2;
  c1 = c2 = 0;
  int i,j;

  // заполняем массив нулями
  // чтобы исключить мусор
  for(i = 0; i < 100; ++i) {
    for(j = 0; j < 100; ++j) {
      array[i][j] = NO_TARGET;
    }
  }
  for(i = 0; i < 100; ++i) {
    fscanf(fp, "%d,%d", &c1, &c2);
    array[c1][c2] = TARGET;
  }
}
//рапечатаем для наглядности поле целей
//1 - цель, точка - не цель
void array_printf(int array[100][100])
{
  int i,j;
  for(i = 0; i < 100; ++i) {
    for(j = 0; j < 100; ++j) {
      if(array[i][j] == TARGET) {
        printf("1");  
      }
      else {
        printf(".");
      }
    }
    printf("\n");
  }
} 
//поиск оптимальной точки для удара и количества 
//уничтоженных целей
void find_center(int array[100][100], int radius)
{
  int i,j;
  float new_rad;
  // текущее и максимальное кол-во целей
  int dest_current = 0;
  int dest_max = 0;
  //координаты всех точек(в роли оптимальных точек)
  int new_center_x, new_center_y;
  //временные координаты для подсчета радиуса
  int temp_center_x, temp_center_y;
  //координаты оптимальной точки
  int pos_x, pos_y;

  // Каждая точка - будет предпологаемой оптимальной
  // точкой по очереди, будем анализировать сколько 
  // целей находятся вокруг нее в заданном радиусе

  for(new_center_x = 0; new_center_x < 100; ++new_center_x) {
    for(new_center_y = 0; new_center_y < 100; ++new_center_y) {
      
      for(i = 0; i < 100; ++i) {
        for(j = 0; j < 100; ++j) {
          if(array[i][j] == TARGET) {
            temp_center_x = i - new_center_x;
            temp_center_y = j - new_center_y;
            new_rad = sqrt((temp_center_x * temp_center_x) + (temp_center_y * temp_center_y));
            if(new_rad < radius) {
              ++dest_current;      
            }
          }
        }
      }

      if(dest_current > dest_max) {
        dest_max = dest_current;
        pos_x = new_center_x;
        pos_y = new_center_y;
      } 
      dest_current = 0;
    }
  }
  
  printf("Optimal point: %d %d\nDestroyed targets: %d\n", pos_x, pos_y, dest_max);

}



