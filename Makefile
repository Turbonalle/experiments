run:
	@./a.out

11:
	@gcc Math/m1_6174.c
	@echo "Compiled '6147'!"

12:
	@gcc Math/m2_factorizer.c
	@echo "Compiled 'factorizer'!"

21:
	@gcc Math/m3_highest_common_factor.c
	@echo "Compiled 'Highest Common Factor'!"

m6:
	@gcc Math/m6_running_calc.c
	@echo "Compiled 'Running Calculator'!"

clean:
	@rm *.out
	@echo "All clean!"