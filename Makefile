PROJECT_NAME = reading.out

SRC = src/readfile.c \
src/sorting.c

T_SRC = test/test_readfile.c

UNI = unity/unity.c

INC = -I inc -I src -I unity

build: main.c $(SRC)
	gcc main.c $(SRC) $(INC) -o $(PROJECT_NAME)
	
run:$(PROJECT_NAME)
	./$(PROJECT_NAME)

test: $(SRC) $(T_SRC) $(UNI)
	gcc $(SRC) $(T_SRC) $(UNI) $(INC) -o $(PROJECT_NAME)
	./$(PROJECT_NAME)

coverage: ${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage main.c $(SRC) $(INC) -o $(PROJECT_NAME)
	./$(PROJECT_NAME) 
	gcov -a main.c

staticcheck:
	cppcheck --enable=all main.c $(SRC) 

memcheck:
	valgrind ./$(PROJECT_NAME)

all: build run test coverage staticcheck memcheck clean

clean:
	rm -rf $(PROJECT_NAME) *.gcov *.gcda *.gcno