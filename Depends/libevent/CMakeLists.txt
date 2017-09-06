project(libevent)

INCLUDE_DIRECTORIES(
${Depends_INCLUDE}
${Depends_INCLUDE}/libevent
${Depends_INCLUDE}/libevent/compat
${Depends_INCLUDE}/libevent/include
${Depends_INCLUDE}/libevent/WIN32-Code/nmake
)

file(GLOB_RECURSE SOURCE_FILE buffer.c buffer_iocp.c  bufferevent.c bufferevent_async.c bufferevent_filter.c
bufferevent_pair.c  bufferevent_ratelim.c bufferevent_sock.c evdns.c event.c event_iocp.c event_tagging.c
evmap.c evrpc.c evthread.c evthread_win32.c evutil.c evutil_rand.c evutil_time.c http.c listener.c log.c
signal.c strlcpy.c win32select.c)

ADD_LIBRARY(${PROJECT_NAME} ${SOURCE_FILE})




