all: doc prog
doc:
	magitex-cweb reticulado.tex
	dvipdf reticulado.dvi
prog:
	ctangle reticulado.tex
	$(CC) -g $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -DNUMERO_EH_INT -O2 teste.c src/reticulado.c -o teste_int
	$(CC) -g $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -DNUMERO_EH_DOUBLE -O2 teste.c src/reticulado.c -o teste_double
	$(CC) -g $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -DNUMERO_EH_MPZ -O2 teste.c src/reticulado.c -o teste_mpz -lgmp
	$(CC) -g $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -DNUMERO_EH_MPQ -O2 teste.c src/reticulado.c -o teste_mpq -lgmp
	$(CC) -g $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -DNUMERO_EH_BN -O2 teste.c src/reticulado.c -o teste_bn -lcrypto -lssl
	@echo "* Testando tipo (int):"
	@./teste_int
	@echo "* Testando tipo (double):"
	@./teste_double
	@echo "* Testando tipo (mpz_t):"
	@./teste_mpz
	@echo "* Testando tipo (mpq_t):"
	@./teste_mpq
	@echo "* Testando tipo (BN):"
	@./teste_bn
clean:
	rm -f *~
