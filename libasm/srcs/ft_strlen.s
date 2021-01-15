; rdi is the parameter : char *s
; rax is the return value (length of the sting pointed to by s)

section .text
	global	ft_strlen

ft_strlen:
	mov rax, 0 ; intialize rax to 0

_loop:
	cmp BYTE[rdi + rax], 0	;compare *(s + i) and 0
	je _end					;end if equal
	inc rax					;else increment rax
	jne _loop				;and restart the loop

_end:
	ret