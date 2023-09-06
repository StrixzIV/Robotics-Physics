target_angle = float(input('Target angle(in degree): '))

angle_per_sec = 45
target_time = (target_angle * (1125 / angle_per_sec)) - 300

print(f'Target time(in ms) = {target_time}')