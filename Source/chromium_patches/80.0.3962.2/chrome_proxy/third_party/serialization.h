#pragma once

#include <stdlib.h>
#include <string>

namespace ChromePlus {

/*
type mapping:

int32: 1, int64: 2, char [] (UTF-8 with '\0'): 3, uint16_t [] (UCS-2 with '\0'): 4,
double: 5,

*/

struct TUnit {
  uint8_t type;
  uint32_t len;
  uint8_t* buf;

  ~TUnit() = default;

  TUnit() {
	type = 0;
    len = 0;
	buf = nullptr;
  }

  TUnit(int32_t v) {
	type = 1;
    len = 4;
    uint8_t* b = new uint8_t[len]();
    uint8_t* ptr = b;
    *ptr = (uint8_t)(v >> 24);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 16);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 8);
    ptr = ptr + 1;
    *ptr = (uint8_t)v;
    buf = b;
  }

  TUnit(int64_t v) {
    type = 2;
    len = 8;
    uint8_t* b = new uint8_t[len]();
    uint8_t* ptr = b;
    *ptr = (uint8_t)(v >> 56);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 48);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 40);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 32);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 24);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 16);
    ptr = ptr + 1;
    *ptr = (uint8_t)(v >> 8);
    ptr = ptr + 1;
    *ptr = (uint8_t)v;
    buf = b;
  }

  TUnit(double v) {
    int64_t* vv = (int64_t*)&v;
    type = 5;
    len = 8;
    uint8_t* b = new uint8_t[len]();
    uint8_t* ptr = b;
    *ptr = (uint8_t)((*vv) >> 56);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 48);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 40);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 32);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 24);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 16);
    ptr = ptr + 1;
    *ptr = (uint8_t)((*vv) >> 8);
    ptr = ptr + 1;
    *ptr = (uint8_t)(*vv);
    buf = b;
  }

  TUnit(const char* v) {
    type = 3;
    len = strlen(v) + 1;
    uint8_t* b = new uint8_t[len]();
    memcpy(b, v, len);
    buf = b;
  }

  TUnit(const wchar_t* v) {
	type = 4;
	len = (wcslen(v) + 1) * 2;
	uint8_t* b = new uint8_t[len]();
	memcpy(b, (const char*)v, len);
	buf = b;
  }

  int32_t ToInt32() {
    int32_t v = 0;
    uint8_t* ptr = buf;
    v |= ((int32_t)(*ptr)) << 24;
    ptr = ptr + 1;
    v |= ((int32_t)(*ptr)) << 16;
    ptr = ptr + 1;
    v |= ((int32_t)(*ptr)) << 8;
    ptr = ptr + 1;
    v |= (int32_t)(*ptr);
    return v;
  }

  int64_t ToInt64() {
    int64_t v = 0;
    uint8_t* ptr = buf;
    v |= ((int64_t)(*ptr)) << 56;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 48;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 40;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 32;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 24;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 16;
    ptr = ptr + 1;
    v |= ((int64_t)(*ptr)) << 8;
    ptr = ptr + 1;
    v |= (int64_t)(*ptr);
    return v;
  }

  double ToDouble() {
    double v = 0;
    int64_t* vv = (int64_t*)&v;
    uint8_t* ptr = buf;
    (*vv) |= ((int64_t)(*ptr)) << 56;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 48;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 40;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 32;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 24;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 16;
    ptr = ptr + 1;
    (*vv) |= ((int64_t)(*ptr)) << 8;
    ptr = ptr + 1;
    (*vv) |= (int64_t)(*ptr);
    return v;
  }

  void ToCharArray(char** v) {
    *v = new char[len]();
    memcpy(*v, buf, len);
  }

  void ToWCharArray(wchar_t** v) {
	*v = new wchar_t[len / 2];
	memcpy((char*)*v, buf, len);
  }

  void ToBuffer(int* sz, uint8_t** b) {
    *b = new uint8_t[len + 4]();
    uint32_t head = (type << 24) + len;
    uint8_t* ptr = *b;
    *ptr = (uint8_t)(head >> 24);
    ptr = ptr + 1;
    *ptr = (uint8_t)(head >> 16);
    ptr = ptr + 1;
    *ptr = (uint8_t)(head >> 8);
    ptr = ptr + 1;
    *ptr = (uint8_t)head;
    ptr = ptr + 1;
    memcpy(ptr, buf, len);
    *sz = len + 4;
  }

  std::string ToString() {
	int sz;
	uint8_t* b;
	ToBuffer(&sz, &b);
	std::string str = std::string((char*)b, sz);
	free(b);
	return str;
  }

  static void NewFromBuffer(const char* b, TUnit** u) {
    NewFromBuffer((const uint8_t*)b, u);
  }

  static void NewFromBuffer(const uint8_t* b, TUnit** u) {
    *u = new TUnit();
    uint8_t type = 0;
    uint32_t len = 0;
    uint8_t* ptr = const_cast<uint8_t*>(b);
    type += ((uint8_t)(*ptr));
    ptr = ptr + 1;
    len += ((uint32_t)(*ptr)) << 16;
    ptr = ptr + 1;
    len += ((uint32_t)(*ptr)) << 8;
    ptr = ptr + 1;
    len += ((uint32_t)(*ptr));
    ptr = ptr + 1;
    uint8_t* buf = new uint8_t[len]();
    memcpy(buf, ptr, len);
    (*u)->type = type;
    (*u)->len = len;
    (*u)->buf = buf;
  }
};

}  // namespace ChromePlus
