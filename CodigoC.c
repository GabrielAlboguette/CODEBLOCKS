#include <stdio.h>
int main () {
int x, y = 1;
printf("Digite um numero inteiro nao negativo:");
scanf("%d", &x);
while(x>1){
y *=x;
x--;
}
printf("Saida %d", y);
return 0;
}
