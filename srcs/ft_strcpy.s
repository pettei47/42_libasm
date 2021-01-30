global _ft_strcpy				; char	*ft_strcpy(char *s1, char *s2);
								;		 rax			rdi		  rsi
section .text

_ft_strcpy:
	push	rbx					; rbxを使うので、元々の値をスタックに逃しておく
	xor		rax, rax			; char *ret = NULL;
	mov		rcx, 0				; int	i   = 0;

.loop:
	mov		bl, [rsi+rcx]		; char bl = s2[i]
	mov		[rdi+rcx], bl		; s1[i] = bl
	test	bl, bl				; if (bl == '\0')
	jz		.end				; 	return
	inc		rcx					; i++;
	jnz		.loop				; jump to .loop

.end
	mov		rax, rdi			; ret = s1
	pop		rbx					; 逃しておいたrbxを戻す
	ret