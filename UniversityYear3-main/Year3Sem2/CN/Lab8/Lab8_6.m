aproape_pi = 3.14;
format long

function retVal = repeated_simpson(a,b,f,n)
  h = (b-a)/n;
  x  = (a+h):h:(b-h)
  mij =(a+h/2):h:(b-h/2)
  retVal = ((b - a) / (6*n)) * (f(a) + 4 *sum(f(mij)) + 2* sum(f(x))+f(b));
endfunction


function retVal = erf(x,n)
  
  f = @(t) exp(-t .^2);
  integral  = repeated_simpson(0,x,f,n);
  retVal = (2/sqrt(pi))* integral;
end

n4 = erf(0.5, 4)
n10 = erf(0.5, 10)

