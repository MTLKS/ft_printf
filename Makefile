NAME		= libftprintf.a
CC			= gcc
AR			= ar
HEADER		= ./includes
CFLAGS		= -Wall -Werror -Wextra
ARFLAGS		= rcs
RM			= rm -rf

OBJ_PATH	= obj
SRC_PATH	= src
LIBFT_PATH	= ./libft

SRC			= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ			= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
LIBFT		= $(LIBFT_PATH)/libft.a

all:		$(NAME)

bonus:		all

$(NAME):	$(LIBFT) $(OBJ_PATH) $(OBJ)
			cp	$(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c*
					$(CC) $(CFLAGS) -g -c -I$(HEADER) $< -o $@

$(LIBFT):
			make -C $(LIBFT_PATH) all

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJ_PATH)

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus libft