function B = div_dif_double(x,f,df)
  z = repelem(x,2);
  n = length(z);
  
  table = nan(n);
  table(:,1) = repelem(f,2);
  
  table(1:2:end-1,2) = df;
  table (2:2:end-2,2) = diff(f) ./ diff(x);
  
  for j=3:n
    table(1:n-j+1, j)= (table(2:n-j+2, j-1) - table(1:n-j+1, j-1)) ./ (z(j:n) - z(1:n-j+1))';
  endfor
  
endfunction




% table = dif_div_double

%z = repelem(...)
% n = length(z)
% table  = nan(n);
%table (:,1) = ....  sa luam prima coloana 
%table(1:2:n-1,2) = df (valorile derivatei) % mergem pe elemente impare ( coloana 2)
%table(....,2) =dif(...) ./ dif(...)