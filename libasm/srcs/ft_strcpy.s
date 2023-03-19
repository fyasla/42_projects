; rdi is the parameter : char *dest
; rsi is the parameter : char *src
; rax is the return value (pointer to dest)
; rcx is the counting variable
; dl is a buffer for char

section .text
	global ft_strcpy

ft_strcpy:
	mov rax, rdi
	cmp	rdi, 0	; check if pointer is not NULL
	je _end
	mov rcx, 0	

_loop:
	mov dl, BYTE[rsi + rcx]		; copy the char in buffer
	mov BYTE[rdi + rcx], dl		; copy the char in dest
	inc rcx						; increment
	cmp dl, 0					; if char copied was 0 then end
	jne _loop

_end:
	ret