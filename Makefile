NAME := libasm.a

includes := .
SRCS := srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_read.s \
		srcs/ft_write.s \
		srcs/ft_strdup.s \

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
fclean: clean ; -rm -f $(NAME)
clean: ; rm -rf srcs/*.o

test:
	gcc $(FLGS) -o ft_asm -L. test.c -lasm -g -fsanitize=address
	./ft_asm