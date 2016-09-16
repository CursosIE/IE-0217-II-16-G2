#!/usr/bin/env python
import sys

## @package sumar.py
# Programa que calcula la suma de argumentos. 
#
# Programa el cual calcula la suma de los argumentos ingresados a la hora de correr este. 



## Funcion para calcular el resultado de la suma de los argumentos ingresados a la hora de correr #  el programa. 
## @var sum 
# Guarda el resultado de la suma de los numeros de los argumentos en la fila argv.
def main():
	
	sum = 0
	for i in range(1, len(sys.argv)):
		sum += float(sys.argv[i])
	print sum 
# @code 
# 
#	sum = 0
#	for i in range(1, len(sys.argv)):
#		sum += float(sys.argv[i])
#	print sum 
# @endcode
# 
if __name__=="__main__":
	main()
