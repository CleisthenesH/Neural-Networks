# Copyright 2023 Kieran W Harvie. All rights reserved.
.PHONY: clean

dual_number: examples/dual_number.c src/dual_number.h
	gcc examples/dual_number.c src/dual_number.h -o dual_number -Isrc -lm

src/%.o:src/%.c src/%.h
	gcc -c $< -o $@ -Isrc  

clean:
	rm src/*.o
	find . -maxdepth 1 -type f -executable | xargs rm
