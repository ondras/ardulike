def poisson(lambda)
  l = Math.exp(-lambda)

  p = rand
  k = 1

  while(p > l) do
    p *= rand
    k += 1
  end

  k - 1
end
