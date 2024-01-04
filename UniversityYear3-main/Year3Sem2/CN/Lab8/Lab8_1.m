a = 0;
b = 1;
f = @(x) 2 ./ (1 + x .^ 2);

function retval = trapezium_quadrature(a, b, f)
  retval = ((b - a) / 2) * (f(a) + f(b));
end

%a
aprox = trapezium_quadrature(a,b,f)

%b
x = 0: 0.001:1;
fx= f(x);
x_vertices = [0 0 1 1 0];
y_vertices = [0 f(0) f(1) 0 0];

hold on
plot(x,fx,'.r')
plot(x_vertices,y_vertices,'b')
hold off

%c
function retVal = simpson_quadrature(a,b,f)
  
 retVal = ((b - a) / 6) * (f(a) + 4 *(f((a + b) / 2)) + f(b));
  
endfunction

simp = simpson_quadrature(a,b,f)
