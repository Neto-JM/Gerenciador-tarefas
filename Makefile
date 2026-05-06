Gerenciador.exe: build/main.o build/Arquivo.o build/Categoria.o build/GerenciadorDeTarefas.o build/Historico.o build/Tarefa.o
	c++ -I include  build/main.o build/Arquivo.o build/Categoria.o build/GerenciadorDeTarefas.o build/Historico.o build/Tarefa.o -o Gerenciador.exe

build/Arquivo.o: src/Arquivo.cpp include/Arquivo.h
	c++ -I include -c src/Arquivo.cpp -o build/Arquivo.o

build/Categoria.o: src/Categoria.cpp include/Categoria.h
	c++ -I include -c src/Categoria.cpp -o build/Categoria.o

build/GerenciadorDeTarefas.o: src/GerenciadorDeTarefas.cpp include/GerenciadorDeTarefas.h
	c++ -I include -c src/GerenciadorDeTarefas.cpp -o build/GerenciadorDeTarefas.o

build/Historico.o: src/Historico.cpp include/Historico.h
	c++ -I include -c src/Historico.cpp -o build/Historico.o

build/Tarefa.o: src/Tarefa.cpp include/Tarefa.h
	c++ -I include -c src/Tarefa.cpp -o build/Tarefa.o

build/main.o: src/main.cpp
	c++ -I include -c src/main.cpp -o build/main.o