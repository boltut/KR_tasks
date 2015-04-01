/*Программа, выводящая строки длиной больше MINLINE символов*/
#include <stdio.h>
#define MINLINE 10 /*значение длины строки, больше которой следует печатать*/

int mygetline(char s[]);
void copy (char to[], char from[]);

main()
{
  int len; // длина текущей строки
  int max; // текущая максимальная длина
  char line[100]; // текущая введенная строка, 100 символов - посчитал пределом длины строки
  
  while((len = mygetline(line)) > 0)
  {
    if(len > MINLINE)
    {
      printf("%s", line);
    }
  }
  return 0;  
}

/*getline: считывает строку в s, возвращает ее длину*/
int mygetline(char s[])
{
  int c, i;
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }
  if(c == '\n')
  {
    s[i] = c;
     ++i;
  }
    s[i] = '\0';
    return i;
}

/*copy: копирует строку 'from' в 'to'; длина to считается достаточной*/
/*void copy (char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}*/
