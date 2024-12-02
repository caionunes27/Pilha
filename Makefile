# Definindo o compilador e as flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Nome do arquivo de código-fonte padrão (caso não seja passado como parâmetro)
SRC = $(FILE).c

# Nome do executável (default: nome do arquivo sem a extensão .c)
TARGET = $(FILE)

# Regra principal para compilar
all: $(TARGET)

# Compilação do executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	gnome-terminal -- bash -c "./$(TARGET); echo ''; echo 'Pressione Enter para fechar...'; read"

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET)

# Definindo que as regras não são arquivos
.PHONY: all run clean

#exemplo de uso:
#make FILE=programa run