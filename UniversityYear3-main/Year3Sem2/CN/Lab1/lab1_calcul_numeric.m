pkg load statistics
disp("1) ")
a = [1 2 3]
b = [4 5 6]'
c = a * b
d = b'
e = a .* b
f = a .^ 2
g = a .^ d
v = 1 : 6
w = 2 : 3 : 10
y = 10 : -1 : 0
exp(a)
exp(1)
sqrt(a)
m = max(a)
[m, k] = max(a)
h = [-2 -9 8]
k = abs(h)
mean(a)
geomean(a)
sum(a)
prod(a)

disp("2) ")
a = [[1 2 13]; [4 5 6]; [7 8 9]]
b = [[4 8 12]; [-1 0 5]; [2 3 8]]
[m, n] = size(a)
t = b'
c = a * b
d = a .* b
e = a .^ 2
size(a)
length(a)
m = mean(a) % line vector with arhithmetic mean of each column
m1 = mean(a, 2)
g = geomean(a)
s = sum(a)
s1 = sum(a, 2)
p = prod(a)
p1 = prod(a, 2)
max(a)
min(a)
diag(a)
m > 2
a > b
inv(b)
det(b)
f = abs(b)
b = [16 15 24]'
x = a \ b % solution of system ax = b
triu(a)
tril(a)
m = [2 3 5; 7 11 13; 17 19 23]
eye(8)
eye(5, 7)
zeros(5, 7)
ones(7, 9)
M = magic(4)
sum(M)
sum(M, 2)
sum(diag(M))
sum(diag(fliplr(M)))

disp("II Polynomials")
p = [2 -5 0 8]
polyval(p, 2)
p2 = [1 -5 -17 21]
roots(p2)

disp("III Graphs")
x = 0 : 0.0001 : 1;
f = exp(10 * x .* (x - 1)) .* sin(12 * pi * x);
f2 = 3 * exp(5 * (x .* x) - 1) .* cos(12 * pi * x);
%plot(x, f, 'r')
%plot(x, f2, 'b')

disp("III 2)")
t = 0 : 0.0001 : 10 * pi;
%a = input("a = ")
%b = input("b = ")
%x = (a + b) * cos(t) - b * cos((a / b + 1) * t);
%y = (a + b) * sin(t) - b * sin((a / b + 1) * t);
%plot(t, x, 'r')
%plot(t, y, 'b')

disp("III 3)")
x = 0 : 0.0001 : 2 * pi;
f1 = cos(x);
f2 = sin(x);
f3 = cos(2 * x);
%hold on;
%plot(x, f1, 'r');
%plot(x, f2, 'b');
%plot(x, f3, 'g');
%hold off;
%plot(x, f1, 'r', x, f2, 'b', x, f3, 'g')

disp("III 4)")
x = -1 : 0.0001 : 1;
y = zeros(1, length(x));
y = (-1 <= x <= 0) .* (x .^ 3 + sqrt(1 - x)) + (0 < x <= 1) .* (x .^ 3 - sqrt(1 - x)) ;
plot(x, y, 'r')

disp("III 5)")
x = 0 : 50
y = zeros(1, length(x));
y = (mod(x, 2) == 0) .* (x / 2) + (mod(x, 2) == 1) .* (3 * x + 1) ;
%plot(x, y, '*r')

disp("III 6)")
function v = g(x)
  if x == 1
    v = 1 + 1 / 2;
  else
    v = 1 + 1 / g(x - 1);
  endif
end
g(5)

disp("III 7)")
[x, y] = meshgrid(-2 : 0.001: 2, -4 : 0.001 : 4);
g = exp(-((x - 1/2) .^ 2 + (y - 1/2) .^ 2));
%mesh(x, y, g)
