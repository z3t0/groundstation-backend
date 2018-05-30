const SerialPort = require('serialport')

function get_list_of_serial_ports () {
    return new Promise ( (resolve, reject) => {
	SerialPort.list()
	    .then( (serial_ports) => {
		let data = []

		for (let i = 0; i < serial_ports.length; i++) {
		    data.push(serial_ports[i].comName)
		}

		resolve(data)
	    })
    })
		 
}


module.exports = {
    list: get_list_of_serial_ports
}
