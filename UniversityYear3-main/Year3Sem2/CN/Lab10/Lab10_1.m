A = [10 7 8 7;7 5 6 5;8 6 10 9;7 5 9 10];
B = [32; 23;33;31];
b = [32.1; 22.9;33.1;30.9];
format short;
function x = zero_sub_diag(A,B) % ZERO SUB DIAGONALA PRINCIPALA
  n = length(B);
  x = zeros(n,1);
  for i = n:-1:1
    x(i) = (B(i) - A(i,(i+1:n))* x(i+1:n))/ A(i,i);
  endfor
 end

 function x = eliminare_gauss(A,B)
 n = length(B); 
 x = zeros(size(B));
 %lipire matricia A si B
 A = [A B];
 % facem zero-uri
 for i = 1:n-1
   [val,pos] = max(abs(A(i:n,i)));
   pos = pos+i-1;
   assert(val ~=0)
   A([i,pos],i:end) = A([pos,i],i:end);
   
   for j = i+1:n
     A(j,i:end) = A(j,i:end) - A(i,i:end)* (A(j,i)/A(i,i));
   endfor
 endfor
 
 x = zero_sub_diag(A(:,1:n),A(:,end));
endfunction

x1 = eliminare_gauss(A,B)
x2 = eliminare_gauss(A,b)

b_error = (abs(B - b))/B
x_error = (abs(x1-x2))/x1


