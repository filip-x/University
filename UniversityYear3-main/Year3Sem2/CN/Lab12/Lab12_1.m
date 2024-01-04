f = @(x) (x-2) .^2 - log(x);
df = @(x) 2*(x-2) -1/x;
x0=1;
function[x2,nr_it,val_fc] = bisection3(f,x0,df,er=1e-10,nr_max_it=100)
 for n =0:nr_max_it
    x2 = x0 -f(x0)/ df(x0);
    if abs(x0-df) <er || abs(f(x2)) <er
        nr_it= n;
        val_fc= f(x2);
      return;
    endif
  endfor
endfunction

[c,nr_it,val_fc] = bisection3(f,x0,df(0))