sources = 1 2 3 4
all: $(sources)
$(sources): %: %.c
	gcc myfuncs.c $< -o $@
clean:
	rm 1 2 3 4 
