#This is a makefile
UNBEATABLE =
snakeo = snakebeatable.o
snakec = snakebeatable.c

ifdef UNBEATABLE  
	snakeo = snakeunbeatable.o
	snakec = snakeunbeatable.c
else 

endif


all: snake

snake: $(snakeo) 
	gcc -Wall -o snake $(snakeo) 



$(snakeo): $(snakec)
	gcc -c -Wall $(snakec)



clean:
	rm $(snakeo)

