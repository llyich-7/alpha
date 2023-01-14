main:	main.o newLinkedList.o
	@gcc main.o newLinkedList.o -o main
	@echo "Compiling: (3/3) Done."
	@echo "Result:"
	@./main
	

main.o: main.c
	@gcc main.c -c -o main.o
	@echo "Compiling: (1/3)"

newLinkedList.o: newLinkedList.c
	@gcc newLinkedList.c -c -o newLinkedList.o
	@echo "Compiling: (2/3)"
clean:
	rm newLinkedList.o main.o main