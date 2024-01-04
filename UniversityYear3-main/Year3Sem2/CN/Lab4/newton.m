function retVal = newton(x,input,fx)
  L = [];
  for i =1:length(input)
    matricie = div_dif(x,fx); % matricie 
    c = matricie(1,:); % first row
    Xceva = input(i);
    v = cumprod(Xceva-x(1:end-1))';
    L(end+1) = c(1)+c(2:end)*v;
  endfor
  retVal = L;
endfunction

function A=div_dif(x, f)
  n=length(x);
  A=[f', nan(n, n-1)];
  for j=2:n
    A(1:n-j+1, j)= (A(2:n-j+2, j-1) - A(1:n-j+1, j-1)) ./ (x(j:n) - x(1:n-j+1))';
  endfor
endfunction