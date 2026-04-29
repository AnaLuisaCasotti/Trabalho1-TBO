# Pega todos os arquivos .c
C_SOURCE = $(wildcard *.c)

# Pega todos os arquivos .h
H_SOURCE = $(wildcard *.h)

# Arquivos objeto (.o)
OBJ = $(C_SOURCE:.c=.o)

# Compilador
CC = gcc

# Flags do compilador
CC_FLAGS = -W -Wall -Wextra -std=c11 -pedantic -MMD -MP

# Regra default: compila o programa
all: trab1

# Gera o executável "trab1" a partir dos arquivos objeto (.o)
trab1: $(OBJ)
	@$(CC) $(OBJ) -o $@ -lm

# Compila os arquivos .c em um .o correspondente
%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

# Inclui os arquivos de dependência (.d) gerados automaticamente
-include $(OBJ:.o=.d)

# Remove arquivos gerados (executável, objetos e dependências)
clean:
	@rm -rf *.o *.d trab1 *~