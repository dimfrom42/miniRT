.PHONY : all clean fclean re

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBS = -L./lib/libft -lft\
	   -L. -lmlx\
	   -L./lib/minilibx_opengl_20191021 -lmlx

INC = -I./header -I./src -I./lib

SRCDIR = ./src/parsing/\
		 ./src/util/\
		 ./src/init/\
		 ./src/vector/\
		 ./src/yoojlee/

SRCS_PARSE = $(addprefix ./src/parsing/, \
			 amb_light_parsing.c\
			 cam_parsing.c\
			 cylinder_parsing.c\
			 light_parsing.c\
			 parse_util.c\
			 parse.c\
			 plane_parsing.c\
			 sphere_parsing.c)

SRCS_UTIL = ./src/util/error.c

SRCS_INIT = $(addprefix ./src/init/, \
			init_world.c\
			init.c)

SRCS_VECTOR = $(addprefix ./src/vector/, \
			  vector.c\
			  vector_utils.c)

SRCS_YOOJLEE = $(addprefix ./src/yoojlee/, \
			   hit_sphere.c\
			   hit_plane.c\
			   hit_cylinder.c\
			   mlx.c\
			   pixel.c\
			   ray.c\
			   render.c\
			   trace.c \
			   light.c \
			   clear.c \
			   utils.c)

SRCS = $(SRCS_PARSE)\
	   $(SRCS_UTIL)\
	   $(SRCS_INIT)\
	   $(SRCS_VECTOR)\
	   $(SRCS_YOOJLEE)\
	   main.c

OBJDIR = objects

vpath %.c $(SRCDIR)

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

$(NAME) :	$(OBJS)
			make mms
			make opengl
			make libft
			$(CC) $(LIBS) $(INC) $(CFLAGS) -framework OpenGL -framework AppKit -o $@ $^

$(OBJDIR) :
			mkdir $(OBJDIR)

$(OBJDIR)/%.o : %.c $(OBJDIR)
				$(CC) $(CFLAG) $(INC) -c $< -o $@

mms :
		make -C lib/minilibx_mms_20200219
		cp -p lib/minilibx_mms_20200219/libmlx.dylib ./

opengl :
		make -C lib/minilibx_opengl_20191021

libft :
		make -C lib/libft

clean :
		make -C lib/minilibx_mms_20200219 clean
		make -C lib/minilibx_opengl_20191021 clean
		make -C lib/libft clean
		rm -rf libmlx.dylib
		rm -rf $(OBJDIR)

fclean : clean
		 make -C lib/libft fclean
		 rm -rf $(NAME)

re : clean all

all : $(NAME)


			 

