#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void main()
{
 char *a, *b;
 a = "abacate";
 b = "uva";
 if (strcmp(a, b) < 0 )
      printf ("%s vem antes de %s no dicion�rio \n", a, b);
 else
      printf ("%s vem depois de %s no dicion�rio \n", a, b);
}
