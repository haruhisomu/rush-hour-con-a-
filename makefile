FLAGS = -O2

all: main test_Car test_Estado Test_Heap Test_muros Test_Operaciones Test_Pila Test_Tablero 

main: main.cpp  Car.o  Tablero.o Pila.o Estado.o Operaciones.o Heap.o Muros.o
	g++ ${FLAGS} Car.o main.cpp Tablero.o Pila.o Estado.o Operaciones.o Heap.o Muros.o -o main
Car.o: Car.cpp Car.h
	g++ ${FLAGS} -c Car.cpp
Tablero.o: Tablero.cpp Tablero.h
	g++ ${FLAGS} -c Tablero.cpp
Pila.o: Pila.cpp Pila.h
	g++ ${FLAGS} -c Pila.cpp
Estado.o: Estado.cpp Estado.h
	g++ ${FLAGS} -c Estado.cpp
Operaciones.o: Operaciones.cpp Operaciones.h
	g++ ${FLAGS} -c Operaciones.cpp	
Heap.o: Heap.cpp Heap.h
	g++ ${FLAGS} -c Heap.cpp	
Muros.o: Muros.cpp Muros.h
	g++ ${FLAGS} -c Muros.cpp

Test_Tablero: Test_Tablero.cpp Tablero.o Estado.o Car.o Muros.o Heap.o Pila.o Operaciones.o
	g++ -o Test_Heap Tablero.o Estado.o Car.o Muros.o Heap.o Pila.o Operaciones.o Test_Tablero.cpp

test_Car: test_Car.cpp Car.o 
	g++ -o test_Car Car.o test_Car.cpp

test_Estado: test_Estado.cpp Estado.o Car.o Muros.o
	g++ -o test_Estado Estado.o Car.o Muros.o test_Estado.cpp

Test_Heap: Test_Heap.cpp Heap.o Estado.o Car.o Muros.o
	g++ -o Test_Heap Heap.o Estado.o Car.o Muros.o Test_Heap.cpp

Test_muros: Test_muros.cpp Muros.o 
	g++ -o Test_muros Muros.o Test_muros.cpp

Test_Operaciones: Test_Operaciones.cpp Operaciones.o Estado.o Car.o Muros.o
	g++ -o Test_Operaciones Operaciones.o Estado.o Car.o Muros.o Test_Operaciones.cpp

Test_Pila: Test_Pila.cpp Pila.o Estado.o Car.o Muros.o
	g++ -o Test_Pila Estado.o Car.o Pila.o Muros.o Test_Pila.cpp
			
clean:
	rm -rf *.o main


