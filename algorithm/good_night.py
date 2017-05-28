#! usr/bin/env python
import sys
import time

def frange(start,end,step=1.0):
	if step > 0:
		while start < end:
			time.sleep(0.008)
			yield start
			start += step
	elif step < 0:
		while start > end:
			time.sleep(0.008)
			yield start
			start += step
	else:
		raise ValueError('frange() step must not be zero')

if __name__ == '__main__':
	for y in frange(1.5,-1.5,-0.1):
		for x in frange(-1.5,1.5,0.05):
			z = x*x + y*y - 1
			f = z*z*z - x*x*y*y*y
			if f <= 0:
				sys.stdout.write('*')
			else:
				sys.stdout.write(' ')
		sys.stdout.write('\n')
	time.sleep(0.008)
	print("My heart is always beating for you -- Rongrong Zhang\n")
	time.sleep(0.008)
	print("\n")				