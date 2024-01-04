%a
t= -1: 0.0001:1;
Ta = @(n) cos(n * acos(t));
plot(t, Ta(1), t, Ta(2), t, Ta(3))
%b
function lab2_2()
  x = -1 : 0.0001 : 1;
  hold on;
  for i = 1 : 7
    plot(x, Tb(i, x));
  end
  hold off;
end
   
function ret = Tb(n, x)
  if (n == 0)
    ret = 1;
    return;
  endif
  if (n == 1)
    ret = x;
    return;
  endif
  ret = 2 * x .* Tb(n - 1, x) - Tb(n - 2, x);
end







