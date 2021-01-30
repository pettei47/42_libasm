global _ft_strlen				; size_t	ft_strlen(char *str);
								;			rax			rdi
section .text					; FYI "section .data" means data section
								; .text means program section
_ft_strlen:
	mov	rax, 0					; int i = 0;

.loop:
	cmp	byte [rdi + rax] , 0	; if(str[rax] == '\0')
	je	.end					; str[rax] == 0 -> jump to end
	inc	rax						; i++;
	jmp	.loop					; jump to ".loop"

.end:
	ret							; return (rax);