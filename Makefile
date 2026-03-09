TARGET = bin/clicalc
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

run: clean default
	./$(TARGET) 

default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/clicalc
	rm -f *.db

$(TARGET): $(OBJ)
	gcc -o $@ $^ -lm

obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude