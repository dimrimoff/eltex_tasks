sources = many_process
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@
clean:
	rm many_process
