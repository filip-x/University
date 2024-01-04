a = 1;
b = 1.5;
format long 

h = (b-a)/2;
f = @(x) exp(-(x .^ 2));
function retval = repeated_rectangle_midpoint(a, b, f, n)
  h = (b-a)/n;
  x =(a+h/2):h:(b-h/2);
  retval = ((b - a) / n) * sum(f(x));
end


res = repeated_rectangle_midpoint(a,b,f,150)
res2 = repeated_rectangle_midpoint(a,b,f,500)