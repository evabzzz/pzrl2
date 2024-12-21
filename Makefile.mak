all: prog
.PHONY: test clean

prog: main.o func.o
        gcc -o prog main.o func.o

main.o: main.c
        gcc -c main.c

func.o: func.c
        gcc -c func.c

test: prog
        
        echo "I want to sleep" > input.txt
        
        ./prog input.txt -r "sleep" "awake" > output.txt
        ./prog input.txt -d "to" >> output.txt
        ./prog input.txt -i -f "hi " >> output.txt
        ./prog input.txt -i -b " bro" >> output.txt

clean:
        rm -f prog *.o input.txt output.txt