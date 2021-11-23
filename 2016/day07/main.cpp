#include <stdio.h>

int main() {
  printf("\033[31mred text\n");
  printf("\033[33;44myellow on blue\n");
  printf("\033[0mdefault colors\n");
  return 0;
}
