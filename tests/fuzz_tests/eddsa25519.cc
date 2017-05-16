/**                                                                                           //
 * Copyright (c) 2015-2017, The Kovri I2P Router Project                                      //
 *                                                                                            //
 * All rights reserved.                                                                       //
 *                                                                                            //
 * Redistribution and use in source and binary forms, with or without modification, are       //
 * permitted provided that the following conditions are met:                                  //
 *                                                                                            //
 * 1. Redistributions of source code must retain the above copyright notice, this list of     //
 *    conditions and the following disclaimer.                                                //
 *                                                                                            //
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list     //
 *    of conditions and the following disclaimer in the documentation and/or other            //
 *    materials provided with the distribution.                                               //
 *                                                                                            //
 * 3. Neither the name of the copyright holder nor the names of its contributors may be       //
 *    used to endorse or promote products derived from this software without specific         //
 *    prior written permission.                                                               //
 *                                                                                            //
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY        //
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF    //
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL     //
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,       //
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,               //
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    //
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,          //
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF    //
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.               //
 *                                                                                            //
 */

#include "tests/fuzz_tests/eddsa25519.h"

#include "core/util/exception.h"
#include "core/util/log.h"

namespace kovri
{
namespace fuzz
{
int EdDSA25519::Initialize(int*, char***)
{
  uint8_t private_key[32] = {
    0xe1, 0xec, 0xff, 0xa6, 0xcd, 0x4e, 0xc7, 0x09, 0x2f, 0x87,
    0x44, 0xaf, 0x48, 0xb3, 0x7f, 0x63, 0x71, 0x63, 0x1e, 0x01,
    0xf7, 0x20, 0xe9, 0x0a, 0xfa, 0x3c, 0x90, 0xec, 0x97, 0x4c,
    0x16, 0x27
  };

  uint8_t public_key[32] = {
    0x0f, 0x90, 0x8b, 0xaf, 0xef, 0x40, 0x79, 0xb5, 0x94, 0xb5,
    0x13, 0xf9, 0xf6, 0x02, 0x65, 0xef, 0x4d, 0x95, 0xa4, 0x84,
    0x2d, 0xc7, 0x23, 0x1b, 0x93, 0xe4, 0x2e, 0x9d, 0x45, 0x52,
    0xed, 0x62
  };
  m_Signer = new kovri::core::EDDSA25519Signer(private_key);
  m_Verifier = new kovri::core::EDDSA25519Verifier(public_key);
  return 0;
}

int EdDSA25519::Impl(const uint8_t* data, size_t size)
{
  LOG(trace) << __func__ << ": size " << size;
  try
    {
      m_Signer->Sign(data, size, m_Signature);
      if (!m_Verifier->Verify(data, size, m_Signature))
        exit(1);
    }
  catch (...)
    {
      kovri::core::Exception ex;
      ex.Dispatch(__func__);
      return 0;
    }
  return 0;
}

}  // namespace fuzz
}  // namespace kovri
