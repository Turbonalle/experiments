m1:
	@gcc Math/m1_6174.c

m2:
	@gcc Math/m2_factorizer.c

m3:
	@gcc Math/m3_highest_common_factor.c

clean:
	@rm *.out
	@echo "All clean!"