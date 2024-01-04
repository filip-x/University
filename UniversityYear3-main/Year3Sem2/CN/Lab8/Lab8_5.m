a = 0;
b= pi;


function retV = lab8_5(a,b,n)
  f = @(x) 1 ./ (4 + sin(20 * x));
  retV= repeated_simpson(a,b,f,n);
  endfunction


function retVal = repeated_simpson(a,b,f,n)
  h = (b-a)/n;
  x  = (a+h):h:(b-h);
  mij =(a+h/2):h:(b-h/2);
  retVal = ((b - a) / (6*n)) * (f(a) + 4 *sum(f(mij)) + 2* sum(f(x))+f(b));
endfunction


lab8_5(a,b,10)
lab8_5(a,b,30)