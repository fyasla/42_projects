; rdi is the parameter const char *s1
; rsi is the parameter const char *s2
; rcx is the counting variable
; rax is the return value

section .text
	global ft_strcmp

ft_strcmp:
	mov rcx, 0 

_loop:
	mov		dl, [rdi + rcx]		; move in on byte register to avoid overflows
	mov		r8b, [rsi + rcx]
	cmp		dl, byte 0			; if end of s1 then end
	je		_end
	cmp		r8b, byte 0			; if end of s2 then end
	je		_end
	cmp		dl, r8b
	jne		_end				; if a a different character has been found then end
	inc		rcx
	jmp		_loop

_end:
	movzx	rax, dl				; reuse larger register to avoid overflows
	movzx	rdx, r8b
	sub		rax, rdx			; comparing the first different characters
	ret