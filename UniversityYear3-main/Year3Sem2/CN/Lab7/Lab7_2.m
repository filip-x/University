t = [0 10 20 30 40 60 80 100];
p = [0.0061 0.0123 0.0234 0.0424 0.0738 0.1992 0.4736 1.0133];

p3 = polyfit(t,p,2)
p4 = polyfit(t,p,3)
interP = polyfit(t,p,7)

x = linspace(0,100);

hold on
plot(x,polyval(p3,x),'b')
plot(x,polyval(p4,x),'g')
plot(x,polyval(interP,x),'y')
plot(t,p,'o')

hold off