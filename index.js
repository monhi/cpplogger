const cpplogger = require('./build/Release/cpplogger.node')

cpplogger.init(6,"/home/mahdi/Desktop/cpplogger/plog.log",1000000,4);

cpplogger.LOGV("Log Verbose Mode.");
cpplogger.LOGD("Log Debug Mode.");
cpplogger.LOGI("Log Info Mode.");
cpplogger.LOGW("Log Warning Mode.");
cpplogger.LOGE("Log Error Mode.");
cpplogger.LOGF("Log Fatal Mode.");

module.exports = cpplogger;
