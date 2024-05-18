sources = test
all: $(sources)
$(sources): %: %.c
	gcc $< -o $@ -fno-stack-protector -no-pie -g
clean:
	rm test 
