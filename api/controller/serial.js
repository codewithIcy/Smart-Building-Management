import { SerialPort } from 'serialport';
import { ReadlineParser } from 'serialport';


const port = new SerialPort({
  path: 'COM11',
  baudRate: 115200
});


const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));


parser.on('data', (data) => {
  if(data.split(":")[0]==="Ping"){
    const latency = Date.now()-(data.split(':')[1])
    console.log(data.length)
    console.log(`${Math.floor((data.length * 8)/latency)}Mbps\n`)
    console.log(`Latency: ${latency}ms`)
  }
});


port.on('open', () => {
  console.log('Serial port opened');
  
})

port.on('error', (err) => {
  console.log('Error:', err.message);
});

export default port;