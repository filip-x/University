x = -5:0.001:5;
fx = 1 ./(1+x .^2);



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

i = 0:100;
y = (i./10) -5;
fy = 1 ./ (1 + y .^ 2);
for n = 2:2:8
  ni= 0:n;
  xi =ni *10 / n - 5;
  f_xi = 1 ./ (1 + xi .^ 2);
  px = [];
  for i = y
    px(end+1) = bary(xi,f_xi,i);
  endfor
  n = n;
  err = max(abs(fy -px))
  disp("");
endfor
  
  
  


