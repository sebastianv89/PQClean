#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include "params.h"


#include "fips202.h"
#include "fips202x4.h"

typedef shake128ctx keccak_state;

void PQCLEAN_KYBER768_AVX2_kyber_shake128_absorb(keccak_state *s, const uint8_t *input, uint8_t x, uint8_t y);
void PQCLEAN_KYBER768_AVX2_kyber_shake128_squeezeblocks(uint8_t *output, size_t nblocks, keccak_state *s);
void PQCLEAN_KYBER768_AVX2_shake256_prf(uint8_t *output, size_t outlen, const uint8_t *key, uint8_t nonce);

#define hash_h(OUT, IN, INBYTES) sha3_256(OUT, IN, INBYTES)
#define hash_g(OUT, IN, INBYTES) sha3_512(OUT, IN, INBYTES)
#define xof_absorb(STATE, IN, X, Y) PQCLEAN_KYBER768_AVX2_kyber_shake128_absorb(STATE, IN, X, Y)
#define xof_squeezeblocks(OUT, OUTBLOCKS, STATE) shake128_squeezeblocks(OUT, OUTBLOCKS, STATE)
#define prf(OUT, OUTBYTES, KEY, NONCE) PQCLEAN_KYBER768_AVX2_shake256_prf(OUT, OUTBYTES, KEY, NONCE)
#define kdf(OUT, IN, INBYTES) shake256(OUT, KYBER_SSBYTES, IN, INBYTES)

#define XOF_BLOCKBYTES SHAKE128_RATE

typedef keccak_state xof_state;


#endif /* SYMMETRIC_H */
