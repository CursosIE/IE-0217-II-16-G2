compilar: 
	gcc C/suma.c -o suma.c.o
	g++ C++/suma.cpp -o suma.cpp.o
	chmod +x Py/suma.py
	
clean: 
	rm suma.c.o suma.cpp.o
	
ejecutar:
	echo "El de C"
	./suma.c.o $(ARG)
	echo "El de c++"
	./suma.cpp.o $(ARG) 
	echo "El de python"
	./Py/suma.py $(ARG)
