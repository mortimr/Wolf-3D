##
## Makefile for makefile in /home/rotaru_i/gfx_wolf3d
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Fri Dec 25 12:01:49 2015 Iulian Rotaru
## Last update Fri Dec 25 12:02:41 2015 Iulian Rotaru
##

all:
	make -C ./src

clean:
	make -C ./src clean

fclean:
	make -C ./src fclean

re:
	make -C ./src re

.PHONY: all clean fclean re
