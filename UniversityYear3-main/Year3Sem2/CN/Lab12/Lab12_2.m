x0 = 1;%a
x1 = 2;%b
f = @(x) x^3 -x^2 -1;
function[x2,nr_it,val_fc] = bisection3(f,x0,x1,er=1e-10,nr_max_it=100)
 for n =0:nr_max_it
    x2 = (x0 * f(x1) - x1 * f(x0))/(f(x1)-f(x0));
    x0 = x1;
    x1 = x2;
    if abs(x0-x1) <er || abs(f(x2)) <er
        nr_it= n;
        val_fc= f(x2);
      return;
    endif
  endfor
endfunction

[c,nr_it,val_fc] = bisection3(f,x0,x1)