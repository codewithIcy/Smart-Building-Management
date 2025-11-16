import serialPort from 'serialport'
import { ReadlineParser } from 'serialport';


const port = new serialPort({
  path: 'COM11',
  baudRate: 115200
});


const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));


parser.on('data', (data) => {
  console.log('Received:', data);
});


port.on('open', () => {
  console.log('Serial port opened');
  

  port.write('Temperature:25.5\n', (err) => {
    if (err) {
      return console.log('Error writing:', err.message);
    }
    console.log('Message sent');
  });
});

port.on('error', (err) => {
  console.log('Error:', err.message);
});

export default port