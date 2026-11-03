CXX = g++
FLAGS = -Wall -Wextra -std=c++11 -I include -I third_party

SRC = src/Carta.cpp src/Coluna.cpp src/Descarte.cpp src/Estoque.cpp src/Fundacao.cpp src/Mover.cpp src/Pilha.cpp src/PilhaFundacao.cpp src/Tableau.cpp src/paciencia.cpp

TESTES = tests/test_carta.cpp tests/test_fundacao.cpp tests/test_mover.cpp tests/test_paciencia.cpp tests/test_pilha.cpp tests/test_tableau.cpp

all: $(SRC:.cpp=.o) src/main.o
	$(CXX) $(FLAGS) $^ -o build/paciencia
	./build/paciencia

testes: $(SRC:.cpp=.o) $(TESTES:.cpp=.o)
	$(CXX) $(FLAGS) $^ -o build/testes
	./build/testes

coverage: clean
	make testes FLAGS="$(FLAGS) --coverage"
	gcovr -r . --exclude third_party --exclude tests

%.o: %.cpp $(wildcard include/*.hpp)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f src/*.o tests/*.o src/*.gcda src/*.gcno tests/*.gcda tests/*.gcno
	rm -f build/paciencia build/testes data/teste*.csv