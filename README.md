# cpplogger
This is a native Node.js package that can be used for logging purposes.
But instead of just writing contents on the monitor, it also writes the contents into circular files.
As I was in need of this library to find the behaviour of my IoT devices, I developed it.
The core is a C library module based on the following repository:

https://github.com/SergiusTheBest/plog

It uses node-gyp and node-addon-api packages to build.

## How to build the project
First you are supposed to install Node.js on your machine. then, to build the project run the following commands inside the project folder:
```
npm install
npm run build
```
After running above commands, a `build` folder will be created which contains the compiled library inside the release folder.
 
## How to use the package
After building the package, cpplogger.node file will be in build/Release folder, which can be used as a Node.js library for logging purposes.
There is also a sample index.js file which shows how to use the package file.

```js
const cpplogger = require('./build/Release/cpplogger.node')

cpplogger.init(6,"/home/mahdi/Desktop/cpplogger/plog.log",1000000,4);

cpplogger.LOGV("Log Verbose Mode.");

cpplogger.LOGD("Log Debug Mode.");

cpplogger.LOGI("Log Info Mode.");

cpplogger.LOGW("Log Warning Mode.");

cpplogger.LOGE("Log Error Mode.");

cpplogger.LOGF("Log Fatal Mode.");
```

By running following command some log contents will be shown on the monitor.
```
node index.js
```
The same contents will be saved on the plog.log file as I set the name of log files to be plog.log in init function.

## Screenshots

In the following image you can see both the console output and plog.log file contents.
A log record will be shown on both console and log file.

 <img src="https://github.com/monhi/cpplogger/blob/main/image.png" width="405"> 


## init function settings
To start the logging process, we are supposed to run `cpplogger.init` functions.

For settings of the init function please refere to  [original repo](https://github.com/SergiusTheBest/plog).

For logging purposes, we use one of the following functions:

- cpplogger.LOGV	->	Verbose mode logging
- cpplogger.LOGD	->	Debug mode logging
- cpplogger.LOGI	->	Info mode logging
- cpplogger.LOGW	->	Warning mode logging
- cpplogger.LOGE	->	Error mode logging
- cpplogger.LOGF	->	Fatal mode logging

## Current limitations
Just only string input is supported for logging functions now. 
but I would like to add other types also.
