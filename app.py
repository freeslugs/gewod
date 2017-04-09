from flask import Flask, render_template, request
import serial

app = Flask(__name__)
app.debug = True

# SERIAL_PORT = '/dev/ttyUSB0'
# ser = serial.Serial(SERIAL_PORT)

@app.route("/")
def index():
  return render_template('index.html')

@app.route("/test/")
def test():
	return render_template('cv.html')
	

@app.route('/move/<row>/<col>/')
def move_droplet(row, col):
	if row is None or col is None:
		return

	pad_number = row * 2 + col
	command = hex(pad_number)
	# Perhaps necessary for Arduino
	# command = chr(command)
	
	ser.write(command)
	return

if __name__ == "__main__":
  app.run()
