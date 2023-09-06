import numpy as np

wheel_radius_cm = 3.03

radius = float(input('radius(cm): '))
time = float(input('time: '))

circular_distance = 2 * np.pi * radius

rpm = circular_distance / (time * wheel_radius_cm * ((2 * np.pi) / 60))

print(f'RPM = {rpm}')