x = [81 100 121];
fx = [9.00 10.00 11.00];

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
  retval =sum(common .* fx) / sum(common);
  
end
input_115 = bary(x, fx, 115)

