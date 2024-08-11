sources = mybash
all: $(sources)
$(sources): %: %.c
	gcc $< -g -o $@
clean:
	rm mybash
