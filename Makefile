run:
	@./a.out

m1:
	@gcc Math/m1_6174.c
	@echo "Compiled '6147'!"

m2:
	@gcc Math/m2_factorizer.c
	@echo "Compiled 'factorizer'!"

m3:
	@gcc Math/m3_highest_common_factor.c
	@echo "Compiled 'Highest Common Factor'!"

clean:
	@rm *.out
	@echo "All clean!"