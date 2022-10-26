# cpplogger
This is a native Node.js package that can be used for logging purposes.
But instead of just writing contents on the monitor, it also writes the contents into circular files.
As I was in need of this library to find the behaviour of my IoT projects, I developed it.
The core is a C library module based on following repository:

https://github.com/SergiusTheBest/plog

It uses node-gyp and node-addon-api packages to build.

## How to build the project
First you are supposed to install Node.js on your machine. then, to build the project run following commands:
```
npm install
npm run build
```

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

By running following command some log files will be shown on the monitor.
```
node index.js
```

## Current limitations
Just only string input is supported now. 
but I would like to add other types also.
