#include<gmp.h>
void main()
{
  mpz_t a,b,x,y,x1,x2,y1,y2,r,d,q,t1;
  mpz_inits(a,b,x,y,x1,x2,y1,y2,r,d,q,t1,NULL);

  gmp_printf ("Enter a :");
  gmp_scanf("%Zd",a);
  gmp_printf ("Enter b :");
  gmp_scanf("%Zd",b);

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
}





