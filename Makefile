# Grupo: 
# Beatriz Maia: 2019107651
# Sophie Dilhon: 2019107591

CC		:= g++
CFLAGS	:= -std=c++11

BIN		:= bin
SRC		:= .
INCLUDE	:= .

EXECUTABLE	:= vereadores
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

# Argumentos utilizados para testar codigo

# Caso teste do pdf
ARG1 := candidatos.csv
ARG2 := partidos.csv
DATE := 15/11/2020

 
CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.cpp=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
# Remove apenas os objetos
cleanObjects:
	-$(RM) $(OBJECTS)
# Remove os objetos, o executável e arquivos csv e txt
clean: 
	-$(RM) $(OBJECTS) vereadores *.csv *.txt


# Comandos para executar
run: 
	./$(EXECUTABLE) $(DIR_ENT0) ./output/

	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES)

# Comandos para executar com valgrind
val: 
	# valgrind ./$(EXECUTABLE) $(DIR_ENT0) $(SAIDA)
	echo "val0"

val0: 
	valgrind ./$(EXECUTABLE) $(DIR_ENT0)