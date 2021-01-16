;	Linux system calls :
; %rax	| System call	|		%rdi		| %rsi		| %rdx
;  0	| sys_write		| unsigned int fd	| char* buf	| size_t count

extern __errno_location
section .text
	global ft_write

ft_write:
	mov rax, 1
	syscall		;write (fd, buf, count) as rax = 1
 	cmp     rax, 0
  	ret