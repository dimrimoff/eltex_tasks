sources = named_pipe_server named_pipe_client
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@
clean:
	rm named_pipe_server named_pipe_client
