epsion = 10 ^-4;
f = @(x) (x-2) .^2 - log(x);
a =1 ;
b =2;
function[c,nr_it,val_fc] = bisection(f,a,b,er=1e-10,nr_max_it=100)
 for n = 0:nr_max_it
    c = (a+b)/2;
    if(f(c) *f(a) <0)
      b=c;
    else
      a=c;
    endif
    if abs(a-b) <er || abs(f(c)) <er
        nr_it= n;
        val_fc= f(c);
      return;
    endif
  endfor
endfunction

[c,nr_it,val_fc] = bisection(f,a,b)
