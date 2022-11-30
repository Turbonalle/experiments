run:
	@./a.out

m1:
	@gcc Math/m1_6174.c
	@echo "Compiled '6147'!"

m2:
	@gcc Math/m2_factorizer.c
	@echo "Compiled 'factorizer'!"

clean:
	@rm *.out
	@echo "All clean!"