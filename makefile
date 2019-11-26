CC=gcc
CFLAGS= -g

TARGET=main
INFIX=i2p
CODE=code
virm=vm

INPUT_=input.txt

OUT2 = a2.txt

start: 	generate

generate: tokenise

tokenise: tokeniser.o #infpf
	@echo "Tokenising input"
	$(CC) $(CFLAGS) tokeniser.c -o $(TARGET)

infpf: 	infixpos3.o #codegen
	@echo "Infix-to-Postfix"
	$(CC) $(CFLAGS) -c main infixpos3.c -o $(_OUTPUT)

codegen: code_generator.o #VM
	@echo "Generating Code..."
	$(CC) $(CFLAGS) -c $(_OUTPUT) code_generator.c $(_OUTPUT)

VM:	virmac.o end
	"Processing Result..."
	$(CC) $(CFLAGS) virmac.c

clean:
	rm *.o main input.txt answers.txt
