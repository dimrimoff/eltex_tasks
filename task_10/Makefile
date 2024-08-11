sources = simple_process
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@
clean:
	rm simple_process
