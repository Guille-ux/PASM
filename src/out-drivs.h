#ifdef MUNIX_KERNEL
void pch(char ch, int x, int y) {
  putchar(ch, pos);
}
#endif
#ifdef WINDOWS
#include <conio.h>
#include <stdio.h>
void pch(char ch, int x, int y) {
  gotoxy(int x, int y);ç
  putchar(ch);
}
#endif
#ifdef LINUX
#include <stdio.h>
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}
void pch(char ch, int x, int y) {
  gotoxy(int x, int y);ç
  putchar(ch);
}
#endif
