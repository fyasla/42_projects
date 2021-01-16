; rdi is the parameter : const char *s
; 
section .text
	extern malloc		; "extern" so the fuctions are callable
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup

ft_strdup:						
	push rdi						; push the *s pointer on the stack
	call ft_strlen
	inc rax				
	mov rdi, rax					; rdi = strlen(s) + 1
	call malloc						; malloc (rdi)
	cmp	rax, 0						; protect malloc
	je end
	pop rsi							; get the *s pointer back from the stack
	mov	rdi, rax
	call ft_strcpy					; strcpy (rdi, rsi)
end:
	ret