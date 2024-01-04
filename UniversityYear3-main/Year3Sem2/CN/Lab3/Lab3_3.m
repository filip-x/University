x = linspace(0,10,21);
fx = (1+cos(pi .* x2))./ (1+x2);

x_plot = 0:0.001:10;
fx_plot = (1+cos(pi .* x1))./ (1+x1);


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

px  = [];
for i = x_plot
  px(end+1) = bary(x,fx,i);
endfor

hold on
plot( x_plot,fx_plot,'r')
plot(x_plot,px,'b')
hold off



