//Программа переписывающая введенную строку в обратном порядке

#include <stdio.h>
#include <stdlib.h>

int mygetline(char s[]);
void reverse(char str[], int n);

int main()
{
  char line[100];
  int c;
  int len;
  
  while((len = mygetline(line)) > 2) {
    reverse(line, len);  
  }
  return 0;
}
/*getline: считывает строку в s, возвращает ее длину*/
int mygetline(char s[])
{
  int c, i;
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
     ++i;
  }
    s[i] = '\0';
  return i;
}
//переписывает в обратном порядке строковый аргумент
void reverse(char str[], int n)
{
  int i;
  
  if(str[n-1] != '\n') {
    printf("\n");
  }
  
  
  for(i = n; i >= 0; --i) {
    printf("%c", str[i] );
  }
  printf("\n");
}
