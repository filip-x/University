function retVal = hering(x,input,fx,df)
  L = []; 
  z = repelem(x,2);
  n = length(z);
  matricie = div_dif_double(x,fx,df); % matricie 
  c = matricie(1,:); % first row
  listaH = [];
  listaDH = [];
  dp = 1;
  for i =1:length(input)  
    p = input(i) - z(1);
    H = c(1);
    dh = 0;
    for k =2:n
      H = H+c(k)* p;
      dh = dh+ c(k)*dp;
      dp= dp * (input(i)- z(k)) +p;
       p= p *(input(i)-z(k));
    endfor
    listaH = [listaH H];
    listaDH = [listaDH dh];
  endfor
  retVal = [listaH; listaDH];
endfunction

function table = div_dif_double(x,f,df)
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
