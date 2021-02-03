global	_ft_strdup					; char *ft_strdup(char *str);
									;		rax				rdi

; include ***
extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc
extern	___error
extern	errno
section	.text

_ft_strdup:
	test	rdi, rdi		; if (rdi == NULL) ?
	jz		.arg_err		; true -> err
	call	_ft_strlen		; rax = ft_strlen;
	inc		rax				; rax = len + 1;
	push	rdi				; strを逃す
	mov		rdi, rax		; rdi = rax (= len + 1)
	call	_malloc			; rax = malloc(rdi);
							; もし失敗していたら、この時点でerrnoに値が設定される
	test	rax, rax		; rax == NULL ?
	jz		.alloc_err		; true -> jump to error
	mov		rdi, rax		; rdi = rax (=malloc(strlen + 1))
	pop		rsi				; 逃しておいたstrをrsiに入れる
	call	_ft_strcpy		; rax = strcpy(rdi, rsi)
	ret

.arg_err:
	call	___error		; rax = &errno
	mov		dword [rax], 22	; errno = 1
	mov		rax, 0			; return 0
	ret

.alloc_err:
	mov		r8, rax			; 現時点の戻り値raxを保存
	call	___error		; rax = &errno
	mov		qword [rax], r8	; *&errno = errno
	xor		rax, rax		; rax = NULL
	ret