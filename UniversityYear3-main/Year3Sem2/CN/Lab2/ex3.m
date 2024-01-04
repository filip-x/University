x = -1:0.0001:3

function ret = P(n, x)
  ret = 0
  for k = 0 : n
    ret += ((x - 0) .^ k) / factorial(k) * exp(0);
  endfor
end
hold on;
for k = 1 : 6
  plot(x, P(k, x));
   h= legend("show")
endfor
hold off;



