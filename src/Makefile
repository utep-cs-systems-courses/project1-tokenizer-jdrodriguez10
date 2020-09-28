tokenizer: tokenizer.o uimain.o history.o
	cc -o tokenizer tokenizer.o uimain.o history.o

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer

tokenizer.o: tokenizer.h tokenizer.c

uimain.o: uimain.c tokenizer.h history.h

history.o: history.h history.c tokenizer.h
