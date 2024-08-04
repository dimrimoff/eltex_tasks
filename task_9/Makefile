 sources = filesystem
all: $(sources)
$(sources): %: %.c
	gcc $< -o $@ -Wall -Werror
clean:
	rm filesystem output.txt
