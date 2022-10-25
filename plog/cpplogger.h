#include <napi.h>
#include <string>
namespace cpplogger 
{  
  int init(int sevirity,std::string filename, int maxFileSize, int maxFiles);
  
  Napi::Object 		Init(Napi::Env env, Napi::Object exports);
  Napi::Number 		InitWrapped(const Napi::CallbackInfo& info);  
  
  int 				LOGVerbose(std::string param);
  Napi::Number 		LOGVWrapped(const Napi::CallbackInfo& info);
  
  int 				LOGDebug(std::string param);
  Napi::Number 		LOGDWrapped(const Napi::CallbackInfo& info);
  
  int 				LOGInfo(std::string param);
  Napi::Number 		LOGIWrapped(const Napi::CallbackInfo& info);
  
  int 		 		LOGWarning(std::string param);
  Napi::Number 		LOGWWrapped(const Napi::CallbackInfo& info);
  
  int 				LOGError(std::string param);
  Napi::Number 		LOGEWrapped(const Napi::CallbackInfo& info);

  int 				LOGFatal(std::string param);
  Napi::Number 		LOGFWrapped(const Napi::CallbackInfo& info);
  
  //void cpplogger::LOGN(std::string param);
}
