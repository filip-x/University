axis([0 10 0 10])
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
 p = polyfit(xi,yi,2);
input = linspace(0,10);
plot(input, polyval(p,input),'b');
hold off


