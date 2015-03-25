/*Перевод темепературы из градусов по Цельсию в градусы по Фаренгейту, 
обернутый в функцию*/

#include <stdio.h>
  
#define LOWER 0 // Нижний предел
#define UPPER 300 // Верхний предел
#define STEP 20 // Шаг

int cels2fahr ();
main()
{
  cels2fahr(UPPER, LOWER);
  return 0;
}

int cels2fahr ()
{
    int fahr;
    printf("\n\n\ncelsius to fahrengeit in function\n\n\n");
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
       printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32) );
    }  
       printf("\n");
       return 0; 
}
