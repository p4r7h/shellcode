/*
    may 2 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    len:6 bytes

     xor rax, rax
     mov al, 60
     mov rsi, 0
     syscall


*/



#include <stdio.h>
#include <string.h>

char code[] = "\x48\x31\xc0\xb0\x3c\xbe\x00\x00\x00\x00\x0f\x05";

int main()
{
    printf("len:%d bytes\n", strlen(code));
    (*(void(*)()) code)();
    return 0;
}

