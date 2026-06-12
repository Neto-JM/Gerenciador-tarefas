all: build/gerenciador

build/gerenciador: build/main.o build/Arquivo.o build/Categoria.o build/GerenciadorDeTarefas.o build/Historico.o build/Tarefa.o build/TarefaComPrazo.o build/TarefaSimples.o
	c++ -I include build/main.o build/Arquivo.o build/Categoria.o build/GerenciadorDeTarefas.o build/Historico.o build/Tarefa.o build/TarefaComPrazo.o build/TarefaSimples.o -o build/gerenciador

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

build/TarefaComPrazo.o: src/TarefaComPrazo.cpp include/TarefaComPrazo.h
	c++ -I include -c src/TarefaComPrazo.cpp -o build/TarefaComPrazo.o

build/TarefaSimples.o: src/TarefaSimples.cpp include/TarefaSimples.h
	c++ -I include -c src/TarefaSimples.cpp -o build/TarefaSimples.o

build/main.o: src/main.cpp
	c++ -I include -c src/main.cpp -o build/main.o

run: build/gerenciador
	./build/gerenciador

clean:
	rm -f build/*.o build/gerenciador