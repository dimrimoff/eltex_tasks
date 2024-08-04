sources = file_manager
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@ -lncurses
clean:
	rm file_manager
