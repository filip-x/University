
p = input('P: ');
n =input('N:');
u = rand (n,1);
x= u;

for i = 1:length(u);
    if u(i) >=p
        x(i,1)=0;
    else
        x(i,1)=1;
    end
end

uq_val = unique(x);
uq_val_frq = histc(x,uq_val);
uq_val_prob = uq_val_frq/n;



