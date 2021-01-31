global	_ft_write			; ssize_t	ft_write(int fd, char *buf, size_t nbyte);
extern	___error
extern	errno

_ft_write:
	push	rbx				; rbxを逃す
	mov		rax, 0x02000004	; write関数のシステムコールアドレス
	syscall					; writeの処理実行
							; エラーの場合、 rax = errno になる（writeの仕様）
	jc		.err			; システムコールがエラーの場合
	jmp		.end

.err:
	mov		rbx, rax		; errnoをrbxに逃す
	call	___error		; rax = &errno
	mov		[rax], rbx		; *rax = rbx
	mov		rax, -1			; エラー時のwriteの戻り値は-1

.end:
	pop		rbx				;逃していたものを戻す
	ret