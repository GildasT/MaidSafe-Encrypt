﻿/*******************************************************************************
 *  Copyright 2011 maidsafe.net limited                                   *
 *                                                                             *
 *  The following source code is property of maidsafe.net limited and is not   *
 *  meant for external use.  The use of this code is governed by the license   *
 *  file LICENSE.TXT found in the root of this directory and also on           *
 *  www.maidsafe.net.                                                          *
 *                                                                             *
 *  You are not free to copy, amend or otherwise use this source code without  *
 *  the explicit written permission of the board of directors of maidsafe.net. *
 ***************************************************************************//**
 * @file  test_utils.cc
 * @brief Tests for the self-encryption helper functions.
 * @date  2011-04-05
 */

#include <array>
#include <cstdint>
#include <vector>
#include <exception>
#ifdef WIN32
#  pragma warning(push)
#  pragma warning(disable: 4308)
#endif
#include "boost/archive/text_oarchive.hpp"
#ifdef WIN32
#  pragma warning(pop)
#endif
#include "boost/archive/text_iarchive.hpp"
#include "boost/timer.hpp"
#include "maidsafe/common/test.h"
#include "cryptopp/modes.h"
#include "cryptopp/sha.h"
#include "maidsafe/common/crypto.h"
#include "maidsafe/common/utils.h"
#include "maidsafe/encrypt/config.h"
#include "maidsafe/encrypt/data_map.h"
#include "maidsafe/encrypt/self_encrypt.h"
#include "maidsafe/encrypt/log.h"
#include "maidsafe/common/memory_chunk_store.h"


namespace maidsafe {

namespace encrypt {


namespace test {
  
class SelfEncryptionTest : public testing::Test {
 public:
  SelfEncryptionTest()
      : hash_func_(std::bind(&crypto::Hash<crypto::SHA512>,
                             std::placeholders::_1)),
      chunk_store_(new MemoryChunkStore (false, hash_func_)),
      data_map_(), selfenc_(chunk_store_, data_map_),
      chunk_size_(1024*256), num_chunks_(10), extra_content_(),
      expected_content_size_(sizeof(extra_content_)),
      file_size_(sizeof(extra_content_)), pre_enc_chunk_(new byte[chunk_size_]),
      pad_(new byte[144]), xor_res_(new byte[chunk_size_]),
      prehash_(new byte[CryptoPP::SHA512::DIGESTSIZE]),
      posthashxor_(new byte[CryptoPP::SHA512::DIGESTSIZE]),
      postenc_(new byte[chunk_size_]), key_(new byte[32]),
      iv_(new byte[16]), pre_enc_file_(new char[file_size_]) {}
 ~SelfEncryptionTest() {}
 bool num_chunks(size_t num_chunks);
 bool extra_content(byte * extra_data);

 
 private:
  SelfEncryptionTest &operator=(const SelfEncryptionTest&);
  SelfEncryptionTest(const SelfEncryptionTest&);
protected:
  MemoryChunkStore::HashFunc hash_func_;
  std::shared_ptr<MemoryChunkStore> chunk_store_;
  std::shared_ptr<DataMap> data_map_;
  SE selfenc_;
  size_t chunk_size_;
  size_t num_chunks_; 
  boost::shared_array<char> extra_content_; 
  size_t expected_content_size_; 
  size_t file_size_; 
  boost::shared_array<byte> pre_enc_chunk_;
  boost::shared_array<byte>pad_;
  boost::shared_array<byte>xor_res_;
  boost::shared_array<byte>prehash_;
  boost::shared_array<byte>posthashxor_;
  boost::shared_array<byte>postenc_; 
  boost::shared_array<byte>key_;
  boost::shared_array<byte>iv_;
  boost::shared_array<char>pre_enc_file_;
};

TEST_F(SelfEncryptionTest, BEH_40Charsonly) {
  std::string content(RandomString(40));
  boost::shared_array<char>stuff(new char[40]);
  boost::shared_array<char>answer(new char[40]);
  std::copy(content.data(), content.data() + 40, stuff.get());
  
  EXPECT_TRUE(selfenc_.Write(stuff.get(), 40));
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
  EXPECT_EQ(0, selfenc_.getDataMap()->size);
  EXPECT_EQ(0, selfenc_.getDataMap()->content_size);
  EXPECT_TRUE(selfenc_.FinaliseWrite());
  EXPECT_EQ(40, selfenc_.getDataMap()->size);
  EXPECT_EQ(40, selfenc_.getDataMap()->content_size);
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
  EXPECT_EQ(*stuff.get(), *selfenc_.getDataMap()->content.c_str());
  EXPECT_TRUE(selfenc_.Read(answer.get(),40));
  EXPECT_EQ(*stuff.get(), *answer.get());
  EXPECT_TRUE(selfenc_.ReInitialise());
}

TEST_F(SelfEncryptionTest, BEH_1023Chars) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  std::string content(RandomString(1023));
  boost::shared_array<char>stuff1 (new char[1023]);
  std::copy(content.c_str(), content.c_str() + 1023, stuff1.get());
  EXPECT_TRUE(selfenc_.Write(stuff1.get(), 1023));
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
  EXPECT_EQ(0, selfenc_.getDataMap()->size);
  EXPECT_EQ(0, selfenc_.getDataMap()->content_size);
  EXPECT_TRUE(selfenc_.FinaliseWrite());
  EXPECT_EQ(1023, selfenc_.getDataMap()->size);
  EXPECT_EQ(1023, selfenc_.getDataMap()->content_size);
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
}

TEST_F(SelfEncryptionTest, BEH_1025Chars3chunks) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  std::string content(RandomString(1025));
  boost::shared_array<char>stuff1 (new char[1025]);
  std::copy(content.c_str(), content.c_str() + 1025, stuff1.get());
  EXPECT_TRUE(selfenc_.Write(stuff1.get(), 1025));
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
  EXPECT_EQ(0, selfenc_.getDataMap()->size);
  EXPECT_EQ(0, selfenc_.getDataMap()->content_size);
  EXPECT_TRUE(selfenc_.FinaliseWrite());
  EXPECT_EQ(1025, selfenc_.getDataMap()->size);
  EXPECT_EQ(1025, selfenc_.getDataMap()->content_size);
  EXPECT_EQ(0, selfenc_.getDataMap()->chunks.size());
}

TEST_F(SelfEncryptionTest, BEH_WriteAndRead) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  size_t test_data_size(1024*1024*20); 
  std::string plain_text(RandomString(test_data_size));
  boost::shared_array<char>plain_data (new char[test_data_size]);
  for (size_t i = 0; i < test_data_size ; ++i) {
    plain_data[i] =/* 'a'; //*/plain_text[i];
  }
  ++test_data_size;
  plain_data[test_data_size] = 'b';

 
  boost::posix_time::ptime time =
        boost::posix_time::microsec_clock::universal_time();
  ASSERT_TRUE(selfenc_.Write(plain_data.get(), test_data_size));
  ASSERT_TRUE(selfenc_.FinaliseWrite());
  std::uint64_t duration =
      (boost::posix_time::microsec_clock::universal_time() -
       time).total_microseconds();
  if (duration == 0)
    duration = 1;
  std::cout << "Self-encrypted " << BytesToBinarySiUnits(test_data_size)
             << " in " << (duration / 1000000.0)
             << " seconds at a speed of "
             <<  BytesToBinarySiUnits(test_data_size / (duration / 1000000.0) )
             << "/s" << std::endl;
  boost::shared_array<char>answer (new char[test_data_size]);
  time =  boost::posix_time::microsec_clock::universal_time();
  ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size, 0));
  duration = (boost::posix_time::microsec_clock::universal_time() -
              time).total_microseconds();
  if (duration == 0)
    duration = 1;
  std::cout << "Self-decrypted " << BytesToBinarySiUnits(test_data_size)
             << " in " << (duration / 1000000.0)
             << " seconds at a speed of "
             <<  BytesToBinarySiUnits(test_data_size / (duration / 1000000.0) )
             << "/s" << std::endl;

  for (size_t  i = 0; i < test_data_size ; ++i)
    ASSERT_EQ(plain_data[i], answer[i]) << "failed at count " << i;

  for (int i =0; i < 20; ++i) // may be more than one copy
    selfenc_.DeleteAChunk(0);
 
 // ASSERT_TRUE(selfenc_.Read(answer2.get(), test_data_size, 0));
//// TODO FIXME this is not guaranteed to fail as
    // delete returns true and does not always remove chunk

}

TEST_F(SelfEncryptionTest, BEH_WriteAndReadByteAtATime) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  size_t test_data_size(1024*1024*2); // less than 2 mB fails due to test
  std::string plain_text(SRandomString(test_data_size));
//   boost::shared_array<char>plain_data (new char[test_data_size]);
  char * plain_data = new char[test_data_size];
  for (size_t i = 0; i < test_data_size ; ++i) {
    plain_data[i] = plain_text[i];
  }

  for (size_t i = 0; i < test_data_size ; ++i)  {
    selfenc_.Write(&plain_data[i], 1, i);
  }

  ASSERT_TRUE(selfenc_.FinaliseWrite());
   EXPECT_EQ(test_data_size, selfenc_.getDataMap()->size);
  EXPECT_EQ(0, selfenc_.getDataMap()->content_size);
  EXPECT_EQ(8, selfenc_.getDataMap()->chunks.size());
//    EXPECT_EQ("b", selfenc_.getDataMap()->content);
   boost::scoped_array<char>answer (new char[test_data_size]);

  ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size));

//   // check chunks 1 and 2
  for (size_t  i = 0; i < 524288 ; ++i)
    ASSERT_EQ(plain_data[i], answer[i]) << "c0 or c1 failed at count " << i;
  // check all other chunks
  for (size_t  i = 524288; i < test_data_size -1 ; ++i)
    ASSERT_EQ(plain_data[i], answer[i]) << "normal chunks failed count :" << i;  

}



TEST_F(SelfEncryptionTest, BEH_WriteAndReadByteAtATimeOutOfSequenceForward) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  size_t test_data_size(1024*1024*2); // less than 2 mB fails due to test
  std::string plain_text(RandomString(test_data_size));
  boost::shared_array<char>plain_data  (new char[test_data_size]);
  for (size_t i = 0; i < test_data_size ; ++i) {
    plain_data[i] = plain_text[i];
  }
  ++test_data_size;
  plain_data[test_data_size] = 'b';

size_t length = 1;
  for (size_t i = 0; i < test_data_size ; i += 2)  {
    ASSERT_TRUE(selfenc_.Write(&plain_data.get()[i], length, i));
  }
  for (size_t i = 1; i < test_data_size ; i +=2 )  {
    ASSERT_TRUE(selfenc_.Write(&plain_data.get()[i], length, i));
  }
  ASSERT_TRUE(selfenc_.FinaliseWrite());

  boost::shared_array<char>answer (new char[test_data_size]);
  
  ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size, 0));

  for (size_t  i = 0; i < test_data_size ; ++i)
    ASSERT_EQ(plain_data[i], answer[i]) << "failed at count " << i;
}

TEST_F(SelfEncryptionTest, FUNC_WriteOnceRead20) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  size_t test_data_size(1024*1024);
  std::string plain_text(RandomString(test_data_size));
  boost::shared_array<char>plain_data (new char[test_data_size]);
  for (size_t i = 0; i < test_data_size ; ++i) {
    plain_data[i] =/* 'a'; //*/plain_text[i];
  }
  ++test_data_size;
  plain_data[test_data_size] = 'b';
  
  ASSERT_TRUE(selfenc_.Write(plain_data.get(), test_data_size));
  ASSERT_TRUE(selfenc_.FinaliseWrite());
  // check it works at least once
  boost::shared_array<char>answer (new char[test_data_size]);
  ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size, 0));

  for (int j = 0; j < 20; ++j) {
    boost::shared_array<char>answer (new char[test_data_size]);
    ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size, 0))
    << "failed at read attempt " << j;
    for (size_t  i = 0; i < test_data_size ; ++i)
      ASSERT_EQ(plain_data[i], answer[i]) << "failed at count " << i;
  }
}

/*
TEST_F(SelfEncryptionTest, BEH_WriteRandomlyAllDirections) {
  EXPECT_TRUE(selfenc_.ReInitialise());
  size_t test_data_size(1024*1024);
  std::string plain_text(RandomString(test_data_size));
  boost::shared_array<char>plain_data (new char[test_data_size]);
  for (size_t i = 0; i < test_data_size ; ++i) {
    plain_data[i] = plain_text[i];
  }
  ++test_data_size;
  plain_data[test_data_size] = 'b';
// #pragma omp parallel for
  for (size_t i = 0; i < test_data_size; ++i) {
    EXPECT_TRUE(selfenc_.Write(&plain_data[i], 1, i));
  }
std::cout << " write finished "   <<std::endl;
  ASSERT_TRUE(selfenc_.FinaliseWrite());
  std::cout << " finalise write finished"   <<std::endl;
  // check it works at least once
  boost::shared_array<char>answer (new char[test_data_size]);
  ASSERT_TRUE(selfenc_.Read(answer.get(), test_data_size, 0));
  for (size_t  i = 0; i < test_data_size ; ++i)
    ASSERT_EQ(plain_data[i], answer[i]) << "failed at count " << i;
}*/


TEST_F(SelfEncryptionTest, BEH_manual_check_write) {
  MemoryChunkStore::HashFunc hash_func = std::bind(&crypto::Hash<crypto::SHA512>,
                                                   std::placeholders::_1);
  std::shared_ptr<MemoryChunkStore>
       chunk_store(new MemoryChunkStore (false, hash_func));
  std::shared_ptr<DataMap> data_map; // NULL
  SE selfenc(chunk_store, data_map);
  size_t chunk_size(1024*256); // system default
  size_t num_chunks(10);
  boost::shared_array<char>extra_content(new char[5]{'1','2','3','4','5'});
  size_t expected_content_size(sizeof(extra_content));
  size_t file_size(chunk_size*num_chunks + expected_content_size);
  boost::shared_array<byte> pre_enc_chunk(new byte[chunk_size]);
  boost::shared_array<byte>pad(new byte[144]);
  boost::shared_array<byte>xor_res(new byte[chunk_size]);
  boost::shared_array<byte>prehash(new byte[CryptoPP::SHA512::DIGESTSIZE]);
  boost::shared_array<byte>posthashxor(new byte[CryptoPP::SHA512::DIGESTSIZE]);
  boost::shared_array<byte>postenc(new byte[chunk_size]);
  boost::shared_array<byte>key(new byte[32]);
  boost::shared_array<byte>iv(new byte[16]);
  boost::shared_array<char>pre_enc_file(new char[file_size]);

  for (size_t i = 0; i < chunk_size; ++i) {
    pre_enc_chunk[i] = 'b';
  }

  for (size_t i = 0; i < file_size; ++i) {
     pre_enc_file[i] = 'b';
  }

  EXPECT_TRUE(selfenc.ReInitialise());
  EXPECT_TRUE(selfenc.Write(pre_enc_file.get(), file_size));
  EXPECT_TRUE(selfenc.FinaliseWrite());
// Do some testing on results
  EXPECT_EQ(num_chunks,  selfenc.getDataMap()->chunks.size());
  EXPECT_EQ(expected_content_size,  selfenc.getDataMap()->content_size);
  EXPECT_EQ(file_size, selfenc.getDataMap()->size);

  CryptoPP::SHA512().CalculateDigest(prehash.get(), pre_enc_chunk.get(),
                                     chunk_size);

  for (int i = 0; i < 64; ++i) {
    pad[i] = prehash[i];
    pad[i+64] = prehash[i];
  }
  for (int i = 0; i < 16; ++i) {
    pad[i+128] = prehash[i+48];
  }
  
  std::copy(prehash.get(), prehash.get() + 32, key.get());
  std::copy(prehash.get() + 32, prehash.get() + 48, iv.get());

  CryptoPP::CFB_Mode<CryptoPP::AES>::Encryption enc(key.get(), 32, iv.get());
  enc.ProcessData(postenc.get(), pre_enc_chunk.get(), chunk_size);


  for (size_t i = 0; i < chunk_size; ++i) {
    xor_res[i] = postenc[i]^pad[i%144];
  }

  CryptoPP::SHA512().CalculateDigest(posthashxor.get(),
                                     xor_res.get(),
                                     chunk_size);
  
  for (int i = 0; i < 64; ++i) {
    
    ASSERT_EQ(prehash[i], selfenc.getDataMap()->chunks[0].pre_hash[i])
      << "failed at chunk 0 pre hash " << i;
    ASSERT_EQ(prehash[i], selfenc.getDataMap()->chunks[1].pre_hash[i])
      << "failed at chunk 1 pre hash " << i;
    ASSERT_EQ(prehash[i], selfenc.getDataMap()->chunks[2].pre_hash[i])
      << "failed at chunk 2 pre hash " << i;
      // TODO uncomment these and fix
    ASSERT_EQ(posthashxor[i], static_cast<byte>(selfenc.getDataMap()->chunks[0].hash[i]))
      << "failed at chunk 0 post hash : " << i;
    ASSERT_EQ(posthashxor[i], static_cast<byte>(selfenc.getDataMap()->chunks[1].hash[i]))
    << "failed at chunk 1 post hash : " << i;
    ASSERT_EQ(posthashxor[i], static_cast<byte>(selfenc.getDataMap()->chunks[2].hash[i]))
    << "failed at chunk 2 post hash : " << i;
  }
// TODO FIXME - this breaks when threaded writes are on.
  // check chunks' hashes - should be equal for repeated single character input
  bool match(true);
  for (size_t i = 0; i < selfenc.getDataMap()->chunks.size(); ++i) {
    for (size_t j = i; j < selfenc.getDataMap()->chunks.size(); ++j) {
      for (int k = 0; k < CryptoPP::SHA512::DIGESTSIZE ; ++k) {
        if (selfenc.getDataMap()->chunks[i].hash[k] !=
                selfenc.getDataMap()->chunks[j].hash[k])
          match = false;
      }
      EXPECT_TRUE(match);
      match = true;
    }
  }
}

}  // namespace test

}  // namespace encrypt

}  // namespace maidsafe