import { SerialPort } from 'serialport';
import { ReadlineParser } from 'serialport';


const port = new SerialPort({
  path: 'COM11',
  baudRate: 115200
});


const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));


parser.on('data', (data) => {
  console.log('Received:', data);
});


port.on('open', () => {
  console.log('Serial port opened');
  
});

port.on('error', (err) => {
  console.log('Error:', err.message);
});

export default port;