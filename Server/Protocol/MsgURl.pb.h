// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgURl.proto

#ifndef PROTOBUF_MsgURl_2eproto__INCLUDED
#define PROTOBUF_MsgURl_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Msg {

// Internal implementation detail -- do not call these.
void LIBPROTOC_EXPORT protobuf_AddDesc_MsgURl_2eproto();
void protobuf_AssignDesc_MsgURl_2eproto();
void protobuf_ShutdownFile_MsgURl_2eproto();

class PackSURLParam;

// ===================================================================

class LIBPROTOC_EXPORT PackSURLParam : public ::google::protobuf::Message {
 public:
  PackSURLParam();
  virtual ~PackSURLParam();

  PackSURLParam(const PackSURLParam& from);

  inline PackSURLParam& operator=(const PackSURLParam& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PackSURLParam& default_instance();

  void Swap(PackSURLParam* other);

  // implements Message ----------------------------------------------

  PackSURLParam* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PackSURLParam& from);
  void MergeFrom(const PackSURLParam& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes strUrl = 1;
  inline bool has_strurl() const;
  inline void clear_strurl();
  static const int kStrUrlFieldNumber = 1;
  inline const ::std::string& strurl() const;
  inline void set_strurl(const ::std::string& value);
  inline void set_strurl(const char* value);
  inline void set_strurl(const void* value, size_t size);
  inline ::std::string* mutable_strurl();
  inline ::std::string* release_strurl();
  inline void set_allocated_strurl(::std::string* strurl);

  // required bytes strGetParams = 2;
  inline bool has_strgetparams() const;
  inline void clear_strgetparams();
  static const int kStrGetParamsFieldNumber = 2;
  inline const ::std::string& strgetparams() const;
  inline void set_strgetparams(const ::std::string& value);
  inline void set_strgetparams(const char* value);
  inline void set_strgetparams(const void* value, size_t size);
  inline ::std::string* mutable_strgetparams();
  inline ::std::string* release_strgetparams();
  inline void set_allocated_strgetparams(::std::string* strgetparams);

  // required bytes strBodyData = 3;
  inline bool has_strbodydata() const;
  inline void clear_strbodydata();
  static const int kStrBodyDataFieldNumber = 3;
  inline const ::std::string& strbodydata() const;
  inline void set_strbodydata(const ::std::string& value);
  inline void set_strbodydata(const char* value);
  inline void set_strbodydata(const void* value, size_t size);
  inline ::std::string* mutable_strbodydata();
  inline ::std::string* release_strbodydata();
  inline void set_allocated_strbodydata(::std::string* strbodydata);

  // required bytes strCookies = 4;
  inline bool has_strcookies() const;
  inline void clear_strcookies();
  static const int kStrCookiesFieldNumber = 4;
  inline const ::std::string& strcookies() const;
  inline void set_strcookies(const ::std::string& value);
  inline void set_strcookies(const char* value);
  inline void set_strcookies(const void* value, size_t size);
  inline ::std::string* mutable_strcookies();
  inline ::std::string* release_strcookies();
  inline void set_allocated_strcookies(::std::string* strcookies);

  // required double fTimeOutSec = 5;
  inline bool has_ftimeoutsec() const;
  inline void clear_ftimeoutsec();
  static const int kFTimeOutSecFieldNumber = 5;
  inline double ftimeoutsec() const;
  inline void set_ftimeoutsec(double value);

  // required bytes strRsp = 6;
  inline bool has_strrsp() const;
  inline void clear_strrsp();
  static const int kStrRspFieldNumber = 6;
  inline const ::std::string& strrsp() const;
  inline void set_strrsp(const ::std::string& value);
  inline void set_strrsp(const char* value);
  inline void set_strrsp(const void* value, size_t size);
  inline ::std::string* mutable_strrsp();
  inline ::std::string* release_strrsp();
  inline void set_allocated_strrsp(::std::string* strrsp);

  // required int64 nRet = 7;
  inline bool has_nret() const;
  inline void clear_nret();
  static const int kNRetFieldNumber = 7;
  inline ::google::protobuf::int64 nret() const;
  inline void set_nret(::google::protobuf::int64 value);

  // required int64 nReqID = 8;
  inline bool has_nreqid() const;
  inline void clear_nreqid();
  static const int kNReqIDFieldNumber = 8;
  inline ::google::protobuf::int64 nreqid() const;
  inline void set_nreqid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:Msg.PackSURLParam)
 private:
  inline void set_has_strurl();
  inline void clear_has_strurl();
  inline void set_has_strgetparams();
  inline void clear_has_strgetparams();
  inline void set_has_strbodydata();
  inline void clear_has_strbodydata();
  inline void set_has_strcookies();
  inline void clear_has_strcookies();
  inline void set_has_ftimeoutsec();
  inline void clear_has_ftimeoutsec();
  inline void set_has_strrsp();
  inline void clear_has_strrsp();
  inline void set_has_nret();
  inline void clear_has_nret();
  inline void set_has_nreqid();
  inline void clear_has_nreqid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* strurl_;
  ::std::string* strgetparams_;
  ::std::string* strbodydata_;
  ::std::string* strcookies_;
  double ftimeoutsec_;
  ::std::string* strrsp_;
  ::google::protobuf::int64 nret_;
  ::google::protobuf::int64 nreqid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void LIBPROTOC_EXPORT protobuf_AddDesc_MsgURl_2eproto();
  friend void protobuf_AssignDesc_MsgURl_2eproto();
  friend void protobuf_ShutdownFile_MsgURl_2eproto();

  void InitAsDefaultInstance();
  static PackSURLParam* default_instance_;
};
// ===================================================================


// ===================================================================

// PackSURLParam

// required bytes strUrl = 1;
inline bool PackSURLParam::has_strurl() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PackSURLParam::set_has_strurl() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PackSURLParam::clear_has_strurl() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PackSURLParam::clear_strurl() {
  if (strurl_ != &::google::protobuf::internal::kEmptyString) {
    strurl_->clear();
  }
  clear_has_strurl();
}
inline const ::std::string& PackSURLParam::strurl() const {
  return *strurl_;
}
inline void PackSURLParam::set_strurl(const ::std::string& value) {
  set_has_strurl();
  if (strurl_ == &::google::protobuf::internal::kEmptyString) {
    strurl_ = new ::std::string;
  }
  strurl_->assign(value);
}
inline void PackSURLParam::set_strurl(const char* value) {
  set_has_strurl();
  if (strurl_ == &::google::protobuf::internal::kEmptyString) {
    strurl_ = new ::std::string;
  }
  strurl_->assign(value);
}
inline void PackSURLParam::set_strurl(const void* value, size_t size) {
  set_has_strurl();
  if (strurl_ == &::google::protobuf::internal::kEmptyString) {
    strurl_ = new ::std::string;
  }
  strurl_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* PackSURLParam::mutable_strurl() {
  set_has_strurl();
  if (strurl_ == &::google::protobuf::internal::kEmptyString) {
    strurl_ = new ::std::string;
  }
  return strurl_;
}
inline ::std::string* PackSURLParam::release_strurl() {
  clear_has_strurl();
  if (strurl_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = strurl_;
    strurl_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void PackSURLParam::set_allocated_strurl(::std::string* strurl) {
  if (strurl_ != &::google::protobuf::internal::kEmptyString) {
    delete strurl_;
  }
  if (strurl) {
    set_has_strurl();
    strurl_ = strurl;
  } else {
    clear_has_strurl();
    strurl_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes strGetParams = 2;
inline bool PackSURLParam::has_strgetparams() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PackSURLParam::set_has_strgetparams() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PackSURLParam::clear_has_strgetparams() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PackSURLParam::clear_strgetparams() {
  if (strgetparams_ != &::google::protobuf::internal::kEmptyString) {
    strgetparams_->clear();
  }
  clear_has_strgetparams();
}
inline const ::std::string& PackSURLParam::strgetparams() const {
  return *strgetparams_;
}
inline void PackSURLParam::set_strgetparams(const ::std::string& value) {
  set_has_strgetparams();
  if (strgetparams_ == &::google::protobuf::internal::kEmptyString) {
    strgetparams_ = new ::std::string;
  }
  strgetparams_->assign(value);
}
inline void PackSURLParam::set_strgetparams(const char* value) {
  set_has_strgetparams();
  if (strgetparams_ == &::google::protobuf::internal::kEmptyString) {
    strgetparams_ = new ::std::string;
  }
  strgetparams_->assign(value);
}
inline void PackSURLParam::set_strgetparams(const void* value, size_t size) {
  set_has_strgetparams();
  if (strgetparams_ == &::google::protobuf::internal::kEmptyString) {
    strgetparams_ = new ::std::string;
  }
  strgetparams_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* PackSURLParam::mutable_strgetparams() {
  set_has_strgetparams();
  if (strgetparams_ == &::google::protobuf::internal::kEmptyString) {
    strgetparams_ = new ::std::string;
  }
  return strgetparams_;
}
inline ::std::string* PackSURLParam::release_strgetparams() {
  clear_has_strgetparams();
  if (strgetparams_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = strgetparams_;
    strgetparams_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void PackSURLParam::set_allocated_strgetparams(::std::string* strgetparams) {
  if (strgetparams_ != &::google::protobuf::internal::kEmptyString) {
    delete strgetparams_;
  }
  if (strgetparams) {
    set_has_strgetparams();
    strgetparams_ = strgetparams;
  } else {
    clear_has_strgetparams();
    strgetparams_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes strBodyData = 3;
inline bool PackSURLParam::has_strbodydata() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PackSURLParam::set_has_strbodydata() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PackSURLParam::clear_has_strbodydata() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PackSURLParam::clear_strbodydata() {
  if (strbodydata_ != &::google::protobuf::internal::kEmptyString) {
    strbodydata_->clear();
  }
  clear_has_strbodydata();
}
inline const ::std::string& PackSURLParam::strbodydata() const {
  return *strbodydata_;
}
inline void PackSURLParam::set_strbodydata(const ::std::string& value) {
  set_has_strbodydata();
  if (strbodydata_ == &::google::protobuf::internal::kEmptyString) {
    strbodydata_ = new ::std::string;
  }
  strbodydata_->assign(value);
}
inline void PackSURLParam::set_strbodydata(const char* value) {
  set_has_strbodydata();
  if (strbodydata_ == &::google::protobuf::internal::kEmptyString) {
    strbodydata_ = new ::std::string;
  }
  strbodydata_->assign(value);
}
inline void PackSURLParam::set_strbodydata(const void* value, size_t size) {
  set_has_strbodydata();
  if (strbodydata_ == &::google::protobuf::internal::kEmptyString) {
    strbodydata_ = new ::std::string;
  }
  strbodydata_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* PackSURLParam::mutable_strbodydata() {
  set_has_strbodydata();
  if (strbodydata_ == &::google::protobuf::internal::kEmptyString) {
    strbodydata_ = new ::std::string;
  }
  return strbodydata_;
}
inline ::std::string* PackSURLParam::release_strbodydata() {
  clear_has_strbodydata();
  if (strbodydata_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = strbodydata_;
    strbodydata_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void PackSURLParam::set_allocated_strbodydata(::std::string* strbodydata) {
  if (strbodydata_ != &::google::protobuf::internal::kEmptyString) {
    delete strbodydata_;
  }
  if (strbodydata) {
    set_has_strbodydata();
    strbodydata_ = strbodydata;
  } else {
    clear_has_strbodydata();
    strbodydata_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes strCookies = 4;
inline bool PackSURLParam::has_strcookies() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PackSURLParam::set_has_strcookies() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PackSURLParam::clear_has_strcookies() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PackSURLParam::clear_strcookies() {
  if (strcookies_ != &::google::protobuf::internal::kEmptyString) {
    strcookies_->clear();
  }
  clear_has_strcookies();
}
inline const ::std::string& PackSURLParam::strcookies() const {
  return *strcookies_;
}
inline void PackSURLParam::set_strcookies(const ::std::string& value) {
  set_has_strcookies();
  if (strcookies_ == &::google::protobuf::internal::kEmptyString) {
    strcookies_ = new ::std::string;
  }
  strcookies_->assign(value);
}
inline void PackSURLParam::set_strcookies(const char* value) {
  set_has_strcookies();
  if (strcookies_ == &::google::protobuf::internal::kEmptyString) {
    strcookies_ = new ::std::string;
  }
  strcookies_->assign(value);
}
inline void PackSURLParam::set_strcookies(const void* value, size_t size) {
  set_has_strcookies();
  if (strcookies_ == &::google::protobuf::internal::kEmptyString) {
    strcookies_ = new ::std::string;
  }
  strcookies_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* PackSURLParam::mutable_strcookies() {
  set_has_strcookies();
  if (strcookies_ == &::google::protobuf::internal::kEmptyString) {
    strcookies_ = new ::std::string;
  }
  return strcookies_;
}
inline ::std::string* PackSURLParam::release_strcookies() {
  clear_has_strcookies();
  if (strcookies_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = strcookies_;
    strcookies_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void PackSURLParam::set_allocated_strcookies(::std::string* strcookies) {
  if (strcookies_ != &::google::protobuf::internal::kEmptyString) {
    delete strcookies_;
  }
  if (strcookies) {
    set_has_strcookies();
    strcookies_ = strcookies;
  } else {
    clear_has_strcookies();
    strcookies_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required double fTimeOutSec = 5;
inline bool PackSURLParam::has_ftimeoutsec() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PackSURLParam::set_has_ftimeoutsec() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PackSURLParam::clear_has_ftimeoutsec() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PackSURLParam::clear_ftimeoutsec() {
  ftimeoutsec_ = 0;
  clear_has_ftimeoutsec();
}
inline double PackSURLParam::ftimeoutsec() const {
  return ftimeoutsec_;
}
inline void PackSURLParam::set_ftimeoutsec(double value) {
  set_has_ftimeoutsec();
  ftimeoutsec_ = value;
}

// required bytes strRsp = 6;
inline bool PackSURLParam::has_strrsp() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PackSURLParam::set_has_strrsp() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PackSURLParam::clear_has_strrsp() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PackSURLParam::clear_strrsp() {
  if (strrsp_ != &::google::protobuf::internal::kEmptyString) {
    strrsp_->clear();
  }
  clear_has_strrsp();
}
inline const ::std::string& PackSURLParam::strrsp() const {
  return *strrsp_;
}
inline void PackSURLParam::set_strrsp(const ::std::string& value) {
  set_has_strrsp();
  if (strrsp_ == &::google::protobuf::internal::kEmptyString) {
    strrsp_ = new ::std::string;
  }
  strrsp_->assign(value);
}
inline void PackSURLParam::set_strrsp(const char* value) {
  set_has_strrsp();
  if (strrsp_ == &::google::protobuf::internal::kEmptyString) {
    strrsp_ = new ::std::string;
  }
  strrsp_->assign(value);
}
inline void PackSURLParam::set_strrsp(const void* value, size_t size) {
  set_has_strrsp();
  if (strrsp_ == &::google::protobuf::internal::kEmptyString) {
    strrsp_ = new ::std::string;
  }
  strrsp_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* PackSURLParam::mutable_strrsp() {
  set_has_strrsp();
  if (strrsp_ == &::google::protobuf::internal::kEmptyString) {
    strrsp_ = new ::std::string;
  }
  return strrsp_;
}
inline ::std::string* PackSURLParam::release_strrsp() {
  clear_has_strrsp();
  if (strrsp_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = strrsp_;
    strrsp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void PackSURLParam::set_allocated_strrsp(::std::string* strrsp) {
  if (strrsp_ != &::google::protobuf::internal::kEmptyString) {
    delete strrsp_;
  }
  if (strrsp) {
    set_has_strrsp();
    strrsp_ = strrsp;
  } else {
    clear_has_strrsp();
    strrsp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int64 nRet = 7;
inline bool PackSURLParam::has_nret() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PackSURLParam::set_has_nret() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PackSURLParam::clear_has_nret() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PackSURLParam::clear_nret() {
  nret_ = GOOGLE_LONGLONG(0);
  clear_has_nret();
}
inline ::google::protobuf::int64 PackSURLParam::nret() const {
  return nret_;
}
inline void PackSURLParam::set_nret(::google::protobuf::int64 value) {
  set_has_nret();
  nret_ = value;
}

// required int64 nReqID = 8;
inline bool PackSURLParam::has_nreqid() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void PackSURLParam::set_has_nreqid() {
  _has_bits_[0] |= 0x00000080u;
}
inline void PackSURLParam::clear_has_nreqid() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void PackSURLParam::clear_nreqid() {
  nreqid_ = GOOGLE_LONGLONG(0);
  clear_has_nreqid();
}
inline ::google::protobuf::int64 PackSURLParam::nreqid() const {
  return nreqid_;
}
inline void PackSURLParam::set_nreqid(::google::protobuf::int64 value) {
  set_has_nreqid();
  nreqid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Msg

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MsgURl_2eproto__INCLUDED
