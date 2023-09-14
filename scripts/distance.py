target_distance = float(input('Target distance(in cm): '))

distance_per_sec = 7
target_time = target_distance * (1000 / distance_per_sec)

print(f'Target time(in ms) = {target_time}')