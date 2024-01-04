xi = [0 pi/2 pi 3*pi/2 2*pi];
yi = sin(xi);

gr1 = spline(xi,yi,pi/4)
gr2 = spline(xi,[1,yi,1],[pi/4])
hold on 
x = linspace(0,2*pi);
plot(x,spline(xi,yi,x), 'b')
plot(x,spline(xi,[1,yi,1],x),'r')
hold off
