/*
    may 3 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    Shellcode Length:  63

   0000000000000002 <shell>:
            
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
"\xeb\x1e\x5e\x48\x31\xc0\xb0\x01\x48\x89\xc7\x48\x89\xfa\x48\x83\xc2\x22\x0f\x05\x48\x31\xc0\x48\x83\xc0\x3c\x48\x31\xff\x0f\x05\xe8\xdd\xff\xff\xff\x68\x65\x79\x20\x69\x6e\x66\x6f\x73\x65\x63\x2c\x20\x68\x6f\x77\x20\x61\x72\x65\x20\x79\x6f\x75\x3f\x0a";


main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
