sources = phonebook
all: $(sources)
$(sources): %: %.c
	gcc myfuncs.c $< -g -o $@
clean:
	rm phonebook
