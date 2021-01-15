; rdi is the parameter : char *dest
; rsi is the parameter : char *src
; rax is the return value (pointer to dest)

section .text
	global ft_strcpy

ft_strcpy:
mov rax, rdi