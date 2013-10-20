/*  Copyright 2011 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#include <chrono>

#include "boost/filesystem/operations.hpp"

#include "maidsafe/common/log.h"
#include "maidsafe/common/test.h"
#include "maidsafe/data_store/local_store.h"

#include "maidsafe/encrypt/tests/encrypt_test_base.h"

namespace fs = boost::filesystem;

namespace maidsafe {

namespace encrypt {

namespace test {

class Benchmark : public EncryptTestBase, public testing::TestWithParam<uint32_t> {
 public:
  typedef std::chrono::time_point<std::chrono::high_resolution_clock> chrono_time_point;

  Benchmark()
      : EncryptTestBase(0),
        kTestDataSize_(1024 * 1024 * 20),
        kPieceSize_(GetParam() ? GetParam() : kTestDataSize_) {
    original_.reset(new char[kTestDataSize_]);
    decrypted_.reset(new char[kTestDataSize_]);
  }

 protected:
  void PrintResult(const chrono_time_point& start_time, const chrono_time_point& stop_time,
                   bool encrypting, bool compressible) {
    uint64_t duration =
        std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count();
    if (duration == 0)
      duration = 1;
    uint64_t rate((static_cast<uint64_t>(kTestDataSize_) * 1000000) / duration);
    std::string encrypted(encrypting ? "Self-encrypted " : "Self-decrypted ");
    std::string comp(compressible ? "compressible" : "incompressible");
    std::cout << encrypted << BytesToBinarySiUnits(kTestDataSize_) << " of " << comp << " data in "
              << BytesToBinarySiUnits(kPieceSize_) << " pieces in " << (duration / 1000)
              << " milliseconds at a speed of " << BytesToBinarySiUnits(rate) << "/s\n";
  }
  void WriteThenRead(bool compressible) {
    chrono_time_point start_time(std::chrono::high_resolution_clock::now());
    for (uint32_t i(0); i < kTestDataSize_; i += kPieceSize_)
      ASSERT_TRUE(self_encryptor_->Write(&original_[i], kPieceSize_, i));
    self_encryptor_->Flush();
    chrono_time_point stop_time(std::chrono::high_resolution_clock::now());
    PrintResult(start_time, stop_time, true, compressible);

    start_time = std::chrono::high_resolution_clock::now();
    for (uint32_t i(0); i < kTestDataSize_; i += kPieceSize_)
      ASSERT_TRUE(self_encryptor_->Read(&decrypted_[i], kPieceSize_, i));
    stop_time = std::chrono::high_resolution_clock::now();
    for (uint32_t i(0); i < kTestDataSize_; ++i)
      ASSERT_EQ(original_[i], decrypted_[i]) << "failed @ count " << i;
    PrintResult(start_time, stop_time, false, compressible);
  }
  const uint32_t kTestDataSize_, kPieceSize_;
};

TEST_P(Benchmark, FUNC_BenchmarkCompressible) {
  memset(original_.get(), 'a', kTestDataSize_);
  WriteThenRead(true);
}

TEST_P(Benchmark, FUNC_BenchmarkIncompressible) {
  memcpy(original_.get(), RandomString(kTestDataSize_).data(), kTestDataSize_);
  WriteThenRead(true);
}

INSTANTIATE_TEST_CASE_P(WriteRead, Benchmark, testing::Values(0, 4096, 65536, 1048576));

// This test is to allow confirmation that memory usage is capped at an
// acceptable level.  While the test is running, memory usage must be visually
// monitored.
TEST(MassiveFile, FUNC_MemCheck) {
  int kNumProcs(8);
  maidsafe::test::TestPath test_dir(maidsafe::test::CreateTestPath());
  fs::path store_path(*test_dir / "data_store");
  data_store::LocalStore local_store(store_path, DiskUsage(uint64_t(4294967296)));

  DataMapPtr data_map(new DataMap);
  std::unique_ptr<SelfEncryptor<data_store::LocalStore>> self_encryptor(
      new SelfEncryptor<data_store::LocalStore>(data_map, local_store, kNumProcs));

  const uint32_t kDataSize((1 << 20) + 1);
  boost::scoped_array<char> original(new char[kDataSize]);
  std::string content(RandomString(kDataSize));
  std::copy(content.data(), content.data() + kDataSize, original.get());

  // Writes ~200MB
  for (uint64_t offset(0); offset != 200 * kDataSize; offset += kDataSize)
    EXPECT_TRUE(self_encryptor->Write(original.get(), kDataSize, offset));

  LOG(kInfo) << "Resetting self encryptor.";
  self_encryptor.reset();
  // Sleep to allow chosen memory monitor to update its display.
  std::this_thread::sleep_for(std::chrono::seconds(1));

  //  LOG(kInfo) << "Resetting chunk store.";
  //  client_nfs.reset();
  //  boost::system::error_code rm_error_code, exists_error_code;
  //  EXPECT_GT(fs::remove_all(store_path, rm_error_code), 0U) << rm_error_code.message();
  // EXPECT_FALSE(fs::exists(store_path, exists_error_code)) << "Remove all failed: " <<
  // rm_error_code
  //      << (exists_error_code ? "\nExists error: " + exists_error_code.message() : "");
  //  // Sleep to allow chosen memory monitor to update its display.
  //  std::this_thread::sleep_for(std::chrono::seconds(3));
}

}  // namespace test

}  // namespace encrypt

}  // namespace maidsafe
