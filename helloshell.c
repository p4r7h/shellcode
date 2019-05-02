/*
    may 2 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    Shellcode Length:  64

    0000000000000002 <shellcode>:
            pop    rsi
        	xor    rax,rax
           	mov    al,0x1
          	mov    rdi,rax
        	mov    rdx,rdi
        	add    rdx,0x22
            syscall 

        	xor    rax,rax
        	add    rax,0x3c
        	xor    rdi,rdi
            syscall 



*/


#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\xeb\x1e\x5e\x48\x31\xc0\xb0\x01\x48\x89\xc7\x48\x89\xfa\x48\x83\xc2\x22\x0f\x05\x48\x31\xc0\x48\x83\xc0\x3c\x48\x31\xff\x0f\x05\xe8\xdd\xff\xff\xff\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x2c\x20\x70\x61\x72\x74\x68\x20\x69\x73\x20\x68\x65\x72\x65\x0a";


main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
