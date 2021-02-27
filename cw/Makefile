all: main.o function_with_output.o operations_with_offers.o q_sort.o text_operations.o
	gcc main.o function_with_output.o operations_with_offers.o q_sort.o text_operations.o -o main

main.o: main.c structs.h
	gcc -c main.c
        
function_with_output.o: function_with_output.c  structs.h
	gcc -c function_with_output.c
        
operations_with_offers.o: operations_with_offers.c  structs.h
	gcc -c operations_with_offers.c
        
q_sort.o: q_sort.c q_sort.h  structs.h
	gcc -c q_sort.c
        
text_operations.o: text_operations.c  structs.h
	gcc -c text_operations.c

clean: 
	rm *.o main
