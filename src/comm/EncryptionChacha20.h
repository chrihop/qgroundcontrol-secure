#ifndef ENCRYPTIONCHACHA20_H
#define ENCRYPTIONCHACHA20_H

#include "QGCMAVLink.h"

#if __cplusplus
extern "C" {
#endif

void stream_cipher_encode_threadsafe(unsigned char * bytes, unsigned long len);

void stream_cipher_update_message(mavlink_message_t * msg);

#if __cplusplus
}
#endif

#endif // ENCRYPTIONCHACHA20_H
