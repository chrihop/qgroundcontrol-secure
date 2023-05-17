#ifndef ENCRYPTIONCHACHA20_H
#define ENCRYPTIONCHACHA20_H

#if __cplusplus
extern "C" {
#endif

void stream_cipher_encode_threadsafe(unsigned char * bytes, unsigned long len);

#if __cplusplus
}
#endif

#endif // ENCRYPTIONCHACHA20_H
