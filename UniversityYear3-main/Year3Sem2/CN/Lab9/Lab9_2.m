axis =([0 1 0 4]);
a=0;
b=1;
f = @(x) 4./(1+x.^2);
fplot(f,[0,1]);

function retVal = repeated_trapezium_quadrature(a,b,f,n)
x = linspace(a,b,n+1);
retVal = ((b - a) / (2 * n)) * (f(a) + f(b) + 2 * sum(f(x(2:end-1))));
endfunction

function T = romberg(a,b,f,n)
  T = NaN(n)
  for i = 1:n
    T(i,1) = repeated_trapezium_quadrature(a,b,f,-2^(i-1))
    for j = 2:i
      Tij = (4 ^ (-j+1)) *T(i-1,j-1) - T(i,j-1);
      T(i,j) = Tij/(4 ^ (-j+1)-1);
    endfor
  endfor
 
endfunction

romberg (a,b,f,-2^(i-1))


