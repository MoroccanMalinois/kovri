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
 */

#ifndef TESTS_FUZZ_TESTS_CORE_ROUTER_TRANSPORTS_SSU_H_
#define TESTS_FUZZ_TESTS_CORE_ROUTER_TRANSPORTS_SSU_H_

#include "tests/fuzz_tests/target.h"
#include "core/router/transports/ssu/packet.h"
#include <memory>

namespace kovri
{
namespace fuzz
{
/**
 * @class SSUTarget
 * @brief Abstract specialization of FuzzTarget for SSU
 */
class SSUTarget : public FuzzTarget
{
 public:
  virtual int Initialize(int* argc, char*** argv);
  int Impl(const uint8_t* data, size_t size);
  virtual void SSUImpl() = 0;

 protected:
  std::unique_ptr<core::SSUPacketParser> m_Parser;
  uint8_t* m_Data;
  size_t m_Size;
  core::Exception m_Exception;
};

/**
 * @class SSUPacket
 * @brief Specialization of SSUTarget for SSUPacket
 */
class SSUPacket : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUHeader
 * @brief Specialization of SSUTarget for SSUHeader
 */
class SSUHeader : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUSessionRequest
 * @brief Specialization of SSUTarget for SSUSessionRequest
 */
class SSUSessionRequest : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUSessionCreated
 * @brief Specialization of SSUTarget for SSUSessionCreated
 */
class SSUSessionCreated : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUSessionConfirmed
 * @brief Specialization of SSUTarget for SSUSessionConfirmed
 */
class SSUSessionConfirmed : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSURelayRequest
 * @brief Specialization of SSUTarget for SSURelayRequest
 */
class SSURelayRequest : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSURelayResponse
 * @brief Specialization of SSUTarget for SSURelayResponse
 */
class SSURelayResponse : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSURelayIntro
 * @brief Specialization of SSUTarget for SSURelayIntro
 */
class SSURelayIntro : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUData
 * @brief Specialization of SSUTarget for SSUData
 */
class SSUData : public SSUTarget
{
 public:
  void SSUImpl();
};

/**
 * @class SSUPeerTest
 * @brief Specialization of SSUTarget for SSUPeerTest
 */
class SSUPeerTest : public SSUTarget
{
 public:
  void SSUImpl();
};


}  // namespace fuzz
}  // namespace kovri

#endif  // TESTS_FUZZ_TESTS_CORE_ROUTER_TRANSPORTS_SSU_H_
