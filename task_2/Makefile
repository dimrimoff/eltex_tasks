sources = 1 2 3 4
all: $(sources)
$(sources): %: %.c
	gcc $< -o $@
clean:
	rm 1 2 3 4 
