//Some definitions using NEON intrinsics.  This file
//is used for all of our NEON implementations of Simon
//and Speck with 64-bit block sizes.

#include <arm_neon.h>
#include <stdint.h>

#define u32 uint32_t
#define u64 uint64_t
#define u128 uint32x4_t

#define LCS(x,r) (((x)<<r)|((x)>>(32-r)))
#define RCS(x,r) (((x)>>r)|((x)<<(32-r)))

#define XOR veorq_u32
#define AND vandq_u32
#define ADD vaddq_u32
#define SL vshlq_n_u32
#define SR vshrq_n_u32

#define SET(a,b) vcombine_u32((uint32x2_t)(a),(uint32x2_t)(b))
#define SET1(X,c) (X=vdupq_n_u32(c))
#define SET4(X,c) (SET1(X,c), X=ADD(X,SET(0x0000000200000000LL,0x0000000300000001LL)),c+=4)

#define ST16(ip,X) vst1q_u32((u32 *)(ip),X)
#define LD16(ip) vld1q_u32((u32 *)(ip))
#define Tps vtrnq_u32
#define STORE(out,X,Y) (ST16(out,Tps(Y,X).val[0]),ST16(out+16,Tps(Y,X).val[1]))
#define XOR_STORE(in,out,X,Y) (ST16(out,XOR(Tps(Y,X).val[0],LD16(in))), ST16(out+16,XOR(Tps(Y,X).val[1],LD16(in+16))))

//The following rotation may simetimes provide better performance.
//#define ROR(X,r) (XOR(SR(X,r),SL(X,(32-(r)))))

#define ROL(X,r) vsriq_n_u32(SL(X,r),X,(32-r))
#define ROR(X,r) vsriq_n_u32(SL(X,(32-r)),X,r)
#define ROL4(X) ROL(X,4)
#define ROR4(X) ROR(X,4)
#define ROL8(X)  ROL(X,8)
#define ROR8(X) ROR(X,8)
