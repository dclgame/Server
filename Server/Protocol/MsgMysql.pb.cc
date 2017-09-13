// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MsgMysql.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MsgMysql.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Msg {

namespace {

const ::google::protobuf::Descriptor* PackMysqlParam_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PackMysqlParam_reflection_ = NULL;
const ::google::protobuf::Descriptor* PackMysqlServerIo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PackMysqlServerIo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MsgMysql_2eproto() {
  protobuf_AddDesc_MsgMysql_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MsgMysql.proto");
  GOOGLE_CHECK(file != NULL);
  PackMysqlParam_descriptor_ = file->message_type(0);
  static const int PackMysqlParam_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, strrecordname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, strkey_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, fieldveclist_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, valueveclist_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, bexit_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, nreqid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, nret_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, etype_),
  };
  PackMysqlParam_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PackMysqlParam_descriptor_,
      PackMysqlParam::default_instance_,
      PackMysqlParam_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlParam, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PackMysqlParam));
  PackMysqlServerIo_descriptor_ = file->message_type(1);
  static const int PackMysqlServerIo_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, nrconnecttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, nrconnecount_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, nport_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, strdbname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, strdnsip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, strdbuser_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, strdbpwd_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, nserverid_),
  };
  PackMysqlServerIo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PackMysqlServerIo_descriptor_,
      PackMysqlServerIo::default_instance_,
      PackMysqlServerIo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PackMysqlServerIo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PackMysqlServerIo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MsgMysql_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PackMysqlParam_descriptor_, &PackMysqlParam::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PackMysqlServerIo_descriptor_, &PackMysqlServerIo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MsgMysql_2eproto() {
  delete PackMysqlParam::default_instance_;
  delete PackMysqlParam_reflection_;
  delete PackMysqlServerIo::default_instance_;
  delete PackMysqlServerIo_reflection_;
}

void protobuf_AddDesc_MsgMysql_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016MsgMysql.proto\022\003Msg\"\237\001\n\016PackMysqlParam"
    "\022\025\n\rstrRecordName\030\001 \002(\014\022\016\n\006strKey\030\002 \002(\014\022"
    "\024\n\014fieldVecList\030\003 \003(\014\022\024\n\014valueVecList\030\004 "
    "\003(\014\022\r\n\005bExit\030\005 \002(\003\022\016\n\006nreqid\030\006 \002(\003\022\014\n\004nR"
    "et\030\007 \002(\003\022\r\n\005eType\030\010 \002(\003\"\254\001\n\021PackMysqlSer"
    "verIo\022\025\n\rnRconnectTime\030\001 \002(\003\022\024\n\014nRconneC"
    "ount\030\002 \002(\003\022\r\n\005nPort\030\003 \002(\003\022\021\n\tstrDBName\030\004"
    " \002(\014\022\020\n\010strDnsIp\030\005 \002(\014\022\021\n\tstrDBUser\030\006 \002("
    "\014\022\020\n\010strDBPwd\030\007 \002(\014\022\021\n\tnServerID\030\010 \002(\003", 358);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MsgMysql.proto", &protobuf_RegisterTypes);
  PackMysqlParam::default_instance_ = new PackMysqlParam();
  PackMysqlServerIo::default_instance_ = new PackMysqlServerIo();
  PackMysqlParam::default_instance_->InitAsDefaultInstance();
  PackMysqlServerIo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MsgMysql_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MsgMysql_2eproto {
  StaticDescriptorInitializer_MsgMysql_2eproto() {
    protobuf_AddDesc_MsgMysql_2eproto();
  }
} static_descriptor_initializer_MsgMysql_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int PackMysqlParam::kStrRecordNameFieldNumber;
const int PackMysqlParam::kStrKeyFieldNumber;
const int PackMysqlParam::kFieldVecListFieldNumber;
const int PackMysqlParam::kValueVecListFieldNumber;
const int PackMysqlParam::kBExitFieldNumber;
const int PackMysqlParam::kNreqidFieldNumber;
const int PackMysqlParam::kNRetFieldNumber;
const int PackMysqlParam::kETypeFieldNumber;
#endif  // !_MSC_VER

PackMysqlParam::PackMysqlParam()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PackMysqlParam::InitAsDefaultInstance() {
}

PackMysqlParam::PackMysqlParam(const PackMysqlParam& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PackMysqlParam::SharedCtor() {
  _cached_size_ = 0;
  strrecordname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  strkey_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  bexit_ = GOOGLE_LONGLONG(0);
  nreqid_ = GOOGLE_LONGLONG(0);
  nret_ = GOOGLE_LONGLONG(0);
  etype_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PackMysqlParam::~PackMysqlParam() {
  SharedDtor();
}

void PackMysqlParam::SharedDtor() {
  if (strrecordname_ != &::google::protobuf::internal::kEmptyString) {
    delete strrecordname_;
  }
  if (strkey_ != &::google::protobuf::internal::kEmptyString) {
    delete strkey_;
  }
  if (this != default_instance_) {
  }
}

void PackMysqlParam::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PackMysqlParam::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PackMysqlParam_descriptor_;
}

const PackMysqlParam& PackMysqlParam::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MsgMysql_2eproto();
  return *default_instance_;
}

PackMysqlParam* PackMysqlParam::default_instance_ = NULL;

PackMysqlParam* PackMysqlParam::New() const {
  return new PackMysqlParam;
}

void PackMysqlParam::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_strrecordname()) {
      if (strrecordname_ != &::google::protobuf::internal::kEmptyString) {
        strrecordname_->clear();
      }
    }
    if (has_strkey()) {
      if (strkey_ != &::google::protobuf::internal::kEmptyString) {
        strkey_->clear();
      }
    }
    bexit_ = GOOGLE_LONGLONG(0);
    nreqid_ = GOOGLE_LONGLONG(0);
    nret_ = GOOGLE_LONGLONG(0);
    etype_ = GOOGLE_LONGLONG(0);
  }
  fieldveclist_.Clear();
  valueveclist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PackMysqlParam::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes strRecordName = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strrecordname()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_strKey;
        break;
      }

      // required bytes strKey = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_strKey:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strkey()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_fieldVecList;
        break;
      }

      // repeated bytes fieldVecList = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_fieldVecList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_fieldveclist()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_fieldVecList;
        if (input->ExpectTag(34)) goto parse_valueVecList;
        break;
      }

      // repeated bytes valueVecList = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_valueVecList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_valueveclist()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_valueVecList;
        if (input->ExpectTag(40)) goto parse_bExit;
        break;
      }

      // required int64 bExit = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bExit:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &bexit_)));
          set_has_bexit();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_nreqid;
        break;
      }

      // required int64 nreqid = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_nreqid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nreqid_)));
          set_has_nreqid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_nRet;
        break;
      }

      // required int64 nRet = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_nRet:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nret_)));
          set_has_nret();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_eType;
        break;
      }

      // required int64 eType = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_eType:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &etype_)));
          set_has_etype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PackMysqlParam::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required bytes strRecordName = 1;
  if (has_strrecordname()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->strrecordname(), output);
  }

  // required bytes strKey = 2;
  if (has_strkey()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->strkey(), output);
  }

  // repeated bytes fieldVecList = 3;
  for (int i = 0; i < this->fieldveclist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->fieldveclist(i), output);
  }

  // repeated bytes valueVecList = 4;
  for (int i = 0; i < this->valueveclist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->valueveclist(i), output);
  }

  // required int64 bExit = 5;
  if (has_bexit()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(5, this->bexit(), output);
  }

  // required int64 nreqid = 6;
  if (has_nreqid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(6, this->nreqid(), output);
  }

  // required int64 nRet = 7;
  if (has_nret()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(7, this->nret(), output);
  }

  // required int64 eType = 8;
  if (has_etype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->etype(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PackMysqlParam::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes strRecordName = 1;
  if (has_strrecordname()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->strrecordname(), target);
  }

  // required bytes strKey = 2;
  if (has_strkey()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->strkey(), target);
  }

  // repeated bytes fieldVecList = 3;
  for (int i = 0; i < this->fieldveclist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(3, this->fieldveclist(i), target);
  }

  // repeated bytes valueVecList = 4;
  for (int i = 0; i < this->valueveclist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(4, this->valueveclist(i), target);
  }

  // required int64 bExit = 5;
  if (has_bexit()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(5, this->bexit(), target);
  }

  // required int64 nreqid = 6;
  if (has_nreqid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(6, this->nreqid(), target);
  }

  // required int64 nRet = 7;
  if (has_nret()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(7, this->nret(), target);
  }

  // required int64 eType = 8;
  if (has_etype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->etype(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PackMysqlParam::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes strRecordName = 1;
    if (has_strrecordname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strrecordname());
    }

    // required bytes strKey = 2;
    if (has_strkey()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strkey());
    }

    // required int64 bExit = 5;
    if (has_bexit()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->bexit());
    }

    // required int64 nreqid = 6;
    if (has_nreqid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nreqid());
    }

    // required int64 nRet = 7;
    if (has_nret()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nret());
    }

    // required int64 eType = 8;
    if (has_etype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->etype());
    }

  }
  // repeated bytes fieldVecList = 3;
  total_size += 1 * this->fieldveclist_size();
  for (int i = 0; i < this->fieldveclist_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->fieldveclist(i));
  }

  // repeated bytes valueVecList = 4;
  total_size += 1 * this->valueveclist_size();
  for (int i = 0; i < this->valueveclist_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->valueveclist(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PackMysqlParam::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PackMysqlParam* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PackMysqlParam*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PackMysqlParam::MergeFrom(const PackMysqlParam& from) {
  GOOGLE_CHECK_NE(&from, this);
  fieldveclist_.MergeFrom(from.fieldveclist_);
  valueveclist_.MergeFrom(from.valueveclist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_strrecordname()) {
      set_strrecordname(from.strrecordname());
    }
    if (from.has_strkey()) {
      set_strkey(from.strkey());
    }
    if (from.has_bexit()) {
      set_bexit(from.bexit());
    }
    if (from.has_nreqid()) {
      set_nreqid(from.nreqid());
    }
    if (from.has_nret()) {
      set_nret(from.nret());
    }
    if (from.has_etype()) {
      set_etype(from.etype());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PackMysqlParam::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PackMysqlParam::CopyFrom(const PackMysqlParam& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PackMysqlParam::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000f3) != 0x000000f3) return false;

  return true;
}

void PackMysqlParam::Swap(PackMysqlParam* other) {
  if (other != this) {
    std::swap(strrecordname_, other->strrecordname_);
    std::swap(strkey_, other->strkey_);
    fieldveclist_.Swap(&other->fieldveclist_);
    valueveclist_.Swap(&other->valueveclist_);
    std::swap(bexit_, other->bexit_);
    std::swap(nreqid_, other->nreqid_);
    std::swap(nret_, other->nret_);
    std::swap(etype_, other->etype_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PackMysqlParam::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PackMysqlParam_descriptor_;
  metadata.reflection = PackMysqlParam_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int PackMysqlServerIo::kNRconnectTimeFieldNumber;
const int PackMysqlServerIo::kNRconneCountFieldNumber;
const int PackMysqlServerIo::kNPortFieldNumber;
const int PackMysqlServerIo::kStrDBNameFieldNumber;
const int PackMysqlServerIo::kStrDnsIpFieldNumber;
const int PackMysqlServerIo::kStrDBUserFieldNumber;
const int PackMysqlServerIo::kStrDBPwdFieldNumber;
const int PackMysqlServerIo::kNServerIDFieldNumber;
#endif  // !_MSC_VER

PackMysqlServerIo::PackMysqlServerIo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void PackMysqlServerIo::InitAsDefaultInstance() {
}

PackMysqlServerIo::PackMysqlServerIo(const PackMysqlServerIo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void PackMysqlServerIo::SharedCtor() {
  _cached_size_ = 0;
  nrconnecttime_ = GOOGLE_LONGLONG(0);
  nrconnecount_ = GOOGLE_LONGLONG(0);
  nport_ = GOOGLE_LONGLONG(0);
  strdbname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  strdnsip_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  strdbuser_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  strdbpwd_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  nserverid_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PackMysqlServerIo::~PackMysqlServerIo() {
  SharedDtor();
}

void PackMysqlServerIo::SharedDtor() {
  if (strdbname_ != &::google::protobuf::internal::kEmptyString) {
    delete strdbname_;
  }
  if (strdnsip_ != &::google::protobuf::internal::kEmptyString) {
    delete strdnsip_;
  }
  if (strdbuser_ != &::google::protobuf::internal::kEmptyString) {
    delete strdbuser_;
  }
  if (strdbpwd_ != &::google::protobuf::internal::kEmptyString) {
    delete strdbpwd_;
  }
  if (this != default_instance_) {
  }
}

void PackMysqlServerIo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PackMysqlServerIo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PackMysqlServerIo_descriptor_;
}

const PackMysqlServerIo& PackMysqlServerIo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MsgMysql_2eproto();
  return *default_instance_;
}

PackMysqlServerIo* PackMysqlServerIo::default_instance_ = NULL;

PackMysqlServerIo* PackMysqlServerIo::New() const {
  return new PackMysqlServerIo;
}

void PackMysqlServerIo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    nrconnecttime_ = GOOGLE_LONGLONG(0);
    nrconnecount_ = GOOGLE_LONGLONG(0);
    nport_ = GOOGLE_LONGLONG(0);
    if (has_strdbname()) {
      if (strdbname_ != &::google::protobuf::internal::kEmptyString) {
        strdbname_->clear();
      }
    }
    if (has_strdnsip()) {
      if (strdnsip_ != &::google::protobuf::internal::kEmptyString) {
        strdnsip_->clear();
      }
    }
    if (has_strdbuser()) {
      if (strdbuser_ != &::google::protobuf::internal::kEmptyString) {
        strdbuser_->clear();
      }
    }
    if (has_strdbpwd()) {
      if (strdbpwd_ != &::google::protobuf::internal::kEmptyString) {
        strdbpwd_->clear();
      }
    }
    nserverid_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PackMysqlServerIo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 nRconnectTime = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nrconnecttime_)));
          set_has_nrconnecttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_nRconneCount;
        break;
      }

      // required int64 nRconneCount = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_nRconneCount:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nrconnecount_)));
          set_has_nrconnecount();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_nPort;
        break;
      }

      // required int64 nPort = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_nPort:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nport_)));
          set_has_nport();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_strDBName;
        break;
      }

      // required bytes strDBName = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_strDBName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strdbname()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_strDnsIp;
        break;
      }

      // required bytes strDnsIp = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_strDnsIp:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strdnsip()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_strDBUser;
        break;
      }

      // required bytes strDBUser = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_strDBUser:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strdbuser()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_strDBPwd;
        break;
      }

      // required bytes strDBPwd = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_strDBPwd:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_strdbpwd()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_nServerID;
        break;
      }

      // required int64 nServerID = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_nServerID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &nserverid_)));
          set_has_nserverid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void PackMysqlServerIo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int64 nRconnectTime = 1;
  if (has_nrconnecttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->nrconnecttime(), output);
  }

  // required int64 nRconneCount = 2;
  if (has_nrconnecount()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->nrconnecount(), output);
  }

  // required int64 nPort = 3;
  if (has_nport()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->nport(), output);
  }

  // required bytes strDBName = 4;
  if (has_strdbname()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->strdbname(), output);
  }

  // required bytes strDnsIp = 5;
  if (has_strdnsip()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      5, this->strdnsip(), output);
  }

  // required bytes strDBUser = 6;
  if (has_strdbuser()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->strdbuser(), output);
  }

  // required bytes strDBPwd = 7;
  if (has_strdbpwd()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->strdbpwd(), output);
  }

  // required int64 nServerID = 8;
  if (has_nserverid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->nserverid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* PackMysqlServerIo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int64 nRconnectTime = 1;
  if (has_nrconnecttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->nrconnecttime(), target);
  }

  // required int64 nRconneCount = 2;
  if (has_nrconnecount()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->nrconnecount(), target);
  }

  // required int64 nPort = 3;
  if (has_nport()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->nport(), target);
  }

  // required bytes strDBName = 4;
  if (has_strdbname()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->strdbname(), target);
  }

  // required bytes strDnsIp = 5;
  if (has_strdnsip()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->strdnsip(), target);
  }

  // required bytes strDBUser = 6;
  if (has_strdbuser()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->strdbuser(), target);
  }

  // required bytes strDBPwd = 7;
  if (has_strdbpwd()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->strdbpwd(), target);
  }

  // required int64 nServerID = 8;
  if (has_nserverid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->nserverid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int PackMysqlServerIo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 nRconnectTime = 1;
    if (has_nrconnecttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nrconnecttime());
    }

    // required int64 nRconneCount = 2;
    if (has_nrconnecount()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nrconnecount());
    }

    // required int64 nPort = 3;
    if (has_nport()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nport());
    }

    // required bytes strDBName = 4;
    if (has_strdbname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strdbname());
    }

    // required bytes strDnsIp = 5;
    if (has_strdnsip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strdnsip());
    }

    // required bytes strDBUser = 6;
    if (has_strdbuser()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strdbuser());
    }

    // required bytes strDBPwd = 7;
    if (has_strdbpwd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->strdbpwd());
    }

    // required int64 nServerID = 8;
    if (has_nserverid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->nserverid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PackMysqlServerIo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PackMysqlServerIo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PackMysqlServerIo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PackMysqlServerIo::MergeFrom(const PackMysqlServerIo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_nrconnecttime()) {
      set_nrconnecttime(from.nrconnecttime());
    }
    if (from.has_nrconnecount()) {
      set_nrconnecount(from.nrconnecount());
    }
    if (from.has_nport()) {
      set_nport(from.nport());
    }
    if (from.has_strdbname()) {
      set_strdbname(from.strdbname());
    }
    if (from.has_strdnsip()) {
      set_strdnsip(from.strdnsip());
    }
    if (from.has_strdbuser()) {
      set_strdbuser(from.strdbuser());
    }
    if (from.has_strdbpwd()) {
      set_strdbpwd(from.strdbpwd());
    }
    if (from.has_nserverid()) {
      set_nserverid(from.nserverid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PackMysqlServerIo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PackMysqlServerIo::CopyFrom(const PackMysqlServerIo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PackMysqlServerIo::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000ff) != 0x000000ff) return false;

  return true;
}

void PackMysqlServerIo::Swap(PackMysqlServerIo* other) {
  if (other != this) {
    std::swap(nrconnecttime_, other->nrconnecttime_);
    std::swap(nrconnecount_, other->nrconnecount_);
    std::swap(nport_, other->nport_);
    std::swap(strdbname_, other->strdbname_);
    std::swap(strdnsip_, other->strdnsip_);
    std::swap(strdbuser_, other->strdbuser_);
    std::swap(strdbpwd_, other->strdbpwd_);
    std::swap(nserverid_, other->nserverid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PackMysqlServerIo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PackMysqlServerIo_descriptor_;
  metadata.reflection = PackMysqlServerIo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Msg

// @@protoc_insertion_point(global_scope)
