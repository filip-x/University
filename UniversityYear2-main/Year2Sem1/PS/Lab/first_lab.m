a = [1, 0, -2; 2, 1, 3; 0, 1, 0];
b = [2 ,1, 1; 1, 0, -1; 1, 1, 0];
c=a-b;
d=a*b;
e=a.*b
fprintf('C:\n');
fprintf('%f\n',c);
fprintf('D:\n');
fprintf('%f\n',d);
fprintf('E:\n');
fprintf('%f\n',e);

x=0:0.1:3
function first
 (x^5)/10;
endfunction
function second
  x.*sin(x);
endfunction
function third
  cos(x)
endfunction
