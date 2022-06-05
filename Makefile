NAME1	=	server
NAME2	=	client

SRCS1	=	server.c utils.c
SRCS2	=	client.c utils.c

CFLAGS	=	-Wall -Wextra -Werror

all		: 	${NAME1} ${NAME2}
${NAME1}:	
			@gcc ${CFLAGS} ${SRCS1} -o ${NAME1}
${NAME2}:			
			@gcc ${CFLAGS} ${SRCS2} -o ${NAME2}
clean	:	

fclean	:	clean
			@rm -rf ${NAME1} ${NAME2}
re		:	fclean all

.PHONY	:	all clean fclean re
