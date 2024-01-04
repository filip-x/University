x = [7,7,4,5,9,9,...
    4,12,8,1,8,7,...
    3,13,2,1,17,7,...
    12,5,6,2,1,13,...
    14,10,2,4,9,11,...
    3,5,12,6,10,7]

sigma = 5;
n = size(x,2);

x_avg = mean(mean(x));
ahp =0.05;
l = x_avg-(sigma/sqrt(n))*norminv(1-ahp/2, 0, 1);
r = x_avg-(sigma/sqrt(n))*norminv(ahp/2, 0, 1);
fprintf("the confidence interval for the mean is (%.3f,%.3f)\n",l, r)


