a =1;
b =3; 
f = @(x) (100 ./ (x .^ 2)) .* sin (10 ./ x);
epsilon = 10 ^ -4;
function retval = simpson_quadrature(a, b, f)
  retval = ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
end

function retVal = repeated_simpson(a,b,f,n)
  h = (b-a)/n;
  x  = (a+h):h:(b-h);
  mij =(a+h/2):h:(b-h/2);
  retVal = ((b - a) / (6*n)) * (f(a) + 4 *sum(f(mij)) + 2* sum(f(x))+f(b));
endfunction

function I = adaptive_simpson(a, b, f, error)
  I1 = simpson_quadrature(a, b, f);
  I2 = simpson_quadrature(a, (a + b) / 2, f) + simpson_quadrature((a + b) / 2, b, f);
  if abs(I1 - I2) < 15 * error
    I = I2;
  else
    I = adaptive_simpson(a, (a + b) / 2, f, error / 2);
    I = I + adaptive_simpson((a + b) / 2, b, f, error / 2);
  endif
endfunction


adaptive_simpson = adaptive_simpson(a, b, f, epsilon)
repeated_simpson50 = repeated_simpson(a, b, f, 50)
repeated_simpson100 = repeated_simpson(a, b, f, 100) 