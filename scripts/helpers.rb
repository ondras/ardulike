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

def normal(mean, stddev)
  theta = 2 * Math::PI * rand
  rho = Math.sqrt(-2.0 * Math.log(1.0 - rand))
  scale = stddev * rho
  mean + scale * Math.cos(theta)
end
