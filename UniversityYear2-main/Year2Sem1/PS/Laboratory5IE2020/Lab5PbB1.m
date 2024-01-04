clc
clear 
close all

x= [7, 7, 4, 5, 9, 9, 4, 12, 8, 1, 8, 7, 3, 13, 2, 1, 17, 7,...
   12, 5, 6, 2, 1, 13, 14, 10, 2, 4, 9, 11, 3, 5, 12, 6, 10, 7];
alpha=0.05;%significance level; 1-alpha confidence level

sigma=5;

[li,ri]=ConfIntMeanVarKnown(x,alpha,sigma);
fprintf('Cofidence Interval for the mean (standard deviation known)\n')
fprintf('(%.4f,%.4f)\n',li,ri)

[li,ri]=ConfIntMeanNotVar(x,alpha);
fprintf('Cofidence Interval for the mean (standard deviation unknown)\n')
fprintf('(%.4f,%.4f)\n',li,ri)

[li,ri]=ConfIntVar(x,alpha);
fprintf('Cofidence Interval for the variance\n')
fprintf('(%.4f,%.4f)\n',li,ri)

fprintf('Cofidence Interval for the standard deviation\n')
fprintf('(%.4f,%.4f)\n',sqrt(li),sqrt(ri))