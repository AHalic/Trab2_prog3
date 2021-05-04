cmake_minimum_required(VERSION 3.17)
project(Trab2_prog3)

set(CMAKE_CXX_STANDARD 11)

add_executable( Trab2_prog3 src/main.cpp
                src/Candidato.cpp src/DateUtils.cpp src/Eleicao.cpp src/Leitura.cpp 
                src/Partido.cpp src/Pessoa.cpp src/Relatorio.cpp src/Verificador.cpp
                src/Votos.cpp
                include/Candidato.h include/DateUtils.h include/Eleicao.h include/Leitura.h 
                include/Partido.h include/Pessoa.h include/Relatorio.h include/Verificador.h
                include/Votos.h)