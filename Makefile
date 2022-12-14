NAME		= bsq

SRCS 		= \
			  main.c \
			  srcs/solver/add_line.c \
			  srcs/solver/delete.c \
			  srcs/solver/get_solution.c \
			  srcs/solver/new.c \
			  srcs/solver/print_solution_fd.c \
			  srcs/parsing/ft_bsq.c \
			  srcs/parsing/ft_read_chars.c \
			  srcs/parsing/ft_realloc.c \
			  srcs/parsing/ft_mesure_line_slvraddline.c \
			  srcs/parsing/ft_parse_chars.c \
			  

ASMSRCS		= \

LIB_NAMES 	= \
			  libft \

LIB_DYN		= \
			  
HEADERS		= \
			  includes \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

OBJS			= ${SRCS:.c=.o} $(ASMSRCS:.s=.o)
DEPS			= ${SRCS:.c=.d}
CC				= gcc -no-pie
CCWFLGS			= -Wall -Wextra -Werror
CCDBGFLGS		= -g -fsanitize=address
CCOfdFLGS		= -O1 -1=native
CCO2FLGS		= -O2 -march=native
CCO3FLGS		= -O3 -march=native
DEPSFLAGS		= -MMD -MP
RM				= rm -f
MAKE			= make -C
AR				= ar
ARFLAGS			= rc
NASM			= nasm
NASMFLAGS		= -felf64

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CC) $(CCWFLAGS) $(CCDBGFLGS) -I$(HEADERS) $(LIB_HEADERS) -o $@ $(OBJS) $(LIB_LD) $(LIB_DYN) $(LIBS) -L/usr/lib -lXext -lX11 -lm

$(LIB_PATHS) :
		$(MAKE) $(dir $@)

clean :
		-$(RM) $(OBJS) $(DEPS)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

%.o : %.asm Makefile
		$(NASM) $(NASMFLAGS) -o $@ $<

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCWFLAGS) $(CCDBGFLGS) $(DEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@ $(LIB_LD) $(LIBS)
