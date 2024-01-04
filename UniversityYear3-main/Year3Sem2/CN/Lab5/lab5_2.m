x = [1 2];
f = [0 0.6931];
df = [1 0.5];
input =1.5;

FandDF= hering(x,input,f,df)
format short g
err = abs(log(input) - FandDF(1))
