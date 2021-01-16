;	Linux system calls :
; %rax	| System call	|		%rdi		| %rsi		| %rdx
;  0	|	sys_read	| unsigned int fd	| char* buf	| size_t count

section .text
	extern __errno_location
	global ft_read

ft_read:
	mov		rax, 0
	syscall
	cmp		rax, 0
	jl		_error ; if there is an error
	ret

_error:
	mov		rcx, rax
	call	__errno_location	; so rax is pointing to errno
	neg		rcx					; as the man says : "Valid error numbers are all positive numbers"
	mov		[rax], rcx			; update errno value
	mov		rax, -1				; return -1 
	ret