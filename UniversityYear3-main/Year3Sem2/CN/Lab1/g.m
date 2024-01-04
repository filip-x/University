function v = g(x)
  if x == 0
   v = 2;
  else
    v = 1 + 1 / g(x - 1);
  endif
end
