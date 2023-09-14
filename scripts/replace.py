import re
from rich import print

with open('./Final copy.ino') as f:
    content = f.read()    

delays = [int(e.split('(')[1]) for e in re.findall(r'delay\(\d+', content) if e not in {500, 100}]
print(f'Delays(ms): {delays}')

distances = list(map(lambda delay: round((7 * delay) / 1000, 2), delays))
print(f'Distances(cm): {distances}')

print({k:v for (k, v) in zip(delays, distances)})