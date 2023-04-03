clean:
	-rm main
all:clean
	gcc -o main.exe src/main.c src/imobiliare.c
run:all
	main.exe