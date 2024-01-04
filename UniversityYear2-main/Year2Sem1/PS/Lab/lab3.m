%{
p = input("P must be in  0.05 and 0.95:");

for n=1:10:100
    val = 1:n;
    b = binopdf(val,n,p);
    plot(val,b);
    pause(0.3);
end
%}
%{
n = input("n must be >=30: ");
p = input("p must be <=0.05: ");

val = 0:n;
b = binopdf(val,n,p);
p = poisspdf(val,n*p);

plot(val,b,'color','r');
hold on;
plot(val,p,'color','b');
%}

%{
%user input
m = input("Give a nr to m: ");
s = input("Give a nr to s: ");
%a
a = normcdf(0,m,s);
a_p = 1-a;
disp(a_p);
%b
%c
alfa = input("Give nr to alfa: ");
c = norminv(alfa,m,s);
disp(c);
%d
beta = input("Give nr to beta: ");
d = norminv(1-beta,m,s);
disp(d);
%}


