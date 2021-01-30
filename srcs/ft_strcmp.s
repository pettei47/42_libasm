global	_ft_strcmp			;int	ft_strcmp(char *s1, char *s2);
							;		rax				rdi		rsi
section .text

_ft_strcmp:
	push	rbx					; rbxを使うので、元々の値をスタックに逃しておく
	xor		rax, rax			; char	al = 0;
	xor		rbx, rbx			; char	bl = 0;
	xor		rcx, rcx			; int	i  = 0;

.loop:
	mov		al, byte [rdi+rcx]	; char al = s1[i];
	mov		bl, byte [rsi+rcx]	; char bl = s2[i];
	cmp		al, bl				; al == bl ?
	jne		.diff				; false
								; ↓true
	test	al, al				; al == 0 ?
	jz		.end				; true
								; ↓false
	inc		rcx					; i++;
	jmp		.loop				; jump to .loop

.diff:
	sub		rax, rbx			; rax = rax - rbx;
	jl		.minus				; if (rax < 0) jump to .minus;
	mov		rax, 1				; rax > 0 -> rax = 1;
	jmp		.end

.minus:
	mov		rax, -1				; rax < 0 -> rax = -1;
	jmp		.end

.end:
	pop		rbx					; 逃しておいたrbxを戻す
	ret			
