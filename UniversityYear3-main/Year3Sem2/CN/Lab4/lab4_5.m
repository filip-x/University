nr1 = 1/2;
f1 = @(x) 3 .^ x;
x1 = [-2 -1 0 1 2];
f1x1 = f1(x1);

nr2 = 3;
f2 = @(x) sqrt(x);
x2 = [0 1 2 4 5];
f2x2 = f2(x2);



function ret = interpolatingPolyomials(x, i, j, mat, firstIndex, lastIndex) % first index and last index are like (P012) first is 0 and last is 2
ret =(1 / (mat(lastIndex, 1) - mat(firstIndex, 1))) * ((x - mat(firstIndex, 1)) * mat(i, j-1) - (x - mat(lastIndex, 1)) * mat(i - 1, j - 1 ));
end

function retval = neville(nr,x,fx)
  m = [x' fx'];
  for i = 2 : length(x)
    m = [m zeros(rows(m), 1)];
    for j = 3 : i + 1
      m(i, j) = interpolatingPolyomials(nr, i, j, m, i - j + 2, i);
    endfor
  end
  retval = m(rows(m), columns(m));
end

outputf1 = neville(nr1,x1,f1x1)
outputf2 = neville(nr2,x2,f2x2)
