
#include <napi.h>
#include "cpplogger.h"


Napi::Object InitAll(Napi::Env env, Napi::Object exports) 
{
  return cpplogger::Init(env, exports);
}

NODE_API_MODULE(cpplogger, InitAll)
