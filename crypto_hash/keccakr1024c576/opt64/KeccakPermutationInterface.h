/*
Algorithm Name: Keccak
Authors: Guido Bertoni, Joan Daemen, Michaël Peeters and Gilles Van Assche
Date: October 27, 2008

This code, originally by Guido Bertoni, Joan Daemen, Michaël Peeters and
Gilles Van Assche as a part of the SHA-3 submission, is hereby put in the
public domain. It is given as is, without any guarantee.

For more information, feedback or questions, please refer to our website:
http://keccak.noekeon.org/
*/

#ifndef _KeccakPermutationInterface_h_
#define _KeccakPermutationInterface_h_

void KeccakInitialize();
void KeccakInitializeState(unsigned char *state);
void KeccakPermutation(unsigned char *state);
void KeccakAbsorb1024bits(unsigned char *state, const unsigned char *data);
void KeccakAbsorb512bits(unsigned char *state, const unsigned char *data);
void KeccakExtract1024bits(const unsigned char *state, unsigned char *data);
void KeccakExtract512bits(const unsigned char *state, unsigned char *data);

#endif
