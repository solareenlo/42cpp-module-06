# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 13:08:30 by tayamamo          #+#    #+#              #
#    Updated: 2021/06/09 13:08:30 by tayamamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for philo_one, updated Wed Jun  9 13:08:30 JST 2021

SRC := A.cpp B.cpp Base.cpp C.cpp main.cpp
OBJ := A.o B.o Base.o C.o main.o

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME := identify

CC := clang++
CFLAGS := -std=c++98 -Wall -Wextra -Werror
CFLAGS += -O0
CFLAGS += -g -fsanitize=address
RM := rm -fr

SRC_DIR := ./
OBJ_DIR := obj
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

.PHONY:	all
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: lint
lint:
	cpplint $(SRC)

.PHONY: thread
thread: CFLAGS += -g -fsanitize=thread
thread: re

.PHONY: leak
leak: CFLAGS += -g -fsanitize=leak
leak: re

.PHONY: address
address: CFLAGS += -g -fsanitize=address
address: re

.PHONY: clean
clean:
	$(RM) Makefile.bak $(NAME).dSYM $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: source
source:
	@mv Makefile Makefile.bak
	@echo "# **************************************************************************** #" > Makefile
	@echo "#                                                                              #" >> Makefile
	@echo "#                                                         :::      ::::::::    #" >> Makefile
	@echo "#    Makefile                                           :+:      :+:    :+:    #" >> Makefile
	@echo "#                                                     +:+ +:+         +:+      #" >> Makefile
	@echo "#    By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+         #" >> Makefile
	@echo "#                                                 +#+#+#+#+#+   +#+            #" >> Makefile
	@echo "#    Created: `date "+%Y/%m/%d %H:%M:%S"` by tayamamo          #+#    #+#              #" >> Makefile
	@echo "#    Updated: `date "+%Y/%m/%d %H:%M:%S"` by tayamamo         ###   ########.fr        #" >> Makefile
	@echo "#                                                                              #" >> Makefile
	@echo "# **************************************************************************** #" >> Makefile
	@echo '' >> Makefile
	@echo "# Makefile for philo_one, updated `date`" >> Makefile
	@echo '' >> Makefile
	@echo SRC := `ls *.cpp` >> Makefile
	@echo OBJ := `ls *.cpp | sed s/cpp$$/o/` >> Makefile
	@echo '' >> Makefile
	@sed -n -e '/^# DO NOT ADD OR MODIFY/,$$p' < Makefile.bak >> Makefile
