 sources = mycalc
all: $(sources)
$(sources): %: %.c
	gcc $< -o $@ -L. -ldl -Wl,-rpath,.
clean:
	rm mycalc  
