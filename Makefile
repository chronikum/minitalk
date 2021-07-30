# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 08:49:54 by jfritz            #+#    #+#              #
#    Updated: 2021/07/30 10:07:51 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minitalk

LIBFTNAME = libft.a

SERVERNAME = server.a

CLIENTNAME = client.a

CFLAGS = -Werror -Wall -Wextra

OBJS := $(*.o)

SERVER = ./server/server.c

CLIENT = ./client/client.c

LIBFTPATH = ./libft/

all: $(NAME)

${NAME}:
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SERVER} ${LIBFTNAME} -o ${SERVERNAME}
	${CC} ${CFLAGS} ${CLIENT} ${LIBFTNAME} -o ${CLIENTNAME}

server: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SERVER} ${LIBFTNAME} -o ${SERVERNAME}

client: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${CLIENT} ${LIBFTNAME} -o ${CLIENTNAME}

clean:
	rm -rf *.o

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(SERVERNAME) ${CLIENTNAME}

re: fclean ${NAME}
