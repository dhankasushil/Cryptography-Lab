#include <stdio.h>
#include <gmp.h>

int main (void) {
          mpz_t a,b,x,y,x1,x2,y1,y2,r,d,q,t1;
	  mpz_inits(a,b,x,y,x1,x2,y1,y2,r,d,q,t1,NULL);
	  unsigned long int i, seed;
	  gmp_randstate_t r_state;

	  seed = time(NULL);
	  gmp_randinit_default (r_state);
	  gmp_randseed_ui(r_state, seed);

	  mpz_urandomb(a,r_state,14); // from 0 to 2^n-1 use urandomb   for 0 to n-1 use urandomm
	  mpz_urandomb(b,r_state,14);

	  gmp_printf("a is %Zd\n", a);
	  gmp_printf("b is %Zd\n", b);
	    

	  if(mpz_cmp_ui(b,0)==0)
	  {
	    mpz_set(d,a);
	    mpz_set_ui(x,1);
	    mpz_set_ui(y,0);
	  }
	  else
	  {

	    mpz_set_ui(x2,1);
	    mpz_set_ui(x1,0);
	    mpz_set_ui(y2,0);
	    mpz_set_ui(y1,1);

	    while(mpz_cmp_ui(b,0)>0)
	    {
		mpz_fdiv_q(q,a,b);  // q=a/b
		mpz_mod(r,a,b);	    // r=a%b
		mpz_mul(t1,q,x1);
		mpz_sub(x,x2,t1);   // x=x2-qx1
		mpz_mul(t1,q,y1);
		mpz_sub(y,y2,t1);   //y=y2-qy1

		mpz_set(a,b);
		mpz_set(b,r);
		mpz_set(x2,x1);
		mpz_set(x1,x);
		mpz_set(y2,y1);
		mpz_set(y1,y);  
	    }

	    mpz_set(d,a);
	    mpz_set(x,x2);
	    mpz_set(y,y2);
	  }
	
	  	
	  gmp_printf ("GCD of a & b is : %Zd , X is %Zd ,Y is %Zd\n", d,x,y);		  

          return 0;
}
