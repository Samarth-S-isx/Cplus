def solve(a, r, str):
   size = len(str)
   largest = []
   low = 0
   for upp in range(1, size+1):
      while str[low:upp] not in str[:low]:
         low += 1
      largest.append(upp - low)

   c = [a]
   for i in range(1, size):
      if largest[i] == 0:
         c.append(c[-1] + a)
      else:
         c.append(min(c[-1] + a, c[i - largest[i]] + r))

   return c[-1]

print(solve(5, 5, 'abhihibhihi'))