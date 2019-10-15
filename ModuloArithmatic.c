#include <stdio.h>
#include <gmp.h>

int main (void) {

          mpz_t a,b,n,ans;
	  mpz_inits(a,b,n,ans,NULL);
	  unsigned long int i, seed;
	  gmp_randstate_t r_state;

	  seed = time(NULL);
	  gmp_randinit_default (r_state);
	  gmp_randseed_ui(r_state, seed);

	  mpz_urandomb(a,r_state,14);
	  mpz_urandomb(b,r_state,14);
	  mpz_urandomb(n,r_state,14);

	  gmp_printf("a is %Zd\n", a);
	  gmp_printf("b is %Zd\n", b);
	  gmp_printf("n is %Zd\n\n", n);

          mpz_mod(a,a,n);
	  mpz_mod(b,b,n);
          mpz_add(ans,a,b);
          mpz_mod(ans,ans,n);

	  gmp_printf("(a+b) mod n is %Zd\n",ans);
	  
	  mpz_sub(ans,a,b);
          mpz_mod(ans,ans,n);
	
	  gmp_printf("(a-b) mod n is %Zd\n",ans);
		
	  mpz_mul(ans,a,b);
          mpz_mod(ans,ans,n);

	  gmp_printf("(a*b) mod n is %Zd\n",ans);
	  
	  mpz_set_ui(ans,0);
	  mpz_invert(ans,b,n);	// modular inverse
 	  if(mpz_cmp_ui(ans,0)==0)
	  { 
		gmp_printf("Modulo division not defined\n");
	  }
	  else
	  {
	  	mpz_mul(ans,ans,a);
	  	mpz_mod(ans,ans,n);

	  	gmp_printf("(a/b) mod n is %Zd\n",ans);
	  }
}
	  
	   
	
