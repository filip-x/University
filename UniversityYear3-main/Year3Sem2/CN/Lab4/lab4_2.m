x = [1 2 3 4 5];
fx = [22 23 25 30 28];
X = 2.5
disp("a.)")
[X;newton(x,X,fx)]


disp("b.)")

X = 1:0.0001:5;
hold on
plot(x,fx,'r.')
plot(X,newton(x,X,fx),'b')
hold off



