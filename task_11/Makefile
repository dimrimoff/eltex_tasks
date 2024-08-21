sources = life_simulation
all: $(sources)
$(sources): %: %.c
	gcc myfuncs.c $< -g -o $@
clean:
	rm life_simulation
