x = [1930 1940 1950 1960 1970 1980];
fx = [123203 131669 150697 179323 203212 226505];

function ret=ui(xi, x)
  u_xi = xi - x;# this is u_x
  u_xi(find(u_xi==0))=[]; # remove 0's
  ret = prod(u_xi);
end
function retval = bary(x, fx, input)
  ui_xi = [];
  for i = 1 : length(x)
    ui_xi(end + 1) = ui(x(i), x); # we append into the list on the last position ( the product from every element) 
  endfor
  dif_input = input - x;# course formula x-x_i
  dif_input(find(dif_input==0))=0.0000001;% if we have the nr in  our vector allready
  Ai = 1 ./ ui_xi; 
  common = Ai ./ dif_input;
  retval = floor(sum(common .* fx) / sum(common));
  #retval =sum(common .* fx) / sum(common); without the floor we have so many nr after, we have an error
end

function retval = bary2(x, fx, input)
  A = [];
  for i = 1 : length(x)
    A(end + 1) = 1 / (prod(x(i) - x(1: i - 1)) * prod(x(i) - x(i + 1:length(x)))); # we append into the list on the last position ( the product from every element) 
  endfor
  retval = floor(sum(A .* fx ./ (input - x)) / sum(A ./ (input - x)))
  #retval =sum(common .* fx) / sum(common); without the floor we have so many nr after, we have an error
  
end

input_1955 = bary(x, fx, 1955)
input_19552 = bary2(x, fx, 1955)
input_1995 = bary(x, fx, 1995)

