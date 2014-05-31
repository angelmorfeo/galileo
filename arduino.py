from serial import Serial
arduino = Serial('/dev/ttyACM0', 9600)
while True:
	try:
		line = arduino.readline()
		print "Temperatura 1: ", line.split("@")[0]
		print "Temperatura 2: ", line.split("@")[1]
		print ("--------------")
	except KeyboardInterrupt:
		break
arduino.close()