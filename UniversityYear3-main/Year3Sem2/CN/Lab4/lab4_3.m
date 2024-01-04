nodes = linspace(0,6,13);
f  = @(x) exp(sin(x));
result = f(nodes);

x = 0:0.001:6;
fx = f(x);
nx = newton(nodes,x,result);

hold on;
plot(nodes, result, 'b.')
plot(x, fx, 'r')
plot(x, nx, 'g')
hold off;





