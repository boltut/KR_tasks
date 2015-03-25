/*Перевод темепературы из градусов по Цельсию в градусы по Фаренгейту, 
обернутый в функцию*/

#include <stdio.h>
  
#define LOWER 0 // Нижний предел
#define UPPER 300 // Верхний предел
#define STEP 20 // Шаг

int cels2fahr (int upper, int lower);
main()
{
  int upper, lower;
  cels2fahr(upper, lower);
  return 0;
}

int cels2fahr (int upper, int lower)
{
    int fahr;
    upper = UPPER;
    lower = LOWER;

    printf("\n\n\ncelsius to fahrengeit in function\n\n\n");
    for(fahr = lower; fahr <= upper; fahr = fahr + STEP)
    {
       printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32) );
    }  
       printf("\n");
       return; 
}
