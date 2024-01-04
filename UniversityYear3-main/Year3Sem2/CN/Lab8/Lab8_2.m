a =1.4;
b =2;
c = 1;
d =1.5;
f = @(x, y) log(x + 2 * y);
format long g;
function retVal = trapezium_double_integral(a,b,c,d,f)
  retVal = f(a, c) + f(a, d) + f(b, c) + f(b, d);
  retVal = retVal + 2 * f((a + b) / 2, c) + 2 * f((a + b) / 2, d);
  retVal = retVal + 2 * f(a, (c + d) / 2) + 2 * f(b, (c + d) / 2);
  retVal = retVal + 4 * f((a + b) / 2, (c + d) / 2);
  retVal = retVal * (b - a) * (d - c) / 16;
endfunction

aprox = trapezium_double_integral(a,b,c,d,f)