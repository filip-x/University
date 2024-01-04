x = [1 1.5 2 3 4];
fx = [0 0.17609 0.30103 0.47712 0.60206];
X= [2.5 3.25];
[X;newton(x,X,fx)]

i= 10:35;
y = i./10;

fy = log10(y);
newtony = newton(x,y,fx);
format short g;
E = max(abs(fy-newtony))