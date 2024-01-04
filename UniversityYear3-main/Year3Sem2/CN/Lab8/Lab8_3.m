r= 110;
p = 75;
function retVal = repeated_trapezium_quadrature(a,b,f,n)
x = linspace(a,b,n+1);
retVal = ((b - a) / (2 * n)) * (f(a) + f(b) + 2 * sum(f(x(2:end-1))));
endfunction

function retV = lab_8_3(r,p,n)
  f = @(x) (1 - ((p / r) ^ 2) * sin(x)) .^ (1 / 2);
  integral = repeated_trapezium_quadrature(0, 2 * pi, f, n);
  retV = (60 * r) / (r ^ 2 - p ^ 2);
  retV = retV * integral;
 endfunction

lab_8_3(r,p,3)
lab_8_3(r,p,4)

