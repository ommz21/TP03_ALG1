# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp03
MEM_LEAK=valgrind --leak-check=full --track-origins=yes --show-reachable=yes 

# === REGRAS =====
# ================
$(EXEC): main.cpp metro.o
	$(CC) $(CFLAGS) main.cpp metro.o -o $(EXEC)

grafo.o: headers/metro.o
	$(CC) $(CFLAGS) -c headers/metro.cpp -o metro.o

all: $(EXEC)
	$(EXEC)

memcheck: $(EXEC) #Execucao usando valgrind para verificar se o codigo possui algum leak de memoria
	$(MEM_LEAK)$(EXEC)

clean: #remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf tp03 metro.o headers/metro.o