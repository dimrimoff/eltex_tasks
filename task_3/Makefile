sources_1 = 1
sources_2 = 2 3 4
all: $(sources_1) $(sources_2)
$(sources_1): %: %.c
	gcc myfuncs.c $< -o $@
$(sources_2): %: %.c
	gcc $< -o $@
clean:
	rm 1 2 3 4 
