all:

c:
	gcc -o $(name) $(name).c -lm -Wall
	./$(name)

f:
	gfortran -o $(name) $(name).f95 -Wall
	./$(name)

cf:
	gcc -c $(name1).c
	gfortran -c $(name2).f95
	gcc -o $(name0) $(name1).o $(name2).o
	./$(name0)
