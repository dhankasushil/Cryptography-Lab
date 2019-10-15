#include<gmp.h>
void main()
{
  mpz_t a,b,t;
  mpz_inits(a,b,t,NULL);
  gmp_printf ("Enter a :");
  gmp_scanf("%Zd",a);
  gmp_printf ("Enter b :");
  gmp_scanf("%Zd",b);

  while(mpz_cmp_ui(b,0)!=0)
  {
    mpz_set(t,b);
    mpz_mod(b,a,b);
    mpz_set(a,t);
  }

  gmp_printf ("GCD of a & b is : %Zd\n", a);
}
