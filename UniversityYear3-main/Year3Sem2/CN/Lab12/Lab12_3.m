x0 = 1;
x1 = 2;
f = @(x) x^3 -x^2 -1;
function[c,nr_it,val_fc] = bisection3(f,a,b,er=1e-10,nr_max_it=100)
 for n =0:nr_max_it
    c = (a*f(b) -b*f(a) )/ (f(b)- f(a));
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

[c,nr_it,val_fc] = bisection3(f,x0,x1)