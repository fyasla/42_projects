; rdi is the parameter const char *s1
; rsi is the parameter const char *s2
; rcx is the counting variable
; rax is the return value

section .text
	global ft_strcmp

ft_strcmp:
	mov rcx, 0
	mov rax, [rdi + rcx]	; char comparaison :
	sub rax, [rsi + rcx]	; rax = *(rdi +rcx) - *(rsi + rcx)
	cmp rax, 0
	jne _end					; if characters are not the same then end
	cmp BYTE[rdi + rcx], 0
	je _end					; if at the end of s1 string then end
	inc rcx					; else continue comparaison
	jmp ft_strcmp

_end:
	ret