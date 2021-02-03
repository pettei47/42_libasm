How to review

only "make"
-> nasm compiles libasm.a

make + "len" or "cpy" or "cmp" or "read" or "write" or "dup"
-> each tests will run.

at "len", "cpy", "dup"
run  ./ft_asm NULL
You can see the case that argment is NULL at libc

and
run ./ft_asm "any string you like"
You can see the case you like

at "cpy"
run ./ft_asm "any string you like" "any string ..."
You can see the case you like
and if the one is NULL, you can see the case NULL

make + "test" or "main"
-> all tests will run together

then, you should read my srcs files