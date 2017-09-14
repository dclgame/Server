
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgDefine.proto 
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgBase.proto 
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgPreGame.proto 
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgShare.proto  
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./FleetingDefine.proto  
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgURl.proto 
protoc.exe -I=./ --cpp_out=dllexport_decl=LIBPROTOC_EXPORT:./ ./MsgMysql.proto 

pause