# cpplogger
This is a Node.js package that can be used for logging purposes.
But instead of writing contents on the monitor, it also writes the contents into circular files.
As I was in need of this library to find the behaviour of my IoT projects, I developed it.
The core library is a C one based on following link:

https://github.com/SergiusTheBest/plog

But as I would like to use it for my Node.js based projects, I have to use N-API to make a JavaScript package.