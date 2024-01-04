pkg load splines
time = [0 3 5 8 13];
distance = [0 225 383 623 993];
speed = [75 77 80 74 72];

c_pp = spline(time, [75 distance 72]);# it rsults a  picewise polinomial which we need to derivate
c_pp_der = ppder(c_pp);# we calcucate the value of the derivative 

f = ppval(c_pp, 10)# we get the val of the point "10" from the polinomial
rez = ppval(c_pp_der, 10)# same but for the              