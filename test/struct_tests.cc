#include <stdlib.h>
#include "nan.h"

#ifdef _WIN32
  #define __alignof__ __alignof
#endif

using namespace node;

namespace {

typedef struct _test1 {
  int a;
  int b;
  double c;
} test1;

typedef struct _test2 {
  int a;
  double b;
  int c;
} test2;

typedef struct _test3 {
  double a;
  int b;
  int c;
} test3;

typedef struct _test4 {
  double a;
  double b;
  int c;
} test4;

typedef struct _test5 {
  int a;
  double b;
  double c;
} test5;

typedef struct _test6 {
  char a;
  short b;
  int c;
} test6;

typedef struct _test7 {
  int a;
  short b;
  char c;
} test7;

typedef struct _test8 {
  int a;
  short b;
  char c;
  char d;
} test8;

typedef struct _test9 {
  int a;
  short b;
  char c;
  char d;
  char e;
} test9;

typedef struct _test10 {
  test1 a;
  char b;
} test10;

// this one simulates the `ffi_type` struct
typedef struct _test11 {
  size_t a;
  unsigned short b;
  unsigned short c;
  struct _test11 **d;
} test11;

typedef struct _test12 {
  char *a;
  int b;
} test12;

typedef struct _test13 {
  char a;
  char b[2];
} test13;

typedef struct _test14 {
  char a;
  char b[2];
  short c;
  char d;
} test14;

typedef struct _test15 {
  test1 a;
  test1 b;
} test15;

typedef struct _test16 {
  double a[10];
  char b[3];
  int c[6];
} test16;

typedef struct _test17 {
  char a[3];
} test17;

typedef struct _test18 {
  test17 a[100];
} test18;

/* test19 example is from libdespotify
 * See: https://github.com/TooTallNate/ref-struct/issues/1
 */

#define STRING_LENGTH 256
typedef struct _test19 {
  bool has_meta_data;
  bool playable;
  bool geo_restricted;
  unsigned char track_id[33];
  unsigned char file_id[41];
  unsigned int file_bitrate;
  unsigned char album_id[33];
  unsigned char cover_id[41];
  unsigned char *key;

  char *allowed;
  char *forbidden;

  char title[STRING_LENGTH];
  struct artist* artist;
  char album[STRING_LENGTH];
  int length;
  int tracknumber;
  int year;
  float popularity;
  struct _test19 *next; /* in case of multiple tracks
                          in an album or playlist struct */
} test19;

#pragma pack(1)
typedef struct _test20 {
  char a;
  void *p;
} test20;

#pragma pack()
typedef struct _test21 {
  char a;
  void *p;
} test21;

typedef struct _test22 {
  int a;
  short b;
  char c;
  char d;
} test22;


void
Initialize(
  v8::Local<v8::Object> target,
  v8::Local<v8::Value> module,
  void* priv) {
  Nan::HandleScope scope;
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
  v8::Maybe<bool> state = v8::Nothing<bool>();
 
  state = target->Set(ctx, Nan::New<v8::String>("test1 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test1)));
  state = target->Set(ctx, Nan::New<v8::String>("test1 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test1)));
  state = target->Set(ctx, Nan::New<v8::String>("test1 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test1, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test1 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test1, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test1 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test1, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test2 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test2)));
  state = target->Set(ctx, Nan::New<v8::String>("test2 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test2)));
  state = target->Set(ctx, Nan::New<v8::String>("test2 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test2, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test2 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test2, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test2 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test2, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test3 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test3)));
  state = target->Set(ctx, Nan::New<v8::String>("test3 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test3)));
  state = target->Set(ctx, Nan::New<v8::String>("test3 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test3, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test3 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test3, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test3 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test3, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test4 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test4)));
  state = target->Set(ctx, Nan::New<v8::String>("test4 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test4)));
  state = target->Set(ctx, Nan::New<v8::String>("test4 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test4, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test4 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test4, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test4 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test4, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test5 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test5)));
  state = target->Set(ctx, Nan::New<v8::String>("test5 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test5)));
  state = target->Set(ctx, Nan::New<v8::String>("test5 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test5, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test5 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test5, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test5 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test5, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test6 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test6)));
  state = target->Set(ctx, Nan::New<v8::String>("test6 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test6)));
  state = target->Set(ctx, Nan::New<v8::String>("test6 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test6, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test6 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test6, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test6 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test6, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test7 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test7)));
  state = target->Set(ctx, Nan::New<v8::String>("test7 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test7)));
  state = target->Set(ctx, Nan::New<v8::String>("test7 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test7, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test7 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test7, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test7 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test7, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test8 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test8)));
  state = target->Set(ctx, Nan::New<v8::String>("test8 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test8)));
  state = target->Set(ctx, Nan::New<v8::String>("test8 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test8, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test8 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test8, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test8 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test8, c)));
  state = target->Set(ctx, Nan::New<v8::String>("test8 offsetof d").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test8, d)));

  state = target->Set(ctx, Nan::New<v8::String>("test9 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test9)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test9)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test9, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test9, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test9, c)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 offsetof d").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test9, d)));
  state = target->Set(ctx, Nan::New<v8::String>("test9 offsetof e").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test9, e)));

  state = target->Set(ctx, Nan::New<v8::String>("test10 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test10)));
  state = target->Set(ctx, Nan::New<v8::String>("test10 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test10)));
  state = target->Set(ctx, Nan::New<v8::String>("test10 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test10, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test10 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test10, b)));

  state = target->Set(ctx, Nan::New<v8::String>("test11 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test11)));
  state = target->Set(ctx, Nan::New<v8::String>("test11 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test11)));
  state = target->Set(ctx, Nan::New<v8::String>("test11 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test11, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test11 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test11, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test11 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test11, c)));
  state = target->Set(ctx, Nan::New<v8::String>("test11 offsetof d").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test11, d)));

  state = target->Set(ctx, Nan::New<v8::String>("test12 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test12)));
  state = target->Set(ctx, Nan::New<v8::String>("test12 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test12)));
  state = target->Set(ctx, Nan::New<v8::String>("test12 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test12, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test12 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test12, b)));

  state = target->Set(ctx, Nan::New<v8::String>("test13 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test13)));
  state = target->Set(ctx, Nan::New<v8::String>("test13 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test13)));
  state = target->Set(ctx, Nan::New<v8::String>("test13 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test13, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test13 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test13, b)));

  state = target->Set(ctx, Nan::New<v8::String>("test14 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test14)));
  state = target->Set(ctx, Nan::New<v8::String>("test14 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test14)));
  state = target->Set(ctx, Nan::New<v8::String>("test14 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test14, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test14 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test14, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test14 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test14, c)));
  state = target->Set(ctx, Nan::New<v8::String>("test14 offsetof d").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test14, d)));

  state = target->Set(ctx, Nan::New<v8::String>("test15 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test15)));
  state = target->Set(ctx, Nan::New<v8::String>("test15 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test15)));
  state = target->Set(ctx, Nan::New<v8::String>("test15 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test15, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test15 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test15, b)));

  state = target->Set(ctx, Nan::New<v8::String>("test16 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test16)));
  state = target->Set(ctx, Nan::New<v8::String>("test16 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test16)));
  state = target->Set(ctx, Nan::New<v8::String>("test16 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test16, a)));
  state = target->Set(ctx, Nan::New<v8::String>("test16 offsetof b").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test16, b)));
  state = target->Set(ctx, Nan::New<v8::String>("test16 offsetof c").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test16, c)));

  state = target->Set(ctx, Nan::New<v8::String>("test17 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test17)));
  state = target->Set(ctx, Nan::New<v8::String>("test17 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test17)));
  state = target->Set(ctx, Nan::New<v8::String>("test17 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test17, a)));

  state = target->Set(ctx, Nan::New<v8::String>("test18 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test18)));
  state = target->Set(ctx, Nan::New<v8::String>("test18 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test18)));
  state = target->Set(ctx, Nan::New<v8::String>("test18 offsetof a").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test18, a)));

  state = target->Set(ctx, Nan::New<v8::String>("test19 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test19)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test19)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof has_meta_data").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, has_meta_data)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof playable").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, playable)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof geo_restricted").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, geo_restricted)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof track_id").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, track_id)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof file_id").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, file_id)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof file_bitrate").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, file_bitrate)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof album_id").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, album_id)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof cover_id").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, cover_id)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof key").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, key)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof allowed").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, allowed)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof forbidden").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, forbidden)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof title").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, title)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof artist").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, artist)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof album").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, album)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof length").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, length)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof tracknumber").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, tracknumber)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof year").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, year)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof popularity").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, popularity)));
  state = target->Set(ctx, Nan::New<v8::String>("test19 offsetof next").ToLocalChecked(), Nan::New<v8::Number>(offsetof(test19, next)));

  state = target->Set(ctx, Nan::New<v8::String>("test20 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test20)));
  state = target->Set(ctx, Nan::New<v8::String>("test20 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test20)));

  state = target->Set(ctx, Nan::New<v8::String>("test21 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test21)));
  state = target->Set(ctx, Nan::New<v8::String>("test21 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test21)));

  state = target->Set(ctx, Nan::New<v8::String>("test22 sizeof").ToLocalChecked(), Nan::New<v8::Number>(sizeof(test22)));
  state = target->Set(ctx, Nan::New<v8::String>("test22 alignof").ToLocalChecked(), Nan::New<v8::Number>(__alignof__(test22)));
 }

} // anonymous namespace

NODE_MODULE(struct_tests, Initialize);
