CC=g++
CFLAGS=-c -Wall -std=c++11 -O2
LDFLAGS=
SOURCES=src/Analisador.cpp src/GerenciadorMemoria.cpp src/Main.cpp src/Processo.cpp src/Terminal.cpp src/Bloco.cpp src/Memoria.cpp src/Relogio.cpp src/Logger.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=firstfit

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	-rm $(OBJECTS)