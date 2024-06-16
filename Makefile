NAME = libasm.a

SRC = ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_write.s

NASM = nasm -f elf64

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

.s.o:
	$(NASM) $< -o $@

tester:
	gcc -Wall -Werror -Wextra main.c $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f a.out

re: fclean all