sources = unnamed_pipe
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@
clean:
	rm unnamed_pipe
