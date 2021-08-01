# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 08:49:54 by jfritz            #+#    #+#              #
#    Updated: 2021/08/01 12:08:18 by jfritz           ###   ########.fr        #
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

CLIENT = ./client/client.c ./client/ft_sender.c

all: $(NAME)

libft:
	make -C ./helper/libft
	mv ./helper/libft/${LIBFTNAME} ${LIBFTNAME}

${NAME}: libft
	${CC} ${CFLAGS} ${SERVER} ${LIBFTNAME} -o ${SERVERNAME}
	${CC} ${CFLAGS} ${CLIENT} ${LIBFTNAME} -o ${CLIENTNAME}

server:
	${CC} ${CFLAGS} ${SERVER} ${HELPERSRC} ${LIBFTNAME} -o ${SERVERNAME}

client:
	${CC} ${CFLAGS} ${CLIENT} ${HELPERSRC} ${LIBFTNAME} -o ${CLIENTNAME}


tester: fclean $(NAME)
	rm -f ./tester/server.a
	rm -f ./tester/client.a
	cp server.a ./tester/
	cp client.a ./tester/
clean:
	rm -rf *.o

fclean: clean
	rm -f ${OBJS} $(SERVERNAME) ${CLIENTNAME}

re: fclean ${NAME}
