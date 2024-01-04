x = linspace(-5, 5, 15);
f = sin(2 * x);
df = 2* cos(2*x);
input =-5: 0.01 : 5;

format short g
FandDF = hering(x,input,f,df);

hold on;
plot(input, sin(2 * input), 'r');
plot(input,FandDF(1, :), 'b');
hold off;