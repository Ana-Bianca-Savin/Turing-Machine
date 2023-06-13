build: 
	gcc -Wall -Werror -std=c99 tema1.c functiiCoadaStiva.c functiiBanda.c functiiOperatii.c -o tema1
run:
	./tema1
clean:
	rm -f tema1
zip:
	zip tema1.zip functiiBanda.c functiiCoadaStiva.c functiiOperatii.c tema1.c headers.h Makefile README