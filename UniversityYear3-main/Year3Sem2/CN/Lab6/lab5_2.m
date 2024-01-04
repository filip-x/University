hold on
[x, y] = ginput(1);
xi = [];
yi = [];
n= 1; 
while ~isempty([x,y])  
  xi = [xi x];
  yi = [yi y];
  plot(x,y,'ok');
  text(x+0.07, y+0.03,int2str(n),'fontsize',15);
  n =n+1;
  [x,y]  = ginput(1)
end

input = linspace(0,n-2);
icsii = spline([0:(n-2)],xi,input);
igrecii = spline([0:(n-2)],yi, input);
plot(icsii, igrecii,'b');
hold off


