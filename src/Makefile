##
## Makefile for makefile in /home/rotaru_i/gfx_colle_fantasy1/src
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Mon Dec 21 14:54:35 2015 Iulian Rotaru
## Last update Sun Dec 27 18:55:43 2015 Iulian Rotaru
##

CC	= gcc

NAME	= wolf3d

RM	= rm -rf

LIB	= -L/home/${USER}/.froot/lib/ -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -I/home/${USER}/.froot/include

CFLAGS	+= -Werror -Wall -Wextra -pedantic -ansi $(LIB) -I../inc

SRC	= main.c \
	  read_map.c \
	  read_map_next.c \
	  read_map_next_next.c \
	  read_map_next_next_next.c \
	  space_escape.c \
	  w_key.c \
	  a_key.c \
	  s_key.c \
	  d_key.c \
	  misc.c \
	  core.c \
	  core_next.c \
	  core_next_next.c \
	  core_next_next_next.c \
	  core_next_next_next_next.c \
	  tekline.c \
	  tekline_one.c \
	  tekline_two.c \
	  tekline_three.c \
	  norm_is_amazing.c \
	  minimap_manager.c \
	  minimap_manager_next.c \
	  ../tcore/tekpixel.c \
	  ../tcore/vecnorm.c \
	  ../tcore/go.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)
	cp $(NAME) ..

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
