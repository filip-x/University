h = 0.25;
i = 0:6;
x = 1+ i * h;
f = sqrt(5*x.^2+1);
m = zeros([7,6]);
m(:,1) = f;% we put the vector( formed from f into first column in m)

for j = 2:7# we go on th columns
  for i = 1:6-j+2#
    m(i,j) = m(i+1,j-1) -m(i,j-1); # we take from the previous column the 
  endfor% diffrence between the element on the next row and the current row
endfor

m

0/0
