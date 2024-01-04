v = randi(5,1,6)
u = randi(5,1,6)
v+u
%v*u
A = randi(5,3,6)
B = randi(5,6,7)
A*B
A = magic(7)
tril(A,-1)
triu(A)
diag(diag(A))
diag(A)



%f(x) = e 

%x = linspace(0,1,1000);%same as above
%y = exp(10*x.*(x-1)).* sin(12*pi*x)
%plot(x,y)

%f = @(x) exp(10*x.*(x-1)).* sin(12*pi*x)
%fplot(f,[0,1],'b','linewidth',2)

%
%t = 0 : 0.0001 : 10 * pi;
%a = input("a = ")
%b = input("b = ")
%x = (a + b) * cos(t) - b * cos((a / b + 1) * t);
%y = (a + b) * sin(t) - b * sin((a / b + 1) * t);
%plot(t, x, 'r')
%plot(t, y, 'b')


%f = @(x)(-1<=x & x>0).* (x.^ 2 + sqrt(1-x)) + (0 < x & x>=1).*(x.^2 + sqrt(1 - x));
%fplot(f,[-1,1]);

function v = g(x)
  if x == 1
    v = 1 + 1 / 2;
  else
    v = 1 + 1 / g(x - 1);
  endif
end
g(0)