/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name(s) of the copyright holder(s) nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

//
// Prototype object-based interface.
//

BLIS_EXPORT_BLIS void bli_castm
     (
       const obj_t* a,
       const obj_t* b
     );

//
// Prototype BLAS-like interfaces with heterogeneous-typed operands.
//

#undef  GENTPROT2
#define GENTPROT2( ctype_a, ctype_b, cha, chb, opname ) \
\
BLIS_EXPORT_BLIS void PASTEMAC(cha,chb,opname) \
     ( \
             trans_t transa, \
             dim_t   m, \
             dim_t   n, \
       const void*   a, inc_t rs_a, inc_t cs_a, \
             void*   b, inc_t rs_b, inc_t cs_b  \
     );

INSERT_GENTPROT2_BASIC( castm )
INSERT_GENTPROT2_MIX_DP( castm )

//
// Prototype object-based _check() function.
//

void bli_castm_check
     (
       const obj_t* a,
       const obj_t* b
     );

