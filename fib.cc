#include <nan.h>
#include <string>

double prev = 0;
double curr = 0;

double clear() {
  prev = 0;
  curr = 0;
  return curr;
}

double next() {
  if (curr == 0) {
    return ++curr;
  }
  curr += prev;
  prev = curr - prev;
  if (curr < prev) {
    clear();
  }
  return curr;
}

void Get(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New(std::to_string(next())).ToLocalChecked());
}

void Clear(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New(std::to_string(clear())).ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
               Nan::New("get").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Get)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("clear").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Clear)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(hello, Init)
