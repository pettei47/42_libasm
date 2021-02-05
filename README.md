# How to review
	make
-> nasm compiles libasm.a
#
	make len
	make cmp
	make cpy
	make write
	make read
	make dup
-> each tests will run.
#
## len, cpy, dup
	./ft_asm NULL
-> You can see the case that argment is NULL at libc

	./ft_asm "any string you like"
-> You can see the case you like
#
## cmp
	./ft_asm "any string you like" "any string ..."
-> You can see the case you like<br>
and if either one is NULL, you can see the case NULL
#
## read
	./ft_asm read
-> You can read something you write in stdin.
# 
## write
	./ft_asm "any string you like"
then

	cat test_wirte.txt
#
	make test
	make main
-> all tests will run together

finally, you should read my srcs files
