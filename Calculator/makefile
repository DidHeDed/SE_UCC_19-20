CC=gcc
CFLAGS= -g

TARGET=main
INFIX=i2p
CODE=code
VM = vm

INPUT=input.txt
OUT1=answers.txt


start: 	tokenise infpf codegen VirM

tokenise: tokeniser.o
	@echo "\n\nTokenising input\n\n"
	$(CC) $(CFLAGS) tokeniser.c -o $(TARGET)
	./$(TARGET)
	

infpf: 	infixpos3.o
	@echo "\n\nInfix-to-Postfix\n\n"
	$(CC) $(CFLAGS) infixpos3.c -o $(INFIX)
	./$(INFIX)

codegen: code_generator.o 
	@echo "\n\nGenerating Code...\n\n"
	$(CC) $(CFLAGS) code_generator.c -o $(CODE)
	./$(CODE)

VirM:	virmac.o
	"Processing Result..."
	$(CC) $(CFLAGS) virmac.c -o $(VM)
	./$(VM)

clean:
	rm *.o  $(INPUT) $(OUT1) $(TARGET) $(INFIX) code a2.txt
