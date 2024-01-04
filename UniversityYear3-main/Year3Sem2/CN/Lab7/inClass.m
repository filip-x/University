time = [1 2 3 4 5 6 7]
temp = [13 15 20 14 15 13 10]

function retval = a_b(x,fx)
  m = length(x)+1;
  sum_x_fx = sum(x .* fx);
  sum_x = sum(x);
  sum_fx = sum(fx);
  sum_x_x = sum(x .* x);
  a = (m+1) .* sum_x_fx - sum_x .* sum_fx;
  a = a/((m+1) * sum_x_x - sum_x^2);
  b = sum_x_x * sum_fx - sum_x_fx * sum_x;
  b = b/((m+1) * sum_x_x - sum_x.^2);
  retval =[a,b];
  endfunction

  ab= a_b(time,temp)
  a = ab(1);
  b = ab(2);
  f =@(x) a *x +b
  E = sum((temp - f(time)).^2)
  f(8)
  % prdict the temp of th room at 8:00
  
  x = 1:0.01:7;
  hold on
  plot(time,temp,'.b')
  plot(x,f(x),'r')
  hold off
  