NAME := libasm.a

includes := .
SRCS := srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_strdup.s \
		srcs/ft_write.s \
		srcs/ft_read.s \

OBJS := $(SRCS:.s=.o)
FLGS = -Wall -Werror -Wextra

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

$(OBJS): %.o: %.s
	nasm -f macho64 $< -o $@

.PHONY: .re fclean clean test
re: fclean all
fclean: clean ; -rm -f $(NAME) ft_asm
clean: ; rm -rf srcs/*.o ft_asm.dSYM

test: all
	gcc $(FLGS) -o ft_asm -L. main/test_all.c -lasm -g -fsanitize=address
	./ft_asm

.PHONY: len cpy cmp dup read write
len: all
	gcc $(FLGS) -o ft_asm -L. main/test_len.c -lasm -g -fsanitize=address
	./ft_asm
cpy: all
	gcc $(FLGS) -o ft_asm -L. main/test_cpy.c -lasm -g -fsanitize=address
	./ft_asm
cmp: all
	gcc $(FLGS) -o ft_asm -L. main/test_cmp.c -lasm -g -fsanitize=address
	./ft_asm
dup: all
	gcc $(FLGS) -o ft_asm -L. main/test_dup.c -lasm -g -fsanitize=address
	./ft_asm
read: all
	gcc $(FLGS) -o ft_asm -L. main/test_read.c -lasm -g -fsanitize=address
	./ft_asm
write: all
	gcc $(FLGS) -o ft_asm -L. main/test_write.c -lasm -g -fsanitize=address
	./ft_asm