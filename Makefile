# Grupo: 
# Beatriz Maia: 2019107651
# Sophie Dilhon: 2019107591

CC		:= g++
CFLAGS	:= -std=c++11

BIN		:= bin
SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= vereadores
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

# Argumentos utilizados para testar codigo

# Caso teste do pdf
ARG1 := entradas/vitoria-candidatos.csv
ARG2 := entradas/vitoria-partidos.csv
DATE := 15/11/2020

 
CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.cpp=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
# Remove apenas os objetos
cleanObjects:
	-rm  */*.o
	
# Remove os objetos, o executável e arquivos csv e txt
clean: 
	-$(RM) $(OBJECTS) vereadores *.csv *.txt


# Comandos para executar
run: 
	./$(EXECUTABLE) $(ARG1) $(ARG2) $(DATE)

	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES)

val:
	valgrind ./$(EXECUTABLE) $(ARG1) $(ARG2) $(DATE)
