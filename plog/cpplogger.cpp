#include "cpplogger.h"
#include <string>
#include "Log.h"
#include "Appenders/ColorConsoleAppender.h"

int cpplogger::init(int sevirity,std::string filename, int maxFileSize, int maxFiles)
{
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.
	plog::init((plog::Severity)sevirity, filename.c_str(), maxFileSize, maxFiles).addAppender(&consoleAppender);
	//LOGI << "Program Started.";
	//LOGD << "Program Started.";
	//LOGE << "Program Started.";
	//LOGW << "Program Started.";
	//LOGV << "Program Started.";	
    return 0;
}

Napi::Number cpplogger::InitWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	if (info.Length() < 4 || !info[0].IsNumber() || !info[1].IsString() || !info[2].IsNumber() || !info[3].IsNumber())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }

    Napi::Number first  = info[0].As<Napi::Number>();
    Napi::String second = info[1].As<Napi::String>();
    Napi::Number third  = info[2].As<Napi::Number>();
    Napi::Number forth  = info[3].As<Napi::Number>();

    int returnValue = cpplogger::init(first.Int32Value(),second.Utf8Value() ,third.Int32Value(),forth.Int32Value());

    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGVerbose(std::string param)
{
	LOGV << param;
	return 0;
}

Napi::Number cpplogger::LOGVWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGVerbose(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGDebug(std::string param)
{
	LOGD << param;
	return 0;
}

Napi::Number cpplogger::LOGDWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGDebug(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGInfo(std::string param)
{
	LOGI << param;
	return 0;
}

Napi::Number cpplogger::LOGIWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGInfo(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGWarning(std::string param)
{
	LOGW << param;
	return 0;
}

Napi::Number cpplogger::LOGWWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGWarning(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGError(std::string param)
{
	LOGE << param;
	return 0;
}

Napi::Number cpplogger::LOGEWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGError(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}

int cpplogger::LOGFatal(std::string param)
{
	LOGF << param;
	return 0;
}

Napi::Number cpplogger::LOGFWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	if (info.Length() < 1 || !info[0].IsString())
	{
        Napi::TypeError::New(env, "Parameter Error").ThrowAsJavaScriptException();
    }    
    Napi::String param = info[0].As<Napi::String>();
    int returnValue = cpplogger::LOGFatal(param.Utf8Value());
    return Napi::Number::New(env, returnValue);  
}




Napi::Object cpplogger::Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("init", Napi::Function::New(env, cpplogger::InitWrapped));
  exports.Set("LOGV", Napi::Function::New(env, cpplogger::LOGVWrapped));
  exports.Set("LOGD", Napi::Function::New(env, cpplogger::LOGDWrapped));
  exports.Set("LOGI", Napi::Function::New(env, cpplogger::LOGIWrapped));  
  exports.Set("LOGW", Napi::Function::New(env, cpplogger::LOGWWrapped));
  exports.Set("LOGE", Napi::Function::New(env, cpplogger::LOGEWrapped));      
  exports.Set("LOGF", Napi::Function::New(env, cpplogger::LOGFWrapped));
  
  
  return exports;
}
